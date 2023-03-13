#include <iostream>
using namespace std;
//��׼ģ���
#include <vector>
#include <algorithm>//��׼�㷨ͷ�ļ�
void myprint(int val)
{
    cout<<val<<endl;
}
void test01()
{
    vector<int> v;
    //�������в�������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    vector<int>::iterator itbegin=v.begin();//��ʼ��������ָ�������е�һ��Ԫ��
    vector<int>::iterator itend=v.end();//������������ָ�����һ��Ԫ�ص���һ��λ��
    //��һ�ֱ�����ʽ
    while(itbegin!=itend)
{
    cout<<*itbegin<<endl;
    itbegin++;
}
//�ڶ��ֱ�����ʽ
for(vector<int>::iterator it=v.begin();it!=v.end();it++)
{
    cout<< *it<<endl;
}
//�����ֱ�����ʽ������STL�ṩ�����㷨
for_each(v.begin(),v.end(),myprint());
}

//vector�����д���Զ������������
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
        cout<< "����"<<(*it).m_name<<endl;
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
        cout<< "����"<<(*it)->m_name<<endl;//�����ó�������ָ��
    }
}

//vector����Ƕ������
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
//ͨ��������������������
for(vector<vector<int>::iterator it=v.begin();it!=v.end();it++)
{
    for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
    {
        cout<<*vit<< " ";
    }
    cout<<endl;
}




