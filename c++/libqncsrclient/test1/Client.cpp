//Client.cpp

#include <Ice/Ice.h>
#include <qncsrinterface.h>

using namespace std;
using namespace csr;

int main(int argc, char * argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try {
        //��ʼ��Ice����ȡͨѶ��������ָ��
        ic = Ice::initialize(argc, argv);                   
        
        //����ͨѶ���Ĵ�����࣬�ô���ʹ�õ������ʶΪSimplePrinter
        //�˿ںţ�10000��Э�飺Ĭ��(TCP)        
        Ice::ObjectPrx base = ic->stringToProxy("qncsrcallback:default -h 10.130.41.12 -p 10000");
        
        //�����������ת��ΪPrinterPrx�����࣬���ñ����������������������
        //���ת�ͳɹ��ͷ���Printer�ӿڵĴ������ת��ʧ�ܾͷ���null����
        ResultCallbackProxyPrx printer = ResultCallbackProxyPrx::checkedCast(base);
        
        //����Printer�ӿڵĴ����׳��쳣
        if (!printer)                                      
            throw "Invalid proxy";                          
        //��Printer�ӿڵĴ������ô���Ĳ���printString
        printer->sendStreamResult("111","2222"); 
    } catch (const Ice::Exception & ex) {//����Ice����ʱ�쳣
        cerr << ex << endl;
        status = 1;
    } catch (const char * msg) {//��׽���������������
        cerr << msg << endl;
        status = 1;
    }
    //ͨѶ�������ʼ�����������ܵ���destroy
    if (ic) {                                              
        try {
            ic->destroy();//����ͨѶ��
        } catch (const Ice::Exception & ex) {
            cerr << ex << endl;
            status = 1;
        }
    }
    return status;
} 
