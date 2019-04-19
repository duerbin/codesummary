#########################################################################
# File Name: make.sh
# Author: dueb
# mail: duerbin@126.com
# Created Time: 2018年03月16日 星期五 19时11分18秒
#########################################################################
#!/bin/bash
rm ./libqncsrclient.so
rm test
cd ..
make
cd test
g++ test.cpp -o test -g -I../include -ldl -lqncsrclient -L/usr/lib -L../bin -L./ -lpthread -Wl,-rpath=./
cp ../bin/libqncsrclient.so ./
./test
