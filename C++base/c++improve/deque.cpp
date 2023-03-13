#include <iostream>
using namespace std;
#include <deque>
//构造函数,和vector一致
void printdeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<< " ";
    }
    cout<<endl;
}
void test()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d.push_back(i);
    }

    printdeque(d1);
     deque<int>d2(d1.begin(),d1.end());
     deque<int>d3(10,100);
     deque<int>d4(d3);
}

//赋值和vector一样的
//大小操作
if(d1.empty())
{
    cout<< "为空"<<endl;
}
else
{
    cout<< "不为空"<<endl;
    cout<< "d1的大小为"<<d1.size<<endl;
    //deque没有容量的概念
}

//删除
d1.push_back(10);//尾插
d1.push_front(100);//头插
d1.pop_back();//尾删
d1.pop_front();//头删
d1.insert(d1.begin(),1000);

deque<int>d2;
d2.push_back(10);
d2.push_back(30);
d1.insert(d1.begin(),d2.begin(),d2.end());

















