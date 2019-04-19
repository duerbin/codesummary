#include <iostream>
#include <map>
using namespace std;


#include"commontools.h"
class student
{
    public:
        string name;
        int    age;
        char   info[10*200];
    public:
        student()
        {
            name="1";
            age=88;
        }
};

int main()
{
    student* s=new student();
    std::map<string,student*> testmap;
    testmap["12"]=s;
    
    std::map<string,student*>::const_iterator flag=testmap.begin();
    for(;flag!=testmap.end();flag++)
    {
        std::cout<<flag->second->age<<endl;
    }

    while(1)
    {
        student* s=new student();
        testmap["12"]=s;
    }
    
}
