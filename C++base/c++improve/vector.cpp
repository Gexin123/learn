#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//vector��������չ

void printvector(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<< " ";
    }
    cout<<endl;
}
void test()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    printvector(v1);
    //ͨ������ķ�ʽ����
   vector<int>v2(v1.begin(),v1.end());
   printvector(v2);
   vector<int>v3(10,100);//10��100
   vector<int>v4(v3);
}

//��ֵ����
vector<int>v1;
for(int i=0;i<10;i++)
{
    v1.push_back(i);
}
vector<int>v2;
v2=v1;
vector<int>v3;
v3.assign(v1.begin(),v1.end());
vector<int>v4;
v4.assign(10,100);

//vector�����������ʹ�С
if(v1.empty())
{
    cout<< "v1Ϊ��"<<endl;
}
else
{
    cout<< "v1������Ϊ"<<v1.capacity()<<endl;
    cout<< "v1�Ĵ�СΪ"<<v1.size()<<endl;
}
v1.resize(15,100);//�������ذ汾��ָ������ֵ
v1.resize(5);//�������־ͻᱻɾ��


//���룬��һ�������ǵ�����
v1.insert(v1.begin(),100);
v1.insert(v1.begin(),2,100);
//ɾ��������Ҳ�ǵ�����
v1.erase(v1.begin());
v1.erase(v1.begin(),v1.end());//���
v1.clear;//���

//��ȡ
for(int i=0;i<v1.size();i++)
{
    cout<<v1[i]<< " ";
    cout<<v1.at(i)<< " ";
}
cout<< "v1�ĵ�һ��Ԫ��Ϊ��"<<v1.front()<<endl;
cout<< "v1�����һ��Ԫ��Ϊ��"<<v1.back()<<endl;

//�����Ļ���
v1.swap(v2);
//���������ڴ�ռ�
vector<int>v;
for(int i=0;i<1000;i++)
{
    v.push_back(i);
}
v.resize(3);
vector<int>(v).swap(v);

//Ԥ���ռ�
void test()
{
    vector<int>v;
    //����reservԤ���ռ�
    v.reserve(10000);
    int num=0;
    int *p=NULL;
    for(int i=0;i<10000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;//�ظ���չ��30������
        }
    }
}

//����
void test()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    //300,200,100,10,20,30
}
sort(d.begin(),d.end());//Ĭ�ϴ�С����













