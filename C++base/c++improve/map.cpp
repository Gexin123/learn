#include <iostream>
using namespace std;
#include<map>
void printmap(map<int,int>&m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<< "key="<<(*it.first)<< "value="<<it->second;
    }
    cout<<endl;
}

void test1()
{
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));//����key����
    //�����ɾ��
    m.insert(make_pair(2,20));
    m[4]=40;
    cout<<m[4]<<endl;//��������key���ʵ�value
    m.erase(m.begin());
    m.erase(3);//����keyɾ��
    m.erase(m.begin(),m.end());
    //���Һ�ͳ��
    map<int,int>::iterator pos=m.find(3);//���ص��ǵ�����
    int num=m.cout(3);//1����0

}

class mycompare//дһ���º����ƶ��������
{
public:
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
};
void test2()
{
    //�Զ�������
    map<int,int,mycompare>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    for(map<int,int,mycompare>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<< "key="<<(*it.first)<< "value="<<it->second;
    }
}













