#!/bin/bash

####################################################
# This script will be called from master_script.sh #
####################################################

# This script is meant to take the original Lund SMHI datafile and return rows with specific string in them.
# e.g. if we want temperatures at 18:00 for each day, we can find them.

# Input data path
INPUT=$1
INPUT_2=$2

# Extracting file name.
DATAFILE="$(basename -s .csv "$INPUT")"

# Making a copy, just to have.
cp -a "$INPUT" "original_$DATAFILE.csv"

# Checking if it worked.
if [[ $? == 1 ]]; then
   echo -e "Error downloading or copying file, maybe wrong command syntax? exiting.... \n"
   usage
fi

# Selecting relevant columns.
grep ${INPUT_2} original_${DATAFILE}.csv |

# replacing ' ' wiht ',' because I like it better this way.
sed 's/ /,/g' |
tail -n +2 |

# taking only relevant columns
cut -d',' -f1,3 > hourly_${DATAFILE}.csv
rm original_${DATAFILE}.csv
