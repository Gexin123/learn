#include <iostream>
using namespace std;
#include<map>
void printmap(map<int,int>&m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<< "key="<<(*it.first)<< "value="<<it->second;
    }
    cout<<endl;
}

void test1()
{
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));//按照key排序
    //插入和删除
    m.insert(make_pair(2,20));
    m[4]=40;
    cout<<m[4]<<endl;//可以利用key访问到value
    m.erase(m.begin());
    m.erase(3);//按照key删除
    m.erase(m.begin(),m.end());
    //查找和统计
    map<int,int>::iterator pos=m.find(3);//返回的是迭代器
    int num=m.cout(3);//1或者0

}

class mycompare//写一个仿函数制定排序规则
{
public:
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
};
void test2()
{
    //自定义排序
    map<int,int,mycompare>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    for(map<int,int,mycompare>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<< "key="<<(*it.first)<< "value="<<it->second;
    }
}













