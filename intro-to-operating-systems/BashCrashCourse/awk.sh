#! /bin/bash
fileName=file2.txt
if [[ -f $fileName ]]
then
    awk '/linux/ {print $1,$2}' $fileName
else
    echo "You are so stupid fucker, there is no file like this fucker!"
fi