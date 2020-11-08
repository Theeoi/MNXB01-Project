#!/bin/bash

usage(){
	echo "----"
	echo -e "  To call this script please use"
	echo -e "   $0 <path>"
	echo -e "  Examples:"
        echo -e "   $0 uppsala_tm_1722-2013.dat"
	echo "----"
}

SMHIINPUT=$1

if [[ x$SMHIINPUT == x ]]; then
   echo "Missing input file parameter, exiting";
   usage
   exit 1
fi

DATAFILE=$(basename $SMHIINPUT)

cp -a $SMHIINPUT original_$DATAFILE


if [[ $? != 0 ]]; then
   echo "Error downloading or copying file, maybe wrong command syntax? exiting....";
   usage
   exit 1
fi

#currently set to clean the data for uppsala, with spaces as a seperator
#cut -d' ' -f1-4 original_$DATAFILE | 

sed 's/      /     /g' original_$DATAFILE | sed 's/     /    /g' | sed 's/    /   /g' | sed 's/   /  /g' | sed 's/  / /g' > clean_$DATAFILE

awk '{if ($6 == 1) print $1, $2, $3, $4}' clean_$DATAFILE > hotcold_uppsala.csv
#| awk '{ if ($2 == 04) print $1, $2, $3, $4}' | awk '{ if ($3 == 30) print $1, $2, $3, $4}' | sed 's/ /,/g' > VALBORG_$DATAFILE

# clean2_$DATAFILE > valborg_uppsala.csv

#cut -d',' -f1-4 
#cut -d' ' -f1-1 clean_$DATAFILE | sed 's/-//g' > date_$DATAFILE
#cut -d' ' -f3- clean_$DATAFILE > temp_$DATAFILE




