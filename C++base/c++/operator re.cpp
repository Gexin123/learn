#include<iostream>
using namespace std;
//���������
class person
{
public:
    person operator+(person &p)//��Ա�������ؼӺ�
    {
        person temp;
        temp.m_a=this->m_a+p.m_a;
        temp.m_b=this->m_b+p.m_b;
        return temp;
    }
    int m_a;
    int m_b;
};

person operator+(person &p1,person &p2)//ȫ�ֺ������ؼӺ�
    {
        person temp;
        temp.m_a=p1.m_a+p2.m_a;
        temp.m_b=p1.m_b+p2.m_b;
        return temp;
    }
void test01()
{
    person p1;
    p1.m_a=10;
    p1.m_b=10;
    person p2;
    p2.m_a=10;
    p2.m_b=10;
    person p3=p1+p2;
    //��Ա�����ı��ʵ��ã�person p3=p1.operrator+(p2)
    //ȫ�ֺ����ı��ʵ��ã�person p3=operator+(p1,p2)
}

//�������������,ֻ������ȫ�ֺ�������

class person
{
public:
    int m_a;
    int m_b;
};
ostream& operator<<(ostream&cout,person &p)
{
    cout<< "m_a="<<p.m_a<< "m_b="<<p.m_b;
    return cout;
}
test01()
{
    person p;
    p.m_a=10;
    p.m_b=20;
    cout<<p;
}

//���������������
class myintegar
{
    friend ostream& operator<<(ostream& cout,myintegar myint)
public:
    myintegar()
    {
        m_num=0;
    }
    //ǰ��++
    myintegar& operator++()
    {
        m_num++;//��++
        return *this;//�ٷ���
    }
    //����++
    myintegar operator++(int)
    {
        myintegar temp=*this;//�ȷ���
        m_num++;//��++
        return temp;

    }
private:
    int m_num;
};
ostream& operator<<(ostream& cout,myintegar myint)
{
    cout<<myint.m_num;
    return cout;
}
//ǰ��++
void test01()
{
    myintegar myint;
    cout<<++myint<<endl;//1
    cout<<myint<<endl;//1
}
//����++
void test02()
{
    myintegar myint;
    cout<<myint++<<endl;//0
    cout<<myint<<endl;//1
}


//��ֵ�����������
class person
{
public:
    person(int age)
    {
        m_age=new int(age);
    }
    person& operator=(person &p)
    {
        if(m_age!=NULL)
        {
            delete m_age;
            m_age=NULL;
        }
       m_age=new int(*p.m_age);//���
       return *this;
    }
    ~person()
    {
        if(m_age!=NULL)
        {
            delete m_age;//�����ڴ��ظ��ͷ�
            m_age=NULL;
        }
    }
    int *m_age;
};
void test01()
{
    person p1(18);
    person p2(20);
    p2=p1;
    cout<< "p1����wei:"<<*p1.m_age<<endl;
    cout<< "p1����wei:"<<*p2.m_age<<endl;
}

//���ع�ϵ�����
class person
{
public:
    person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    bool operator==(person &p)//���صȺ�
    {
        if(this->m_name==p.m_name&&this->m_age==p.m_age)
        {
            return true;
        }
        return false;
    }
     bool operator!=(person &p)//���ز��Ⱥ�
    {
        if(this->m_name==p.m_name&&this->m_age==p.m_age)
        {
            return false;
        }
        return true;
    }
    string m_name;
    int m_age;
};
void test01()
{
    person p1("tom",18);
    person p2("sam",20);
    if(p1==p2)
    {
        cout<< "һ����"<<endl;
    }
}

class myprint
{
public:
    void operator()(string test)//����С���ţ��ͺ�������
    {
        cout<<test<<endl;
    }
};
class myadd
{
public:
     int operator()(int num1,int num2)//�º����ǳ����
    {
        return num1+num2;
    }
};
void test01()
{
    myprint print;
    myprint("hello world");
}
void test02()
{
    myadd add;
    cout<<myadd()(100,100)<<endl;//������������
}



