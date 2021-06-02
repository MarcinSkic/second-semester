#! /bin/bash
fileName=file2.txt
if [[ -f $fileName ]]
then
    cat $fileName | sed 's/b/B/'    #s <- substitute, $2 <- from, $3 <- into <but only first found>
    echo
    cat $fileName | sed 's/l/L/g'   #g <- global
    if grep "linux" $fileName
    then
        sed -i 's/linux/unix/g' $fileName #-i <- modifies used file instead of printing
    else
        sed -i 's/unix/linux/g' $fileName
    fi
else
    echo "You are so stupid fucker, there is no file like this fucker!"
fi