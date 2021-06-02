#! /bin/bash
n1=10
n2=30
echo $((31+21))
echo $((n1 + n2))
echo $(expr $n1 + $n2)  #Przestarzale

hex=FF5

echo -n "The decimal value of $hex is: "

echo "obase=10; ibase=16; $hex" | bc
