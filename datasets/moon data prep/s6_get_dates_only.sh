#!/bin/bash

#Making a CSV creator where we separate Year, Month and Day.

INPUT1=$1
INPUT2=$2

DATAFILE1="$(basename -s .csv "$INPUT1")"
cp -a "${INPUT1}" "${DATAFILE1}_og.csv"

DATAFILE2="$(basename -s .csv "$INPUT2")"
cp -a "${INPUT2}" "${DATAFILE2}_og.csv"


cut -d',' -f2-4 ${DATAFILE1}_og.csv > "$(pwd)/full-moon_only_dates.csv"
cut -d',' -f2-4 ${DATAFILE2}_og.csv > "$(pwd)/non-moon_only_dates.csv"

cut -d',' -f1 ${DATAFILE1}_og.csv > "$(pwd)/full-moon_only_temps.csv"
cut -d',' -f1 ${DATAFILE2}_og.csv > "$(pwd)/non-moon_only_temps.csv"

rm "$INPUT1"
rm "$INPUT2"

rm ${DATAFILE1}_og.csv
rm ${DATAFILE2}_og.csv