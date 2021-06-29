#! /bin/bash

echo "enter 1st string"
read st1

echo "enter 2nd string"
read st2



if [ "$st1" == "$st2" ]
then
    echo "string same"
else
    echo "string not same"
fi

c=$st1$st2

echo "Polaczone stringi: $c"