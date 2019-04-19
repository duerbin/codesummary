//Client.cpp

#include <Ice/Ice.h>
#include <Printer.h>

using namespace std;
using namespace Demo;

int main(int argc, char * argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try {
        //初始化Ice，获取通讯器，智能指针
        ic = Ice::initialize(argc, argv);                   
        
        //创建通讯器的代理基类，该代理使用的请求标识为SimplePrinter
        //端口号：10000，协议：默认(TCP)        
        Ice::ObjectPrx base = ic->stringToProxy("qncsrcallback:default -p 10000");
        
        //代理基类向下转型为PrinterPrx代理类，调用本操作会向服务器发送请求。
        //如果转型成功就返回Printer接口的代理，如果转型失败就返回null代理。
        PrinterPrx printer = PrinterPrx::checkedCast(base);
        
        //不是Printer接口的代理，抛出异常
        if (!printer)                                      
            throw "Invalid proxy";                          
        //是Printer接口的代理，调用代理的操作printString
        printer->printString("Hello World!");              
    } catch (const Ice::Exception & ex) {//捕获Ice运行时异常
        cerr << ex << endl;
        status = 1;
    } catch (const char * msg) {//捕捉致命错误，输出错误串
        cerr << msg << endl;
        status = 1;
    }
    //通讯器必须初始化过，否则不能调用destroy
    if (ic) {                                              
        try {
            ic->destroy();//销毁通讯器
        } catch (const Ice::Exception & ex) {
            cerr << ex << endl;
            status = 1;
        }
    }
    return status;
} 
