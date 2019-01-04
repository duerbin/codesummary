# -*- coding: utf-8 -*-
# @Author: dueb
# @Date:   2018-12-20 12:03:52
# @Last Modified by:   dueb
# @Last Modified time: 2018-12-20 12:42:48

ifile_1="a.dat"
ifile_2="b.dat"
ofile="c.dat"

pofile=open(ofile,"w+")


def readAllline(ofile):
    oALLLine=[]
    pOfile=open(ofile,"r")
    
    oline=pOfile.readline()
    while oline:
        oALLLine.append(oline)
        oline=pOfile.readline()
    return oALLLine
o1=readAllline(ifile_1)
o2=readAllline(ifile_2)

gMerge=[]
for tmpline in o1:
    sp_tmp=tmpline.split('\x7f')
    key=sp_tmp[1]
    print key 
    for tmp_o2 in o2:
        if tmp_o2.find(key)==-1:
            gMerge.append(tmpline)


print gMerge
for merge in gMerge:
    pofile.write(merge)
for o2_tmp in o2:
    pofile.write(o2_tmp)

pofile.close()


