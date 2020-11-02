#!/bin/bash

####################################################
# This script will be called from master_script.sh #
####################################################

# Making a CSV where we separate Year, Month and Day.

INPUT=$1

DATAFILE="$(basename -s .csv "$INPUT")"
cp -a "${INPUT}" "${DATAFILE}_og.csv"

echo 'Temp,Year,Month,Day' > ${DATAFILE}_comma_sep.csv

cut -d',' -f2 ${DATAFILE}_og.csv > ${DATAFILE}_temp.csv
paste -d',' ${DATAFILE}_temp.csv <(cut -d',' -f1 ${DATAFILE}_og.csv | sed 's/-/,/g') >> ${DATAFILE}_comma_sep.csv

#cut -d',' -f1 ${DATAFILE}_comma_sep.csv > ${DATAFILE}_only_temps.csv
#cut -d',' -f2-4 ${DATAFILE}_comma_sep.csv > ${DATAFILE}_only_dates.csv

rm "${DATAFILE}_temp.csv"
rm "${DATAFILE}_og.csv"
rm "${INPUT}"