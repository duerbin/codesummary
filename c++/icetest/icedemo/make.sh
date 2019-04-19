#########################################################################
# File Name: make.sh
# Author: dueb
# mail: duerbin@126.com
# Created Time: 2019年04月19日 星期五 11时20分31秒
#########################################################################
#!/bin/bash
 client Client.cpp qncsrinterface.cpp -I ./ -I ../lib/ice/include/ -I ../lib/log4cppz/include/ -lIce -lIceUtil -L ../lib/ice/lib/

