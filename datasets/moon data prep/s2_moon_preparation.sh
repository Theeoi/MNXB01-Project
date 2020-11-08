#!/bin/bash

####################################################
# This script will be called from master_script.sh #
####################################################

# Replaces month names with numbers.
# And more! (just some small formating)

INPUT=$1 # Input data path

# Extracting file name.
DATAFILE="$(basename -s .csv "${INPUT}")"
cp -a "${INPUT}" "${DATAFILE}_og.csv"

STARTLINE=$(grep -n "1961:" ${DATAFILE}_og.csv | cut -f1 -d:)
STARTLINE=$(( $STARTLINE + 0 ))
tail -n +$STARTLINE ${DATAFILE}_og.csv |

# Doing the replacement.
sed 's/January/01/g' |
sed 's/February/02/g' |
sed 's/March/03/g' |
sed 's/April/04/g' |
sed 's/May/05/g' |
sed 's/June/06/g' |
sed 's/July/07/g' |
sed 's/August/08/g' |
sed 's/September/09/g' |
sed 's/October/10/g' |
sed 's/November/11/g' |
sed 's/December/12/g' |

# cutting things we don't need
cut -d',' -f2 |
cut -c 2- |
awk '{print $3 "," $2 "," $1}' > ${DATAFILE}_temp2.csv # rearranging dates format from 'dd mm yyyy' to 'yyyy-mm-dd'

# Now we have a file with just dates in the correct format
echo Year,Month,Day > ${DATAFILE}_temp.csv
while IFS= read -r line
do
	COUNT=$(expr length "$line")
	if [ $COUNT == 9 ]
	then 
		echo ${line:0:7} 0${line:8:9} >> ${DATAFILE}_temp.csv
	else 
		echo $line >> ${DATAFILE}_temp.csv
	fi
done < "${DATAFILE}_temp2.csv"
sed 's/ /,/g' ${DATAFILE}_temp.csv > ${DATAFILE}_final.csv
rm ${DATAFILE}_temp2.csv
rm ${DATAFILE}_temp.csv
rm ${DATAFILE}_og.csv