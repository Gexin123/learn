#include<iostream>
using namespace std;
//���ü̳�ʵ��
class basepage
{
    public:
    void header()
    {
        cout<< "��ҳ�������Ρ���¼"<<endl;
    }
     void footer()
    {
        cout<< "�������ģ�����������վ�ڵ�ͼ"<<endl;
    }
     void left()
    {
        cout<< "jave��python"<<endl;
    }
};
class java:public basepage//ֱ�Ӽ̳������basepage
{
public://���ڴ˻�����д�Լ����е�
    void content()
    {
        cout<< "javaѧ����Ƶ"<<endl;
    }
};
void test01()
{
    java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
}

class base1
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};
class son1:public base1
{
public:
    void func()
    {
        m_a=10;//������Ȼ����
        m_b=20;//����-����
        m_c=30;//�����е�˽��Ȩ�ޣ����ܷ���
    }
};
class son1:protected base1
{
public:
    void func()
    {
        m_a=10;//����--����
        m_b=20;//����--����
    }

};
class son3:private base1
{
public:
    void func()
    {
        m_a=10;//����--˽��
        m_b=20;//����--˽��
    }
};
class grandson:public son3
{
public:
    void func()
    {
        //�������Է��ʡ�����ȫ������˽����
    }
};

//�̳��еĹ���˳�������и������ж��ӣ�������˳���෴

class base
{
public:
    base()
    {
        m_a=100;
    }
    int m_a;
};
class son:public base
{
public:
    son()
    {
        m_a=200;
    }
    int m_a;
};
void test01()
{
    son s;
    cout<< s.m_a<<endl;//200
    cout<<s.base::m_a<<endl;//100,ͬ���ĳ�Ա�Ĵ�������һ��base��������

}


//��̳е��﷨
class base1
{
public:
    base1()
    {
        int m_a=100;
    }
    int m_a=100;
};
class base2
{
public:
    base2()
    {
        int m_a=200;
    }
    int m_a=200;
};
class son:public base1,public base2
{
public:
    son()
    {
        m_c=300;
        m_d=400;
    }
    int m_c;
    int m_d;
};
void test()
{
    son s;
    cout<<s.base1::m_a<<endl;
    cout<<s.base2::m_a<<endl;//���������������
}

//���μ̳�
class animal
{
public:
    int m_age;
};
class sheep:virtual public animal {};
class tuo:virtual public animal {};//��̳У������ָ��
class sheeptuo:public sheep,public tuo{};
void test01()
{
    sheeptuo st;
    st.sheep::m_age=18;
    st.tuo::m_age=20;
   cout<<st.m_age<<endl;//����ֻ��һ�ݣ������20
}








