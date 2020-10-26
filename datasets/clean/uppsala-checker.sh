#!/bin/bash

## Made for checking uppsala-tm-1722-2013.dat for missing dates and NaN values.

DATAINPUT=$1

if [[ "xDATAINPUT" == "x" ]]; then
    echo "Input file in argument 1 is missing!\n"
    exit 1
fi

DATALOC=$(dirname "$DATAINPUT")

DATAFILE=$(basename "$DATAINPUT")

echo "Years with missing dates:"
for (( i = 1722; i <= 2013; i++ )) ; do
    DAYS=$( grep -c "${i}" $DATAINPUT )
    if [[ "$DAYS" != @(365|366) ]] ; then
        printf "${i}: "
        grep -c "${i}" $DATAINPUT
    fi 
done
