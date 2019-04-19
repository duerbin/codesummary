#!/bin/sh

########################################################
#chdir --daemon
#
# Contact Center On Demand Platform
# Copyright 2008 Channelsoft(Beijing) Tech. Co.,Ltd.
# ALL RIGHTS RESERVED.
#
########################################################
#2009-5-25 
#(1)added list_service function
#(2)startup some units by using command "nohup"
########################################################
program='test'
usage() {
    echo "usage: $0 start|stop|restart|status|version";
    echo "  start: will stop all the Service first,and start all the service";
    echo "  stop: will stop all the Service";
    echo "  Service include: "$program,;
}

set_ulimit() {
	core_limit=`ulimit -c`
	[ $core_limit="0" ]
	if [ $? -eq "0" ]; then
		ulimit -c unlimited
		echo "ulimit set"
	fi;
}

list_service() {
ps -ef|grep $program|grep -v tail|grep -v grep
sleep 1
}

list_version() {
    echo "--------------------------------------"
    echo $program":"
    ./$program -v
    cd ..
    echo
}
restart_service()
{
stop_service
start_service
}
start_service() {
    echo "start begin........................."
    set_ulimit

 ret=`ps aux|grep $program|grep -v grep|grep -v tail|awk '{print $2}'`;
  if [ "$ret" ]; then
        echo $program" is running";
  else  
   nohup ./$program --config ./ >/dev/null 2>&1 &
  fi

   echo "start end........................."
   list_service
}
stop_service() {
    echo "stop begin........................."
  ret=`ps aux|grep $program|grep -v grep|grep -v tail|awk '{print $2}'`;
  #echo $ret;
  if [ "$ret" ]; then
 	echo "stop "$program;
	kill -9 $ret;
  else
	echo  $program" is stoped";
  fi
  
   list_service
}


if [ $# -gt 0 ]; then
  case $1 in
  "status")
    list_service
    ;;
  "start")
    start_service
    ;;
  "stop")
    stop_service
    ;;
  "restart")
    restart_service
    ;;
  "version")
    list_version
   ;;
  *)
    usage
  esac
else
    usage
fi;

