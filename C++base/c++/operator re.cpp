#include<iostream>
using namespace std;
//运算符重载
class person
{
public:
    person operator+(person &p)//成员函数重载加号
    {
        person temp;
        temp.m_a=this->m_a+p.m_a;
        temp.m_b=this->m_b+p.m_b;
        return temp;
    }
    int m_a;
    int m_b;
};

person operator+(person &p1,person &p2)//全局函数重载加号
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
    //成员函数的本质调用：person p3=p1.operrator+(p2)
    //全局函数的本质调用：person p3=operator+(p1,p2)
}

//左移运算符重载,只能利用全局函数重载

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

//递增运算符的重载
class myintegar
{
    friend ostream& operator<<(ostream& cout,myintegar myint)
public:
    myintegar()
    {
        m_num=0;
    }
    //前置++
    myintegar& operator++()
    {
        m_num++;//先++
        return *this;//再返回
    }
    //后置++
    myintegar operator++(int)
    {
        myintegar temp=*this;//先返回
        m_num++;//再++
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
//前置++
void test01()
{
    myintegar myint;
    cout<<++myint<<endl;//1
    cout<<myint<<endl;//1
}
//后置++
void test02()
{
    myintegar myint;
    cout<<myint++<<endl;//0
    cout<<myint<<endl;//1
}


//赋值运算符的重载
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
       m_age=new int(*p.m_age);//深拷贝
       return *this;
    }
    ~person()
    {
        if(m_age!=NULL)
        {
            delete m_age;//堆区内存重复释放
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
    cout<< "p1年龄wei:"<<*p1.m_age<<endl;
    cout<< "p1年龄wei:"<<*p2.m_age<<endl;
}

//重载关系运算符
class person
{
public:
    person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    bool operator==(person &p)//重载等号
    {
        if(this->m_name==p.m_name&&this->m_age==p.m_age)
        {
            return true;
        }
        return false;
    }
     bool operator!=(person &p)//重载不等号
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
        cout<< "一样大"<<endl;
    }
}

class myprint
{
public:
    void operator()(string test)//重载小括号，和函数很像
    {
        cout<<test<<endl;
    }
};
class myadd
{
public:
     int operator()(int num1,int num2)//仿函数非常灵活
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
    cout<<myadd()(100,100)<<endl;//匿名函数对象
}



