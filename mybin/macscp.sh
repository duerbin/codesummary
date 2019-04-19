# !/bin/bash

if [ $# -ne 1 ] ; then
	echo $# " parameter error"
	echo "example : macscp [filename]"
	exit 
fi

scp -r dueb@10.130.41.21:~/macbak/$1 .


