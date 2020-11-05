
dir = getwd()
setwd(dir)

#Creating plasme dataframe
lund_data = read.csv("final_file.csv")

## tell R that Month is a categorical variable, not numerical:
lund_data$Month <- factor(lund_data$Month,
                       levels=c(1,2,3,4,5,6,7,8,9,10,11,12),
                       labels=c("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"))

moon_temps_model = lm(lund_data$Temp ~ lund_data$Year + lund_data$Month*lund_data$Day + lund_data$Dist)
year_temps_model = lm(lund_data$Temp ~ lund_data$Year)

summary(moon_temps_model)

jpeg("moon_temps_year.jpeg")
with(lund_data, plot(lund_data$Temp ~ lund_data$Year))
abline(a=summary(year_temps_model)$coefficients[1],b=summary(year_temps_model)$coefficients[2], col="red")

jpeg("moon_temps_month.jpeg")
with(lund_data, plot(lund_data$Temp ~ lund_data$Month))

jpeg("moon_temps_dist.jpeg")
with(lund_data, plot(lund_data$Temp ~ lund_data$Dist))

#Done