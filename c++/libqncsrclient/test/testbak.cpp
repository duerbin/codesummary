//*******************************************************
//  @filename:	test.cpp
//  @function:	test qncsrclient.so
//  @author: 	dueb
//*******************************************************
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#ifdef _WIN32
#include <stdio.h>
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <pthread.h>
#endif
using namespace std;
int main()
{
	string filename="./5010.wav.pcm";
	ifstream in(filename.c_str(),ios::in|ios::binary|ios::ate);
	if(in.is_open())
	{
		int size=in.tellg();
		cout<<size<<endl;
		in.seekg(0,ios::beg);
		ostringstream ss;
		ss<<in.rdbuf();
		string outstr=ss.str();
		//outstr="111";
		cout<<outstr<<endl;
		int a;
		cin>>a;
		cout<<outstr.c_str()<<endl;
		char * strData=new char[outstr.length()+1];
		strncpy(strData,outstr.c_str(),outstr.length());
		std::cout<<outstr.c_str()<<endl;

	}
	else
	{
		return -1;
	}
}
