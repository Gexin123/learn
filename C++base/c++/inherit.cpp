#include<iostream>
using namespace std;
//利用继承实现
class basepage
{
    public:
    void header()
    {
        cout<< "首页、公开课、登录"<<endl;
    }
     void footer()
    {
        cout<< "帮助中心，交流合作、站内地图"<<endl;
    }
     void left()
    {
        cout<< "jave、python"<<endl;
    }
};
class java:public basepage//直接继承上面的basepage
{
public://再在此基础上写自己特有的
    void content()
    {
        cout<< "java学科视频"<<endl;
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
        m_a=10;//公共仍然公共
        m_b=20;//保护-保护
        m_c=30;//父类中的私有权限，不能访问
    }
};
class son1:protected base1
{
public:
    void func()
    {
        m_a=10;//公共--保护
        m_b=20;//保护--保护
    }

};
class son3:private base1
{
public:
    void func()
    {
        m_a=10;//公共--私有
        m_b=20;//保护--私有
    }
};
class grandson:public son3
{
public:
    void func()
    {
        //都不可以访问。上面全部都是私有了
    }
};

//继承中的构造顺序是先有父亲再有儿子，而析构顺序相反

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
    cout<<s.base::m_a<<endl;//100,同名的成员的处理，加上一个base的作用域

}


//多继承的语法
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
    cout<<s.base2::m_a<<endl;//加作用域加以区分
}

//菱形继承
class animal
{
public:
    int m_age;
};
class sheep:virtual public animal {};
class tuo:virtual public animal {};//虚继承，虚基类指针
class sheeptuo:public sheep,public tuo{};
void test01()
{
    sheeptuo st;
    st.sheep::m_age=18;
    st.tuo::m_age=20;
   cout<<st.m_age<<endl;//数据只有一份，会输出20
}








