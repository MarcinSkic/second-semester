#! /bin/bash

car=('BMW' 'Toyota' 'Honda')

echo "${car[@]}"    #Show everything
echo "${#car[@]}"   #Length of array
echo "${!car[@]}"   #Show indexes {0 1 2 3 ...}

car[2]="Mercedes"
unset "car[1]"  #Removes variable on this index and not shrinks (you get hole in array)
printf "\nAfter unset and setting new value\n"
echo "${car[@]}"    #Show everything
echo "${#car[@]}"   #Length of array
echo "${!car[@]}" 