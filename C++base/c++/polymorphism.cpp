#include<iostream>
using namespace std;
class cpu//����cpu
{
public:
    virtual void calculate()=0;//����ļ��㺯��
};
class videocard
{
public:
    virtual void display()=0;//����ļ��㺯��
};
class memory
{
public:
    virtual void storage()=0;//����ļ��㺯��
};
class computer
{
public:
    computer(cpu *cp��videocard *vc��memory *mem)
    {
        m_cp=cp;
        m_vc=vc;
        m_mem=mem;
    }
    ~computer()
    {
        if(m_cp!=NULL)//�ֶ������Ķ�����Ҫ�����ֶ��ͷ�
        {
            delete m_cp;
            m_cp=NULL;
        }
        if(m_vc!=NULL)
        {
            delete m_vc;
            m_vc=NULL;
        }
        if(m_mem!=NULL)
        {
            delete m_mem;
            m_mem=NULL;
        }
    }
private:
    cpu *m_cp;//cpu�����ָ��
    videocard *m_vc;
    memory *m_mem;
};
void work()//�ṩ��������
{
    m_cp->calculate();//�ú����������������ýӿ�
    m_vc->display();
    m_mem->storage();
}
class intelcpu:public cpu
{
public:
    virtual void calculate()
    {
        cout<< "Intel��cpu��ʼ������"<<endl;
    }
};
class intelvideocard:public videocard
{
public:
    virtual void display()
    {
        cout<< "Intel���Կ���ʼ��ʾ��"<<endl;
    }
};
class intelmemory:public memory
{
public:
    virtual void storage()
    {
        cout<< "Intel���ڴ�����ʼ�洢��"<<endl;
    }
};
class lenovocpu:public cpu
{
public:
    virtual void calculate()
    {
        cout<< "�����cpu��ʼ������"<<endl;
    }
};
class Lenovovideocard:public videocard
{
public:
    virtual void display()
    {
        cout<< "������Կ���ʼ��ʾ��"<<endl;
    }
};
class Lenovomemory:public memory
{
public:
    virtual void storage()
    {
        cout<< "������ڴ�����ʼ�洢��"<<endl;
    }
};
void test()
{
    //��һ̨���Ե����
    cpu *icpu=new intelcpu;
    videocard *ivc=new intelvideocard;
    memory *imem=new intelmemory;
    //������һ̨����
    computer *computer1=new computer(icpu,ivc,imem);
    computer1->work();
    delete computer1;

    //�ڶ�̨���Ե���װ
     computer *computer2=new computer(new lenovocpu,new Lenovovideocard,new Lenovomemory);//ֱ�Ӵ���
    computer2->work();
    delete computer2;
}




