#!/bin/bash

# This script is meant to take the original Lund SMHI datafile and resturn rows with specific string in them.
# e.g. if we want temperatures at 18:00 for each day, we can find them.

# Script running information.
usage(){
	echo "----"
	echo -e "  To call this script please use"
	echo -e "   $0 '<path>' 'string you want to sort rows by' "
	echo -e "  Examples:"
    echo -e "   $0 '../data/smhi-opendata_1_52240_20200905_163726.csv'"
	echo "----"
}

# Input data path
INPUT=$1
INPUT_2=$2

# Check that the path is defined.
if [[ -z $INPUT && $# -le 0 ]]; then
   echo -e "Missing input file parameter, exiting"
   usage
   exit 1
fi

# Extracting file name.
DATAFILE="$(basename -s .csv "$INPUT")"

# Making a copy, just to have.
echo -e "\nCopying input file $INPUT to original_$DATAFILE.csv \n";
cp -a "$INPUT" "original_$DATAFILE.csv"

# Checking if it worked.
if [[ $? == 1 ]]; then
   echo -e "Error downloading or copying file, maybe wrong command syntax? exiting.... \n"
   usage
fi

# Selecting relevant columns.
grep ${INPUT_2} original_${DATAFILE}.csv > ${INPUT_2}-${DATAFILE}.csv

# replacing ';' wiht ' '.
sed 's/;/ /g' ${INPUT_2}-${DATAFILE}.csv > ${INPUT_2}_${DATAFILE}.csv 
rm ${INPUT_2}-${DATAFILE}.csv # gotta delete old file

# taking only relevant columns
cut -d' ' -f1,3 ${INPUT_2}_${DATAFILE}.csv > ${INPUT_2}_final_${DATAFILE}.csv
rm ${INPUT_2}_${DATAFILE}.csv # gotta delete old file again