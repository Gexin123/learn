#include<iostream>
using namespace std;
//对象的初始化和清理
class person
{
public:
    person()
    {
        cout<< "构造无参函数调用"<<endl;
    }
    person(int a)
    {
        age=a;
        cout<< "构造有参函数调用"<<endl;
    }
    person(const person &p)
    {
        age=p.age;//将传入的人身上的所有属性，拷贝到我的身上
        cout<< "构造拷贝函数调用"<<endl;
    }
    //析构函数，清理操作
    ~person()
    {
        cout<< "析构函数"<<endl;
    }
};//析构和构造都是必须有的函数，编译器会自动调用
//值传递
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
    person p1;//不要使用括号
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
        cout<< "无参构造函数"<<endl;
    }
    person(int age,int height)
    {
        cout<< "有参构造函数"<<endl;
        m_age=age;
        m_height=height;
    }
    person(const person &p)
    {
        cout<< "拷贝构造函数"<<endl;
        m_age=p.m_age;
        m_height=new int(*p.m_height);//深拷贝，在堆区重新创建一个内存
    }
    ~person()//释放堆区的内存
    {
        cout<< "析构函数"<<endl;
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

//初始化列表
class person
{
public:
    //传统初始化赋初值
    person(int a,int b,int c)
    {
        m_a=a;
        m_b=b;
        m_c=c;
    }
    person(int a,int b,int c):m_a(a),m_b(b),m_c(c)//初始化列表语法

    int m_a;
    int m_b;
    int m_c;
};
void test01()
{
    person p(10,20,30);
}

//当其他类对象作为本类的成员，构造时候先构造类对象，再构造自身。
//析构的顺序与它相反
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









