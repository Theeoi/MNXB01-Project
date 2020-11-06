
dir = getwd()
dir = paste(dir, "/code/Take_me_to_the_moon/", sep = "")
dir
setwd(dir)

###########################
# Formating the Dataframe #
###########################

# Creating whether data-frame
lund_data = read.csv("final_file.csv")

lund_data$Month2 = lund_data$Month

# tell R that Month is a categorical variable, not numerical:
lund_data$Month = factor(lund_data$Month,
                       levels=c(1,2,3,4,5,6,7,8,9,10,11,12),
                       labels=c("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"))

# Creating a season frame where months are sorted by season. 
lund_data$Season = lund_data$Month
levels(lund_data$Season) = c("Winter", "Winter", "Spring", "Spring", "Spring", "Summer", "Summer", "Summer", "Autumn", "Autumn", "Autumn", "Winter")

# Creating a frame that has sorted distances to full moon by 'Full' and 'Not'.
lund_data$Full = factor(lund_data$Dist)
levels(lund_data$Full) = c("Full", "Not", "Not", "Not", "Not", "Not", "Not", "Not", "Not", "Not", "Not", "Not", "Not", "Not", "Not", "Not", "Not")


#########################################################
# Making a linear model Temps = Year + Month*Day + Dist #
#########################################################
full_model = lm(lund_data$Temp ~ lund_data$Year + lund_data$Month2*lund_data$Day + lund_data$Dist)
summary(full_model)


######################################
# Making a linear model Temps = Year #
######################################
year_model = lm(lund_data$Temp ~ lund_data$Year)
summary(year_model)

# Making a JPEG output for our plot with colours for seasons
jpeg("temps_year_season.jpeg")
with(lund_data, plot(Temp ~ Year))
with(subset(lund_data,Season=="Winter"),points(Year, Temp, col='blue'))
with(subset(lund_data,Season=="Spring"),points(Year, Temp, col='green'))
with(subset(lund_data,Season=="Summer"),points(Year, Temp, col='red'))
with(subset(lund_data,Season=="Autumn"),points(Year, Temp, col='yellow'))
abline(year_model, col="red")

# Constants needed for confidence intervals
mx = mean(lund_data$Year)
my = mean(lund_data$Temp)
beta0 = summary(year_model)$coefficients[1]
beta1 = summary(year_model)$coefficients[2] 
yhat = year_model$fit
e = year_model$residuals
s = summary(year_model)$sigma
n = nrow(lund_data)
t_quant = qt(1-0.05/2, n-2)

# Calculating the 95 % prediction interval for the expected#
ci_PY0_upr = beta0 + beta1*(1960:2015) + t_quant*s*sqrt(1+(1/n)+((1960:2015)-mx)^2 /sum(((1960:2015)-mx)^2))
ci_PY0_lwr = beta0 + beta1*(1960:2015) - t_quant*s*sqrt(1+(1/n)+((1960:2015)-mx)^2 /sum(((1960:2015)-mx)^2))

lines((1960:2015), ci_PY0_upr,lty=2,col="blue",lwd=2)
lines((1960:2015), ci_PY0_lwr,lty=2,col="blue",lwd=2)

# Making a JPEG output for our plot with colours for seasons
jpeg("temps_month_fullmoon.jpeg")
with(lund_data, plot(Temp ~ Month2))
with(subset(lund_data,Full=="Full"),points(Month2, Temp, col='red'))

write.csv(x=lund_data, file="final_file_even_better.csv")
