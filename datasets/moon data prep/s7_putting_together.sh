#!/bin/bash

# Putting together the final CSV file with format Temp,Year,Month,Day,Dist

# First full-moon data:
paste -d',' full-moon_only_temps.csv full-moon_only_dates.csv full-moon_only_distances.csv > final_file.csv
# Now non-moon date:
paste -d',' non-moon_only_temps.csv non-moon_only_dates.csv non-moon_only_distances.csv |  tail -n +2 >> final_file.csv

# Removing some temporary files
rm full-moon_only_temps.csv full-moon_only_dates.csv full-moon_only_distances.csv 
rm non-moon_only_temps.csv non-moon_only_dates.csv non-moon_only_distances.csv