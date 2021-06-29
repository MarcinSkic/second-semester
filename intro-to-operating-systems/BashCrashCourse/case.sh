#! /bin/bash
car="Toyota"
case $car in
    "BMW" )
        echo "To BMW" ;;
    * )
        echo "Unknown car" ;;
esac