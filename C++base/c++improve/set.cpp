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
    //��������ֻ��insert�ķ�ʽ
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
     set<int>s2;
    s2.insert(100);
    s1.swap(s2);
    s1.erase(s1.begin());//ֻ��ɾ����С���Ǹ�
    s1.erase(30);//ֱ��ɾ������
    //����
    set<int>::iterator pos=s1.find(30);
    if(pos!=s1.end())
    {
        cout<< "�ҵ�Ԫ��"<< *pos<<endl;
    }
    //ͳ�Ƹ���
    int num=s1.count(30);
    cout<<num<<endl;//Ҫô��0��Ҫô��1

    //ָ���������Ϊ�Ӵ�С,�ڲ���֮ǰ��ָ������
    set<int,mycompare>s3;
    s3.insert(10);
    s3.insert(30);
    s3.insert(50);
    s3.insert(20);
}

//set��multiset������
void test()
{
    set<int>s;
    pair<set<int>::iterator,bool>ret=s.insert(10);
    if(ret.second)
    {
        cout<< "��һ�β���ɹ�"<<endl;
    }
    else
    {
        cout<< "��һ�β���ʧ��"<<endl;
    }
    mulitset<int>ms;
    ms.insert(10);
}

//pair���鴴��
void test()
{
    pair<string,int>p("tom",20);
    cout<< "����"<<p.first<< "���"<<p.second<<endl;
}

//�Զ����������͵�����
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
    person p1("��ɮ"��30);
    person p2("�����"��1000);
    person p3("��˽�"��999);
    person p4("ɳɮ"��800);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
}
















