#include<iostream>
using namespace std;
class person
{
public:
    static void func()
    {
        m_a=100;
        m_b=200;//静态成员函数不可以访问非静态成员变量
        cout<< "静态函数调用"<<endl;
    }
    static int m_a;
    int m_b;
};
void test01()
{
    person p;//通过对象访问
    p.func();
    person::func();//通过类名访问
}


//成员变量和成员函数是分开存储的
class person
{
   int m_a;
   void func(){}
};
void test01()
{
    person p;
    cout<< "size of p="<<sizeof(p)<<endl;//空对象占用的内存空间是：1
    //是为了区分每一个空对象占用的内存空间
}
void test02()
{
    person p;
    cout<< "size of p="<<sizeof(p)<<endl;//非空对象占用的内存空间是：4
    //就是int的内存大小，static也是4
}

//this指针概念
class person
{
public:
    person(int age)
    {
        //解决名称冲突
        this->age=age;//this指针指向被调用的成员函数所属的对象
    }
    person& personage(person &p)
    {
        this->age+=p.age;
        return *this;//this指向p2的指针，而*this就是这个对象本体
    }
    int age;//成员属性应该和参数进行区分
};
void test01()
{
    person p1(18);
    cout<< "p1的年龄是："<<p1.age<<endl;//
}
void test02()
{
    personp1(10);
    personp2(10);
    p2.personage(p1).personage(p1).personage(p1);//链式编程思想
    cout<< "p2的年龄为："<<p2.age<<endl;//
}
class person
{
public:
    void showperson() const//在成员函数后面加const，修饰的是this指向，让指针不可以修改
    {
        this->m_b=100;
        m_a=100;//
    }
    int m_a=100;
    mutable int m_b;//特殊变量，即使在常函数中，也可以修改这个值
};
const person p;//变为常对象


//友元：让一个函数或者类访问一个类中的私有成员
class building
{
    friend void goodgay(building *build)//goodgay这个全局函数是building的好朋友，可以访问里面的私有成员
public:
    building()
    {
        m_sittingroom="客厅"；
        m_bedroom="卧室"；
    }
public:
    string m_sittingtoom;
private:
    string m_bedroom;
};
void goodgay(building *build)
{
    cout<< "好基友全局函数，正在访问"<<build->m_sittingroom<<endl;
    cout<< "好基友全局函数，正在访问"<<build->m_bedroom<<endl;
}
void test01()
{
    building build;
    goodgay(&build);

}

//类做友元
class building;
class goodgay
{
public:
    goodgay();
public:
    void visit();//访问buildi中的属性
    building *build;
};
class building
{
    friend class goodgay;//goodgay是building的好盆友
public:
    building();
public:
    string m_sittingtoom;
private:
    string m_bedroom;

};
  building::building();//在类外构造成员函数
  {
      m_sittingroom="客厅"；
        m_bedroom="卧室"；
  }
   goodgay::goodgay()
   {
       build=new building;

   }
   void goodgay:: visit()
   {
       cout<< "好基友正在访问"<<build->m_sittingroom<<endl;
       cout<< "好基友正在访问"<<build->m_bedroom<<endl;
   }


//成员函数做友元
class building;
class goodgay
{
public:
    goodgay();
    void visit();
    void visit2();
    building *build;
};
class building
{
    friend void goodgay::visit();//goodgay类下的vivst成员函数作为本类的好朋友，可以访问私有成员
public:
    building();
public:
    string m_sittingroom;
private:
    string m_beroom;

};
building::building()
{
    m_sittingroom="客厅";
    m_bedroom="卧室";
}
goodgay::goodgay()
{
    build=new building;
}
    void goodgay::visit()
    {
        cout<< "visit正在访问"<<build->m_bedroom<<endl;
    }
    void goodgay::visit2()





