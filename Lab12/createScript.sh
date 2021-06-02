#! /bin/bash

#dl=$( awk '{$1print length}')
#if ((dl <= 3))
#then
#echo "Too short"
#exit
#fi

touch $1
chmod +x $1
codium $1
echo "#! /bin/bash" > $1