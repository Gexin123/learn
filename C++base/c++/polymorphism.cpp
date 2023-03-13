#include<iostream>
using namespace std;
class cpu//抽象cpu
{
public:
    virtual void calculate()=0;//抽象的计算函数
};
class videocard
{
public:
    virtual void display()=0;//抽象的计算函数
};
class memory
{
public:
    virtual void storage()=0;//抽象的计算函数
};
class computer
{
public:
    computer(cpu *cp，videocard *vc，memory *mem)
    {
        m_cp=cp;
        m_vc=vc;
        m_mem=mem;
    }
    ~computer()
    {
        if(m_cp!=NULL)//手动创建的堆区需要将其手动释放
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
    cpu *m_cp;//cpu的零件指针
    videocard *m_vc;
    memory *m_mem;
};
void work()//提供工作函数
{
    m_cp->calculate();//让函数工作起来，调用接口
    m_vc->display();
    m_mem->storage();
}
class intelcpu:public cpu
{
public:
    virtual void calculate()
    {
        cout<< "Intel的cpu开始计算啦"<<endl;
    }
};
class intelvideocard:public videocard
{
public:
    virtual void display()
    {
        cout<< "Intel的显卡开始显示啦"<<endl;
    }
};
class intelmemory:public memory
{
public:
    virtual void storage()
    {
        cout<< "Intel的内存条开始存储啦"<<endl;
    }
};
class lenovocpu:public cpu
{
public:
    virtual void calculate()
    {
        cout<< "联想的cpu开始计算啦"<<endl;
    }
};
class Lenovovideocard:public videocard
{
public:
    virtual void display()
    {
        cout<< "联想的显卡开始显示啦"<<endl;
    }
};
class Lenovomemory:public memory
{
public:
    virtual void storage()
    {
        cout<< "联想的内存条开始存储啦"<<endl;
    }
};
void test()
{
    //第一台电脑的零件
    cpu *icpu=new intelcpu;
    videocard *ivc=new intelvideocard;
    memory *imem=new intelmemory;
    //创建第一台电脑
    computer *computer1=new computer(icpu,ivc,imem);
    computer1->work();
    delete computer1;

    //第二台电脑的组装
     computer *computer2=new computer(new lenovocpu,new Lenovovideocard,new Lenovomemory);//直接传入
    computer2->work();
    delete computer2;
}




