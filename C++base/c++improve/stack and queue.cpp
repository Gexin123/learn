#include <iostream>
using namespace std;
#include<queue>
//ջ���Ƚ����
stack<int>s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
while(!s.empty())
{
    cout<< "ջ��Ԫ��Ϊ��"<<s.top()<<endl;
    s.top();//����ջ��Ԫ��
}
cout<< "ջ�Ĵ�СΪ"<<s.size(<<endl;

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
    person p1("��ɮ"��30);
    person p2("�����"��1000);
    person p3("��˽�"��999);
    person p4("ɳɮ"��800);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    while(!q.empty())
    {
        cout<< "��ͷԪ��---����"<<q.front().m_name<<endl;
        cout<< "��βԪ��---����"<<q.back().m_name<<endl;
        q.pop();//����
    }
}
