#/bin/bash
echo "run docker"
#set -v   
if [ $# -eq 0 ] 
then
	echo error; $0 [-d] imageid 
	exit
fi

if [ $1 = '-d' ]
then
	ret=`sudo docker run -d -v /data/docker:/data/data_host -v /home/dueb/gitcode:/data/code -it $2 /bin/bash`
	echo $ret
	cmd="sudo docker exec -it $ret /bin/bash"
	echo $cmd

else
	sudo docker run -v /data/docker:/data/host_data -v /home/dueb/gitcode:/data/code -it $1 /bin/bash
fi
	


