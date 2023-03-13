#include <iostream>
using namespace std;
#include<queue>
//栈，先进后出
stack<int>s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
while(!s.empty())
{
    cout<< "栈顶元素为："<<s.top()<<endl;
    s.top();//弹出栈顶元素
}
cout<< "栈的大小为"<<s.size(<<endl;

//queque
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
void test()
{
    queue<person>q;
    person p1("唐僧"，30);
    person p2("孙悟空"，1000);
    person p3("猪八戒"，999);
    person p4("沙僧"，800);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    while(!q.empty())
    {
        cout<< "队头元素---姓名"<<q.front().m_name<<endl;
        cout<< "队尾元素---姓名"<<q.back().m_name<<endl;
        q.pop();//出队
    }
}
