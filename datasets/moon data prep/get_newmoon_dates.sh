#!/bin/bash

INPUT=$1

# Extracting file name.
DATAFILE="$(basename -s .csv "${INPUT}")"
cp -a "${INPUT}" "${DATAFILE}_og.csv"

while IFS= read -r line
do
    ./date_converter $line >> new_moon_final.csv
done < "${DATAFILE}_og.csv"
rm ${DATAFILE}_og.csv