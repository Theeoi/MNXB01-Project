#!/bin/bash

INPUT1=$1
INPUT2=$2
INPUT3=$3


DATAFILE1="$(basename -s .csv "${INPUT1}")"
cp -a "${INPUT1}" "${DATAFILE1}_og.csv"

DATAFILE2="$(basename -s .csv "${INPUT2}")"
cp -a "${INPUT2}" "${DATAFILE2}_og.csv"

grep -Ff ${DATAFILE1}_og.csv ${DATAFILE2}_og.csv > temps_${INPUT3}.csv
rm ${DATAFILE1}_og.csv
rm ${DATAFILE2}_og.csv
