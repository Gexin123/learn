#include <iostream>
using namespace std;

//����ģ��
//�������ͽ����ĺ���
void swapint(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void swapdouble(int &a,int &b)
{
    double temp=a;
    a=b;
    b=temp;
}
//����ģ��
template<typename T>//T��һ��ͨ�õ��������ͣ�typename�����滻��class
void myswap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}
void test02()//���ú���ģ��
{
    int a=10;
    int b=20;
    myswap(a,b);//�Զ������Ƶ�������Ҫ�Ƶ���һ�µ��������Ͳſ���
    myswap<int>(a,b);//��ʾָ�����ͣ�T����Ҫȷ���������Ͳſ���ʹ��
}
void test01()
{
    int a=10;
    int b=20;
    swapint(a,b);
    double c=1.1;
    double d=2.2;
    swapdouble(c,d);
}

//ʵ��ͨ�ã��������������ĺ���
template<class T>
void mysort(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int max=i;
        for(int j=i+1;j<len;j++)
        {
            //�϶������ֵ�ȱ�����j��С���ǿ��Ը������ֵ
            if(arr[max]<arr[j])
            {
                max=j;
            }
        }
        if(max!=i)
        {
            myswap(arr[max],arr[i]);
        }
    }
}
template<class T>
void printarray(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}
void test03()
{
    char chararr[]='badcf';
    int num=sizeof(chararr)/sizeof(char);
    mysort(chararr,num);
    printarray(chararr,num);
}
void test04()
{
    int intarray[]={9,4,5,8,3};
    int num=sizeof(intarray)/sizeof(int);
    mysort(intarray,num);
    printarray(intarray,num);
}

//��ͨ�����ͺ���ģ�������
//��ͨ�������Է���
//�Զ������Ƶ������Է�����ʽ����ת��
//��ʾָ�����ͣ����Է���
int myadd(int a,int b)
{
    return a+b;
}
template<class T>
T myadd02(T a,T b)
{
    return a+b;
}
void test05()
{
    int a=10;
    int b=20;
    char c='c';//c��Ӧ��ascii��Ϊ99
    cout<<myaddd(a,c)<<endl;//109
    cout<<myadd02(a,c)<<endl;//�����﷨��û�а취��ʾ
    cout<<myadd02<int>(a,c)<<endl;109
}


//��ͨ�����뺯��ģ��ĵ��ù���
void myprint(int a,int b)
{
    cout<< "������ͨ����"<<endl;
}
template<class T>
void myprint(T a,T b)
{
    cout<< "���ú���ģ��"<<endl;
}
void test06()
{
    int a=10;
    int b=20;
    myprint(a,b);//���ȵ�����ͨ����
    myprint<>(a,b);//ǿ�Ƶ���ģ��
}

//ģ��ľ����ԣ��ض�������������Ҫ�þ��廯��ʽ����ʹʵ��
class person
{
public:
    person(string name,int age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    string m_name;
    int m_age;
};
template<class T>
bool mycompare(T &a,T &b)
{
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//���þ��廯person�İ汾ʵ�ִ��룬���廯���ȵ���
template<>bool mycompare(person &p1,person &p2)
{
    if(p1.m_name==p2.m_name&&p1.m_age==p2.m_age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test07()
{
    int a=10;
    int b=20;
    bool ret=mycompare(a,b);
    if(ret)
    {
        cout<< "a==b"<<endl;
    }
    else
    {
        cout<< "a!=b"<<endl;
    }
}
void test08()
{
    person p1("tom",10);
    person p2("tom",10);
    bool ret=mycompare(p1,p2);
    if(ret)
    {
        cout<< "p1==p2"<<endl;
    }
    else
    {
        cout<< "p1!=p2"<<endl;
    }
}

//��ģ��,���ͺ���ģ�������
template<class nametype,class agetype=int>
class person
{
public:
    person(nametype name,agetype age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    nametype m_name;
    agetype m_age;
};
void test09()
{
    person<string,int>p1("�����",18);//ֻ������ʾָ������
}

//��ģ���������������
template<class T1,class T2>
class person()
{
public:
    person(T1 name,T2 age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    void showperson()
    {
        cout<< "����"<<this->m_name<< "���"<<this->age<<endl;
    }
    T1 m_name;
    T2 m_age;
}
void printperson(person<string,int> &p)//1��ָ���������͡�2������Ҳ���Խ���ģ�廯
{
    p.showperson();
}
void test()
{
    person<string,int> p("�����",100);
    printperson(p);
}

//��ģ����̳�
template<class T>
class base
{
    T m;
};
//class son:public base//���󣬱���֪�������T����,���ܹ����ݸ�����
class son:public base<int>
{

};
template<class T1,class T2>
class son2:public base<T2>
{
    T1 obj;
};
void test()
{
    son2<int char>s2;
}

//��ģ��ĳ�Ա����������ʵ��
template <class T1,class T2>
class person()
{
public:
    person(T1 name,T2 age);
    T1 m_name;
    T2 m_age;
    void showpeson();
}
template<class T1,class T2>
 person<T1,T2>::person(T1 name,T2 age)
 {
     this->m_name=name;
     this->m_age=age;
 }
 template<class T1,class T2>
 void person<T1,T2>::showpeson()
 {
     cout<<this->m_name<<this->m_age<<endl;
 }

//��ģ��ķ��ļ���д�����Լ����
#include "person.cpp"//1��ֱ�Ӱ���Դ�ļ�
//2����.h��.cpp����д��һ�𣬽���׺��Ϊ.hcpp
void test()
{
    person<string,int> p("�����"��999);
    p.showperson();
}

//��ģ�����Ԫ
template<class T1,class T2>
class person
{
    //ȫ�ֺ��� ����ʵ��
    friend void printperson(person<T1,T2> p)
    {
        cout<< "������"<<p.m_name<<p.m_age<<endl;
    }
    //ȫ�ֺ��� ����ʵ��
    //�ӿ�ģ������б�
    friend void printperson2<>(person<T1,T2> p);
public:
    person(T1 name,T2 age)
    {
        this->m_name=name;
        this->m_age=age;
    }
private:
    T1 m_name;
    T2 m_age;
};
//ȫ�ֺ��� ����ʵ��
template<class T1,class T2>
void printperson2(person<T1,T2> p)
{
    cout<< "������"<<p.m_name<< "���"<<p.m_age<<endl;
}





