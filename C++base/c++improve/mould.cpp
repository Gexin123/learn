#include <iostream>
using namespace std;

//函数模板
//两个整型交换的函数
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
//函数模板
template<typename T>//T是一个通用的数据类型，typename可以替换成class
void myswap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}
void test02()//利用函数模板
{
    int a=10;
    int b=20;
    myswap(a,b);//自动类型推导，必须要推导出一致的数据类型才可以
    myswap<int>(a,b);//显示指定类型，T必须要确定数据类型才可以使用
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

//实现通用，对数组进行排序的函数
template<class T>
void mysort(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int max=i;
        for(int j=i+1;j<len;j++)
        {
            //认定的最大值比遍历的j还小，那可以更新最大值
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

//普通函数和函数模板的区别
//普通函数可以发生
//自动类型推导不可以发生隐式类型转换
//显示指定类型，可以发生
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
    char c='c';//c对应的ascii码为99
    cout<<myaddd(a,c)<<endl;//109
    cout<<myadd02(a,c)<<endl;//错误语法，没有办法显示
    cout<<myadd02<int>(a,c)<<endl;109
}


//普通函数与函数模板的调用规则
void myprint(int a,int b)
{
    cout<< "调用普通函数"<<endl;
}
template<class T>
void myprint(T a,T b)
{
    cout<< "调用函数模板"<<endl;
}
void test06()
{
    int a=10;
    int b=20;
    myprint(a,b);//优先调用普通函数
    myprint<>(a,b);//强制调用模板
}

//模板的局限性，特定的数据类型需要用具体化方式做特使实现
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
//利用具体化person的版本实现代码，具体化优先调用
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

//类模板,它和函数模板的区别
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
    person<string,int>p1("孙悟空",18);//只能用显示指定类型
}

//类模板对象做函数参数
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
        cout<< "姓名"<<this->m_name<< "年纪"<<this->age<<endl;
    }
    T1 m_name;
    T2 m_age;
}
void printperson(person<string,int> &p)//1、指定传入类型。2、参数也可以进行模板化
{
    p.showperson();
}
void test()
{
    person<string,int> p("孙悟空",100);
    printperson(p);
}

//类模板与继承
template<class T>
class base
{
    T m;
};
//class son:public base//错误，必须知道父类的T类型,才能够传递给子类
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

//类模板的成员函数的类外实现
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

//类模板的分文件编写问题以及解决
#include "person.cpp"//1、直接包含源文件
//2、将.h和.cpp内容写在一起，将后缀改为.hcpp
void test()
{
    person<string,int> p("孙悟空"，999);
    p.showperson();
}

//类模板和友元
template<class T1,class T2>
class person
{
    //全局函数 类内实现
    friend void printperson(person<T1,T2> p)
    {
        cout<< "姓名："<<p.m_name<<p.m_age<<endl;
    }
    //全局函数 类外实现
    //加空模板参数列表
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
//全局函数 类外实现
template<class T1,class T2>
void printperson2(person<T1,T2> p)
{
    cout<< "姓名："<<p.m_name<< "年纪"<<p.m_age<<endl;
}





