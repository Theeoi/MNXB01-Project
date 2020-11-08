#!/bin/bash

#################
# Master Script #
#################
# This is the master script, just execute it, and data will be processed.

cd "$(dirname "$0")" # setting cwd as the dirrectory where the scrip is running.

SMHI_path=$(pwd)/rawdata_Lund.csv
MOON_path=$(pwd)/full_moon.csv

##
chmod +x s1_hourly_cleaner.sh
./s1_hourly_cleaner.sh "${SMHI_path}" 18:00

##
chmod +x s2_moon_preparation.sh
./s2_moon_preparation.sh "${MOON_path}"

##
chmod +x s3_yyyy-mm-dd-temp.sh
./s3_yyyy-mm-dd-temp.sh "$(pwd)/hourly_rawdata_Lund.csv"

##
chmod +x s4_get_non_moon_temps.sh
./s4_get_non_moon_temps.sh "$(pwd)/hourly_rawdata_Lund_comma_sep.csv" "$(pwd)/full_moon_final.csv" 

##
chmod +x s5_get_temps.sh
./s5_get_temps.sh "$(pwd)/hourly_rawdata_Lund_comma_sep.csv" "$(pwd)/full_moon_final.csv" 

##
chmod +x s6_get_dates_only.sh
./s6_get_dates_only.sh "$(pwd)/temps_full-moon.csv" "$(pwd)/temps_non-moon.csv"

## Compiling
g++ -o distances "$(pwd)/cpp_code/main.cpp"
./distances

# Putting things together
chmod +x s7_putting_together.sh
./s7_putting_together.sh