#! /bin/bash

mkdir -p SomeDirectory
function appendFile()
{
    echo "Enter the text you want to append: "
    read text
    echo $text >> $1
}
echo "Write directory to check"
read direct
if [ -d $direct ]
then
    echo "This directory exists"
else
    echo "This directory doesn't exist"
fi

echo "Write file to append"
read fileName
if [ -f $fileName ]
then
    appendFile $fileName
else
    while ((1))
    do
        echo "File $fileName doesn't exists. Do you want to create it? (Y/N)"
        read choice
        if [[ $choice != "Y" && $choice != "N" ]]
        then
            echo "Wrong choice, try again"
            continue
        else
            break
        fi
    done
    if [[ $choice == "Y" ]]
    then
        touch $fileName
        appendFile $fileName
    else
        echo "File NOT created, program exits"
    fi
fi