#include<iostream>
using namespace std;
//����ĳ�ʼ��������
class person
{
public:
    person()
    {
        cout<< "�����޲κ�������"<<endl;
    }
    person(int a)
    {
        age=a;
        cout<< "�����вκ�������"<<endl;
    }
    person(const person &p)
    {
        age=p.age;//������������ϵ��������ԣ��������ҵ�����
        cout<< "���쿽����������"<<endl;
    }
    //�����������������
    ~person()
    {
        cout<< "��������"<<endl;
    }
};//�����͹��춼�Ǳ����еĺ��������������Զ�����
//ֵ����
 dowork01(person p)
{

}
void test02()
{
    person p;
    dowork01(p);
}
void test01()
{
    person p1;//��Ҫʹ������
    person p2(10);
    person p3(p2);

}
int main()
{
    test01();
}


class person
{
public:
    person()
    {
        cout<< "�޲ι��캯��"<<endl;
    }
    person(int age,int height)
    {
        cout<< "�вι��캯��"<<endl;
        m_age=age;
        m_height=height;
    }
    person(const person &p)
    {
        cout<< "�������캯��"<<endl;
        m_age=p.m_age;
        m_height=new int(*p.m_height);//������ڶ������´���һ���ڴ�
    }
    ~person()//�ͷŶ������ڴ�
    {
        cout<< "��������"<<endl;
        if(m_height !=NULL)
        {
            delete m_height;
        }
    }
public:
    int m_age;
    int m_height;
};
void test01()
{
    person p1(18,180);
    person p2(p1);

}

//��ʼ���б�
class person
{
public:
    //��ͳ��ʼ������ֵ
    person(int a,int b,int c)
    {
        m_a=a;
        m_b=b;
        m_c=c;
    }
    person(int a,int b,int c):m_a(a),m_b(b),m_c(c)//��ʼ���б��﷨

    int m_a;
    int m_b;
    int m_c;
};
void test01()
{
    person p(10,20,30);
}

//�������������Ϊ����ĳ�Ա������ʱ���ȹ���������ٹ�������
//������˳�������෴
class phone
{
public:
    phone(string pname)
    {
        m_pname=pname;
    }
    string m_pname;
};
class person
{
    person(string name,string pname):m_name(name),m_phone(phone)
public:
    string m_name;
    string m_phone;

};









