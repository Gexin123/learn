#include <iostream>
using namespace std;
//标准模板库
#include <vector>
#include <algorithm>//标准算法头文件
void myprint(int val)
{
    cout<<val<<endl;
}
void test01()
{
    vector<int> v;
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    vector<int>::iterator itbegin=v.begin();//起始迭代器，指向容器中第一个元素
    vector<int>::iterator itend=v.end();//结束迭代器，指向最后一个元素的下一个位置
    //第一种遍历方式
    while(itbegin!=itend)
{
    cout<<*itbegin<<endl;
    itbegin++;
}
//第二种遍历方式
for(vector<int>::iterator it=v.begin();it!=v.end();it++)
{
    cout<< *it<<endl;
}
//第三种遍历方式，利用STL提供遍历算法
for_each(v.begin(),v.end(),myprint());
}

//vector容器中存放自定义的数据类型
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
void test02()
{
    vector<person>v;
    person p1("aaa",10);
    person p2("bbb",20);
    person p3("ccc",30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for(vector<person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<< "姓名"<<(*it).m_name<<endl;
        cout<<it->m_name<<endl;
    }
}
void test03()
{
    vector<person*>v;
    person p1("aaa",10);
    person p2("bbb",20);
    person p3("ccc",30);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    for(vector<person*>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<< "姓名"<<(*it)->m_name<<endl;//解引用出来的是指针
    }
}

//vector容器嵌套容器
vector<vector<int>>v;
vector<int>v1;
vector<int>v2;
vector<int>v3;
for(int i=0;i<3;i++)
{
    v1.push_back(i+1);
    v1.push_back(i+2);
    v1.push_back(i+3);
}
v.push_back(v1);
v.push_back(v2);
v.push_back(v3);
//通过大容器遍历所有数据
for(vector<vector<int>::iterator it=v.begin();it!=v.end();it++)
{
    for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
    {
        cout<<*vit<< " ";
    }
    cout<<endl;
}




