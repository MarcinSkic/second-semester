#! /bin/bash

echo "Write file to read"
read fileName
if [ -f $fileName ] #if file exists
then
    while IFS= read -r line
    do
        echo $line
        
    done < $fileName
    #rm $fileName <- deletes
else
    echo "we are in trouble"
fi