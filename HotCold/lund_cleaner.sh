#!/bin/bash

usage(){
	echo "----"
	echo -e "  To call this script please use"
	echo -e "   $0 <path>"
	echo -e "  Examples:"
        echo -e "   $0 ../datasets/rawdata_smhi-opendata_Lund.csv"
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

cut -d' ' -f1-3 original_$DATAFILE | cut -d' ' -f2 --complement | sed 's/-/ /g' | sed 's/,,/ /g' > clean_$DATAFILE
awk '{ if ($2 == 04) print $1, $2, $3, $4}'  clean_$DATAFILE | awk '{ if ($3 == 30) print $1, $2, $3, $4}' | sed 's/ /,/g' > VALBORG_$DATAFILE


#cut -d' ' -f1-1 clean_$DATAFILE | sed 's/-//g' > date_$DATAFILE
#cut -d' ' -f3- clean_$DATAFILE > temp_$DATAFILE




