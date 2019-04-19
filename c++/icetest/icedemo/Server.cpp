//Server.cpp��


//�������Ice.h�ļ�����֧��Ice����ʱ
#include <Ice/Ice.h>
//�������Printer.h����ʹ��Slice�淶
#include <Printer.h>

using namespace std;
using namespace Demo;

/*
�Ǽ���Printer����Printer.ice������Slice2cpp���������ɣ�
����printString�Ǵ��鷽�����Ǽ��಻�ܱ�ʵ������
������PrinterI��̳��ԹǼ���Printer���ṩ��printString���鷽����ʵ�֡�
*/
class PrinterI : public Printer {
public:
    virtual void printString(const string & s,const Ice::Current &);
};

/*
  Ice:Current����Ϊ�������в�����ʵ���ṩ���йص�ǰִ���������Ϣ��
  �������������ӣ���ʶ�����棬����������ģʽ�������ģ�����ID�ȡ�
*/
void PrinterI::printString(const string & s, const Ice::Current &)
{
    cout << s << endl;
}


int main(int argc, char* argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try {
        //��ʼ��Ice����ȡͨѶ��������ָ��
        ic = Ice::initialize(argc, argv);                           
        
        //��ͨѶ��ic�ϴ�������������SimplePrinterAdapter
        //ȱʡЭ��(TCP)���ڶ˿�10000�ϼ���
        Ice::ObjectAdapterPtr adapter
            = ic->createObjectAdapterWithEndpoints("SimplePrinterAdapter", "default -p 10000");
            
        //������������PrinterI
        Ice::ObjectPtr object = new PrinterI;    
                           
        //����������PrinterI������������������������������SimplePrinter��   
        //�ͻ��˱���ʹ�ô����Ƶ������ʶ����������ߵĲ�����        
        adapter->add(object,ic->stringToIdentity("SimplePrinter")); 
        
        //����������������ͻ����������ڿ��Է��ɸ���������PrinterI��
        adapter->activate();                                        
        //����ǰ�����������̣߳��ȴ�ͨѶ���ر�
        ic->waitForShutdown();                                      
    }catch (const Ice::Exception & e) { //��׽Ice����ʱ�׳����쳣
        cerr << e << endl;
        status = 1;
    } catch (const char * msg) {//��׽���������������
        cerr << msg << endl;
        status = 1;
    }
    //ͨѶ�������ʼ�����������ܵ���destroy
    if (ic) {                            
        try { 
            ic->destroy();//����ͨѶ��
        } catch (const Ice::Exception & e) {
            cerr << e << endl;
            status = 1;
        }
    }
    return status;
}
