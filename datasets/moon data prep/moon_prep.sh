#!/bin/bash

# Replaces month names with numbers.
#

# 
usage(){
	echo "----"
	echo -e "  To call this script please use"
	echo -e "   $0 '<path>' 'string you want to sort rows by' "
	echo -e "  Examples:"
    echo -e "   $0 '../data/smhi-opendata_1_52240_20200905_163726.csv'"
	echo "----"
}

INPUT=$1 # Input data path

# Check that the path is defined.
if [[ -z $INPUT && $# -le 0 ]]; then
   echo -e "Missing input file parameter, exiting"
   usage
   exit 1
fi

# Extracting file name.
DATAFILE="$(basename -s .csv "${INPUT}")"
cp -a "${INPUT}" "${DATAFILE}_og.csv"


# Doing the replacement.
sed 's/January/01/g' ${DATAFILE}_og.csv > ${DATAFILE}_temp.csv 

sed 's/February/02/g' ${DATAFILE}_temp.csv > ${DATAFILE}_temp2.csv 
rm ${DATAFILE}_temp.csv

sed 's/March/03/g' ${DATAFILE}_temp2.csv > ${DATAFILE}_temp.csv 
rm ${DATAFILE}_temp2.csv

sed 's/April/04/g' ${DATAFILE}_temp.csv > ${DATAFILE}_temp2.csv 
rm ${DATAFILE}_temp.csv

sed 's/May/05/g' ${DATAFILE}_temp2.csv > ${DATAFILE}_temp.csv 
rm ${DATAFILE}_temp2.csv

sed 's/June/06/g' ${DATAFILE}_temp.csv > ${DATAFILE}_temp2.csv 
rm ${DATAFILE}_temp.csv

sed 's/July/07/g' ${DATAFILE}_temp2.csv > ${DATAFILE}_temp.csv 
rm ${DATAFILE}_temp2.csv

sed 's/August/08/g' ${DATAFILE}_temp.csv > ${DATAFILE}_temp2.csv 
rm ${DATAFILE}_temp.csv

sed 's/September/09/g' ${DATAFILE}_temp2.csv > ${DATAFILE}_temp.csv 
rm ${DATAFILE}_temp2.csv

sed 's/October/10/g' ${DATAFILE}_temp.csv > ${DATAFILE}_temp2.csv 
rm ${DATAFILE}_temp.csv

sed 's/November/11/g' ${DATAFILE}_temp2.csv > ${DATAFILE}_temp.csv 
rm ${DATAFILE}_temp2.csv

sed 's/December/12/g' ${DATAFILE}_temp.csv > ${DATAFILE}_temp2.csv 
rm ${DATAFILE}_temp.csv


# cutting things we don't need
cut -d',' -f2 ${DATAFILE}_temp2.csv > ${DATAFILE}_temp.csv
rm ${DATAFILE}_temp2.csv

tail -n +2 ${DATAFILE}_temp.csv > ${DATAFILE}_temp2.csv
rm ${DATAFILE}_temp.csv

cut -c 2- ${DATAFILE}_temp2.csv > ${DATAFILE}_temp.csv
rm ${DATAFILE}_temp2.csv

awk '{print $3 "-" $2 "-" $1}' ${DATAFILE}_temp.csv > ${DATAFILE}_temp2.csv # rearranging dates format from 'dd mm yyyy' to 'yyyy-mm-dd'
rm ${DATAFILE}_temp.csv


# Now we have a file with just dates in the correct format

while IFS= read -r line
do
	COUNT=$(expr length "$line")
	if [ $COUNT == 9 ]
	then 
		echo ${line:0:7}-0${line:8:9} >> ${DATAFILE}_final.csv
	else 
		echo $line >> ${DATAFILE}_final.csv
	fi
done < "${DATAFILE}_temp2.csv"
rm ${DATAFILE}_temp2.csv
rm ${DATAFILE}_og.csv