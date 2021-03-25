#!/bin/bash
echo enter run name : 
read varname
cd $varname
COUNTER=0

FILE=$varname'_r'$COUNTER'.bin'
echo "$FILE exist"
while [  -f "$FILE" ]; do
    FILEROOT=$varname'_r'$COUNTER'.root'
    daqana_v6f4 $FILE $FILEROOT
    COUNTER=$(( $COUNTER + 1))
    FILE=$varname'_r'$COUNTER'.bin'
    FILEROOT=$varname'_r'$COUNTER'.root' 
done



