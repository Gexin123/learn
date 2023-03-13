#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//vector容器的扩展

void printvector(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<< " ";
    }
    cout<<endl;
}
void test()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    printvector(v1);
    //通过区间的方式构造
   vector<int>v2(v1.begin(),v1.end());
   printvector(v2);
   vector<int>v3(10,100);//10个100
   vector<int>v4(v3);
}

//赋值操作
vector<int>v1;
for(int i=0;i<10;i++)
{
    v1.push_back(i);
}
vector<int>v2;
v2=v1;
vector<int>v3;
v3.assign(v1.begin(),v1.end());
vector<int>v4;
v4.assign(10,100);

//vector容器的容量和大小
if(v1.empty())
{
    cout<< "v1为空"<<endl;
}
else
{
    cout<< "v1的容量为"<<v1.capacity()<<endl;
    cout<< "v1的大小为"<<v1.size()<<endl;
}
v1.resize(15,100);//利用重载版本，指定填充的值
v1.resize(5);//超出部分就会被删除


//插入，第一个参数是迭代器
v1.insert(v1.begin(),100);
v1.insert(v1.begin(),2,100);
//删除，参数也是迭代器
v1.erase(v1.begin());
v1.erase(v1.begin(),v1.end());//清空
v1.clear;//清空

//读取
for(int i=0;i<v1.size();i++)
{
    cout<<v1[i]<< " ";
    cout<<v1.at(i)<< " ";
}
cout<< "v1的第一个元素为："<<v1.front()<<endl;
cout<< "v1的最后一个元素为："<<v1.back()<<endl;

//容器的互换
v1.swap(v2);
//可以收缩内存空间
vector<int>v;
for(int i=0;i<1000;i++)
{
    v.push_back(i);
}
v.resize(3);
vector<int>(v).swap(v);

//预留空间
void test()
{
    vector<int>v;
    //利用reserv预留空间
    v.reserve(10000);
    int num=0;
    int *p=NULL;
    for(int i=0;i<10000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;//重复扩展了30次数据
        }
    }
}

//排序
void test()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    //300,200,100,10,20,30
}
sort(d.begin(),d.end());//默认从小到大













