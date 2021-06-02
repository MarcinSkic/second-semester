#! /bin/bash

echo "press any key to continue"

while [ true ]
do
    read -t 3 -n 1  #-t <- how long it will wait until fails (3 seconds in this case)
                    #-n <- how many chars do it need to stop reading (1 in this case)
if [ $? = 0 ]       #$? <- exit status of last command (read succes is 0)
then
    echo "You pressed the key, congratulations! exiting"
    exit;
else
    echo "Press this key you stupid fuck!"
fi
done