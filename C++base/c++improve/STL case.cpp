#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <map>
#include <string>
#include<stdlib.h>
#include <algorithm>
//有5名选手ABCDE，10个评委对其打分，去除最高分和最低分，取平均值
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
        string name="选手";
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
        cout<< "选手姓名"<<it->m_name<< "得分"<<it->m_score<<endl;
    }
}
int main()
{
    vector<person>v;
    creatperson(v);
    setscore(v);
    showscore(v);
}

//员工分组
class worker
{
public:
    string m_name;
    int m_salary;
};
void creatworker(vector<worker>&v)
{
    string nameseed="ABCDEFGHIJ"；
    for(int i=0;i<10;i++)
    {
        worker wor;
        wor.m_name= "员工";
        wor.m_name+=nameseed[i];
        wor.m_salary=rand()%10000+10000;
        v.push_back(wor);
    }
}
//员工的分组
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
        cout<< "姓名"<<pos->second.m_name<< "工资"<<pos->second.m_salary<<endl;
    }
}
int main()
{
    //创建员工
    vector<worker>vworker;
    creatworker(vworker);
    //员工分组
    multimap<int,worker>mworker;
    setgroup(vworker,mworker);
    //分组显示员工
    showworker(mworker);

}























