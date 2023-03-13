#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>
//����
void print01(int val)
{
    cout<<val<<endl;
}
class print02
{
public:
    void operator()(int val)
    {
        cout<<val<<endl;
    }
};
class transform
{
public:
    int operator()(int v)
    {
        return v+1000;
    }
};
class person
{
public:
    person(string name,int age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    //����==
    bool operator==(const person &p)
    {
        if(this->m_name==p.m_name&&this->m_age==p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_name;
    int m_age;
};
class greaterfive
{
public:
    bool operator()(int val)
    {
        return val>5;
    }
};
class greater20
{
public:
    bool operator()(const person &p)
    {
        return p.m_age>20;
    }
};
class countage
{
public:
    bool operator==(const person &p)
    {
        if(this->m_age==p.m_age)
        {
           return true;
        }
        else
        {
            return false;
        }
    }
};
class countage20
{
public:
    bool operator()(const person &p)
    {
       return p.m_age>20;
    }
};
void test()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //����
    for_each(v.begin(),v.end(),print01);//��ͨ����
    for_each(v.begin(),v.end(),print02());//�º���
    //����
    vector<int>vtarget;
    vtarget.resize(v.size());
    transform(v.begin(),v.end(),vtarget.begin(),transform());//���һ�����Զ������һ���߼�����

    //����
    vector<int>::iterator it=find(v.begin(),v.end(),5);
    if(it==v.end())
    {
        cout<< "û���ҵ�"<<endl;
    }
    //�����Զ������������
    vector<person>v2;
    person p1("a",10);
    person p2("b",20);
    person p3("d",30);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    vector<person>::iterator it=find(v2.begin(),v2.end(),p2);
    if(it==v2.end())
    {
        cout<<"not find"<<endl;
    }
    else
        cout<<it->m_name<<it->m_age<<endl;
    //find_if����
    vector<int>::iterator it=find_if(v.begin(),v.end(),greaterfive());
    //����find_if�����Զ������������
    vector<person>::iterator it=find_if(v2.begin(),v2.end(),greater20());
    //���õĲ����㷨adjacent_find
    //�ҵ����ڵ��ظ�Ԫ��
    vector<int>::iterator pos=adjacent_find(v.begin(),v.end());
    //����ָ��Ԫ���Ƿ����
    //���ֲ��ҷ�,���������������
    //�ҵ����ص����棬���򷵻ؼ�
    bool ret=binary_search(v.begin(),v.end(),9);

    //ͳ��Ԫ�ظ���
    int num=count(v.begin(),v.end(),40);
    //ͳ���Զ������������
    person p("abc",10);
    int num=count(v2.begin(),v2.end(),p);
    //��������ͳ��
    int num=count_if(v.begin(),v.end(),greaterfive());
    //�Զ������������
    //����20�������
    int num=count_if(v2.begin(),v2.end(),countage20());

    //���õ������㷨
    sort(v.begin(),v.end());//Ĭ�ϴ�С����
    for_each(v.begin(),v.end(),print01);
    //�Ӵ�С
    sort(v.begin(),v.end(),greater<int>());

    //ϴ��
    srand(unsigned int)time(NULL);
    random_shuffle(v.begin(),v.end());

    //��������merge,�����ϲ����������������������
    vector<int>v3;
    vector<int>v4;
    for(int i=0;i<10;i++)
    {
        v3.push_back(i);
        v4.push_back(i+5);
    }
    vector<int>vtarget;
    vtarget.resize(v3.size()+v4.size());
    merge(v3.begin(),v3.end(),v4.begin(),v4.end(),vtarget.begin());

    //��ת
    reverse(v.begin(),v.end());

    //���õĿ���
    vector<int>vcopy;
    vcopy.resize(v.size());
    copy(v.begin(),v.end(),vcopy.begin());
    //�滻
    replace(v.begin(),v.end(),20,2000)//�����е�20���滻��2000

    //�����������������Ķ������滻
    replace_if(v.begin(),v.end(),greaterfive(),3000);//������5�������滻��3000

    //���������е�Ԫ��
    swap(v3,v4);

    //���õ����������㷨
    int total=accumulate(v.begin(),v.end(),0);//�ۼӣ�0����ʼ���ۼ�ֵ
    vector<int>v5;
    v5.resize(10);
    fill(v5.begin(),v5.end(),100);//��䣬����ָ����������

    //���õļ�������
    //����
    vector<int>vtarget2;
    vtarget2.resize(min(v3.size(),v4.size()));
    vector<int>::iterator itend=set_intersection(v3.begin(),v3.end(),v4.begin(),v4.end(),vtarget2.begin());
    for_each(vtarget2.begin(),itend(),print02());
    //����
    vector<int>vtarget3;
    vtarget3.resize(v3.size()+v4.size());
    vector<int>::iterator itend=set_union(v3.begin(),v3.end(),v4.begin(),v4.end(),vtarget3.begin());
    //�
    vector<int>vtarget4;
    vtarget4.resize(max(v3.size(),v4.size()));
    vector<int>::iterator itend=set_difference(v3.begin(),v3.end(),v4.begin(),v4.end(),vtarget4.begin());

}












