#! /bin/bash


#-eq -> ==
#-ne -> !=
#-lt -> <
#-gt -> >
#Jesli chcesz uzywac normalnych operatorow zastap "[]" -> "(())"


count=15
if (( count < 10 ))
then
    echo "lups"
elif [ $count -gt 10 ]
then
    echo "omegalups"
    echo "mam nadzieje ze mozna kilka"
else
    echo "gigalups"
fi

age=19
echo "First age test"
if [ $age -gt 10 ] && [ "$age" -lt 40 ]
then
    echo "Age correct"
else 
    echo "Age bad"
fi

echo "Second age test"
if [[ $age -gt 10  &&  "$age" -lt 40 ]]
then
    echo "Age correct"
else 
    echo "Age bad"
fi

echo "Third age test"
if [ "$age" -gt 10  -a  "$age" -lt 40 ]
then
    echo "Age correct"
else 
    echo "Age bad"
fi

echo "Fourth age test"
if (( age > 10  &&  age < 40 ))
then
    echo "Age correct"
else 
    echo "Age bad"
fi