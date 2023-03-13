#include <iostream>
using namespace std;
#include<set>
class mycompare
{
public:
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
};
void test1()
{
    set<int>s1;
    //插入数据只有insert的方式
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
     set<int>s2;
    s2.insert(100);
    s1.swap(s2);
    s1.erase(s1.begin());//只会删除最小的那个
    s1.erase(30);//直接删除数据
    //查找
    set<int>::iterator pos=s1.find(30);
    if(pos!=s1.end())
    {
        cout<< "找到元素"<< *pos<<endl;
    }
    //统计个数
    int num=s1.count(30);
    cout<<num<<endl;//要么是0，要么是1

    //指定排序规则为从大到小,在插入之前就指定规则
    set<int,mycompare>s3;
    s3.insert(10);
    s3.insert(30);
    s3.insert(50);
    s3.insert(20);
}

//set和multiset的区别
void test()
{
    set<int>s;
    pair<set<int>::iterator,bool>ret=s.insert(10);
    if(ret.second)
    {
        cout<< "第一次插入成功"<<endl;
    }
    else
    {
        cout<< "第一次插入失败"<<endl;
    }
    mulitset<int>ms;
    ms.insert(10);
}

//pair对组创建
void test()
{
    pair<string,int>p("tom",20);
    cout<< "姓名"<<p.first<< "年纪"<<p.second<<endl;
}

//自定义数据类型的排序
class person
{
public:
    person(string name;int age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    string m_name;
    int m_age;
};
class compareperson
{
public:
   bool operator()(const person&p1,const&p2)
   {
       return p1.m_age>p2.m_age;
   }
};
void test()
{
    set<person,compareperson>s;
    person p1("唐僧"，30);
    person p2("孙悟空"，1000);
    person p3("猪八戒"，999);
    person p4("沙僧"，800);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
}
















