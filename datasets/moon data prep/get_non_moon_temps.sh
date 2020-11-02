#!/bin/bash

INPUT1=$1
INPUT2=$2

DATAFILE1="$(basename -s .csv "${INPUT1}")"
DATAFILE2="$(basename -s .csv "${INPUT2}")"

cp -a "${INPUT1}" "${DATAFILE1}_og.csv"
cp -a "${INPUT2}" "${DATAFILE2}_og.csv"

grep -vFf ${DATAFILE2}_og.csv ${DATAFILE1}_og.csv > temps_non-moon.csv
rm ${DATAFILE1}_og.csv
rm ${DATAFILE2}_og.csv