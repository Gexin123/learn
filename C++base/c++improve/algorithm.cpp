#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>
//遍历
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
    //重载==
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
    //遍历
    for_each(v.begin(),v.end(),print01);//普通函数
    for_each(v.begin(),v.end(),print02());//仿函数
    //搬运
    vector<int>vtarget;
    vtarget.resize(v.size());
    transform(v.begin(),v.end(),vtarget.begin(),transform());//最后一个可以对其进行一个逻辑运算

    //查找
    vector<int>::iterator it=find(v.begin(),v.end(),5);
    if(it==v.end())
    {
        cout<< "没有找到"<<endl;
    }
    //查找自定义的数据类型
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
    //find_if查找
    vector<int>::iterator it=find_if(v.begin(),v.end(),greaterfive());
    //利用find_if查找自定义的数据类型
    vector<person>::iterator it=find_if(v2.begin(),v2.end(),greater20());
    //常用的查找算法adjacent_find
    //找到相邻的重复元素
    vector<int>::iterator pos=adjacent_find(v.begin(),v.end());
    //查找指定元素是否存在
    //二分查找法,必须是有序的序列
    //找到返回的是真，否则返回假
    bool ret=binary_search(v.begin(),v.end(),9);

    //统计元素个数
    int num=count(v.begin(),v.end(),40);
    //统计自定义的数据类型
    person p("abc",10);
    int num=count(v2.begin(),v2.end(),p);
    //按条件来统计
    int num=count_if(v.begin(),v.end(),greaterfive());
    //自定义的数据类型
    //大于20岁的人数
    int num=count_if(v2.begin(),v2.end(),countage20());

    //常用的排序算法
    sort(v.begin(),v.end());//默认从小到大
    for_each(v.begin(),v.end(),print01);
    //从大到小
    sort(v.begin(),v.end(),greater<int>());

    //洗牌
    srand(unsigned int)time(NULL);
    random_shuffle(v.begin(),v.end());

    //常用排序merge,两个合并的容器必须是有序的序列
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

    //反转
    reverse(v.begin(),v.end());

    //常用的拷贝
    vector<int>vcopy;
    vcopy.resize(v.size());
    copy(v.begin(),v.end(),vcopy.begin());
    //替换
    replace(v.begin(),v.end(),20,2000)//将所有的20都替换成2000

    //将区间内满足条件的都进行替换
    replace_if(v.begin(),v.end(),greaterfive(),3000);//将大于5的数都替换成3000

    //互换容器中的元素
    swap(v3,v4);

    //常用的算术生成算法
    int total=accumulate(v.begin(),v.end(),0);//累加，0是起始的累加值
    vector<int>v5;
    v5.resize(10);
    fill(v5.begin(),v5.end(),100);//填充，可以指定填充的数据

    //常用的集合运算
    //交集
    vector<int>vtarget2;
    vtarget2.resize(min(v3.size(),v4.size()));
    vector<int>::iterator itend=set_intersection(v3.begin(),v3.end(),v4.begin(),v4.end(),vtarget2.begin());
    for_each(vtarget2.begin(),itend(),print02());
    //并集
    vector<int>vtarget3;
    vtarget3.resize(v3.size()+v4.size());
    vector<int>::iterator itend=set_union(v3.begin(),v3.end(),v4.begin(),v4.end(),vtarget3.begin());
    //差集
    vector<int>vtarget4;
    vtarget4.resize(max(v3.size(),v4.size()));
    vector<int>::iterator itend=set_difference(v3.begin(),v3.end(),v4.begin(),v4.end(),vtarget4.begin());

}












