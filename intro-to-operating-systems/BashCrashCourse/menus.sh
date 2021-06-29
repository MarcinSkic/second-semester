#! /bin/bash
select car in BMW Mercedes Tesla Toyota Honda Ford
do
    case $car in
    BMW)
        echo "You have selected best car $car";;
    *)
        echo "Error you have chosen some stupid car or even you are turbo stupid and write some weird shit";;
    esac
done