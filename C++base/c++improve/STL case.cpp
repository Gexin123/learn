#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <map>
#include <string>
#include<stdlib.h>
#include <algorithm>
//��5��ѡ��ABCDE��10����ί�����֣�ȥ����߷ֺ���ͷ֣�ȡƽ��ֵ
class person
{
public:
    person(string name,int score)
    {
        this->m_name=name;
        this->m_score=score;
    }
    string m_name;
    int m_score;
};
void creatperson(vector<person>&v)
{
    string nameseed="ABCDE";
    for(int i=0;i<5;i++)
    {
        string name="ѡ��";
        name+=nameseed[i];
        int score=0;
        person p(name,score);
        v.push_back(p);
    }
}
void setscore(vector<person>&v)
{
    for(vector<person>::iterator it=v.begin();it!=v.end();it++)
    {
        deque<int>d;
        for(int i=0;i<10;i++)
        {
            int score=rand()%40+61;
            d.push_back(score);
        }
        sort(d.begin(),d.end());
        d.pop_back();
        d.pop_front();
        int sum=0;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            sum+=*dit;
        }
        int avg=sum/d.size();
        it->m_score=avg;
    }
}
void showscore(vector<person>&v)
{
    for(vector<person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<< "ѡ������"<<it->m_name<< "�÷�"<<it->m_score<<endl;
    }
}
int main()
{
    vector<person>v;
    creatperson(v);
    setscore(v);
    showscore(v);
}

//Ա������
class worker
{
public:
    string m_name;
    int m_salary;
};
void creatworker(vector<worker>&v)
{
    string nameseed="ABCDEFGHIJ"��
    for(int i=0;i<10;i++)
    {
        worker wor;
        wor.m_name= "Ա��";
        wor.m_name+=nameseed[i];
        wor.m_salary=rand()%10000+10000;
        v.push_back(wor);
    }
}
//Ա���ķ���
void setgroup(vector<worker>&v,multimap<int,worker>&m)
{
    for(vector<worker>::iterator it=v.begin();it!=v.end();it++)
    {
        int deptid=rand()%3;
        m.insert(make_pair(deptid,*it));
    }
}
void showworker(multimap<int,worker>&m)
{
    multimap<int,worker>::iterator pos=m.find(0);
    int count=m.count(0);
    int index=0;
    for(;pos!=m.end()&&index<count;pos++,index++)
    {
        cout<< "����"<<pos->second.m_name<< "����"<<pos->second.m_salary<<endl;
    }
}
int main()
{
    //����Ա��
    vector<worker>vworker;
    creatworker(vworker);
    //Ա������
    multimap<int,worker>mworker;
    setgroup(vworker,mworker);
    //������ʾԱ��
    showworker(mworker);

}























