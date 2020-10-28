#!/bin/bash

## Made for checking uppsala-tm-1722-2013.dat for missing dates and NaN values.

DATAINPUT=$1

if [[ "xDATAINPUT" == "x" ]]; then
    echo "Input file in argument 1 is missing!\n"
    exit 1
fi

## Find the number of occurances of each year and make sure it's either 365 or 366
echo "Years with missing dates:"
for (( i = 1722; i <= 2013; i++ )); do
    DAYS=$( grep -c "${i}" $DATAINPUT )
    if [[ "$DAYS" != @(365|366) ]]; then
        printf "${i}: "
        grep -c "${i}" $DATAINPUT
    fi 
done

DATANAME=$(basename "$DATAINPUT")
DATALOC=$(dirname "$DATAINPUT")

## Reformating for data to look more like the other data
echo "Reformating data date structure and saving as reformat_${DATANAME}"
sed -e 's, \([^ ]*\) \([^ ]*\) \([^ ]*\),\1-\2-\3 ,' $DATAINPUT > $DATALOC/reformat_$DATANAME


NUMLINES=$( wc -l $DATAINPUT | awk -F' ' '{print $1}' )

## Our data is in the fifth column
DATA=$( cat $DATAINPUT | awk -F' ' '{print $5}' ) 

echo "Checking if all ${NUMLINES} lines of data are numbers."
for (( j = 1; j < $NUMLINES; j++ )); do
    DATALINE=$( echo $DATA | awk -F' ' '{print $'${j}'}' )

    if (( $j%100 == 0 )); then
        echo "Successfully checked ${j} out of ${NUMLINES} values."
    fi

    re='^[+-]?[0-9]?[0-9]?([.][0-9]+)?$'
    if ! [[ $DATALINE =~ $re ]]; then
        echo "error on line ${j}: Not a number" >&2; exit 1
    fi
done

echo "Successfully checked all ${NUMLINES} values."

