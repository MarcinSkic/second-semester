#! /bin/bash
echo "Where do I have to look fucker!?"
read fileName
fileName=file2.txt
if [[ -f $fileName ]]
then
    echo "Okay so i found the text fucker, now what do you want me to find huh, fucker?"
    read grepVar;
    grep  -i -n -v $grepVar $fileName #-i <- no case sensitivity, -n <- gives indexes, -c <- just gives amount as single result
    if [[ $? != 0 ]] #-v <- the everything other than searched variable
    then
        echo "There was no such word you FUCKER!!! Why do you waste my time fukcer!"
    fi
else
    echo "You are so stupid fucker, there is no file like this fucker!"
fi