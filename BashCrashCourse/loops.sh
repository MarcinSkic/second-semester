#! /bin/bash
#until -> do until statement is true, when true stop
number=1

echo "First loop"
until (( number >= 10 ))
do
	echo "$number"
	number=$((number+1))
done

echo "Second loop"
for i in 2 3
do
	echo $i
done

echo "Third loop"
for x in {0..20..3}	#last number is incrementator: i += 3
do
	echo $x
done

echo "Fourth loop"
for (( i=0; i<10; i++ ))
do
	if (( i == 2))
	then
	continue
	elif ((i == 5))
	then
	break
	fi
	echo $i
done