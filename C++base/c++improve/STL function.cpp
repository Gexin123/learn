#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>//�ڽ���������ͷ�ļ�
//�º������в���Ҳ�з���ֵ
class myadd
{
public:
    int operator()(int v1,int v2)
    {
        return v1+v2;
    }

};
class myprint
{
public:
    myprint()
    {
        this->count=0;
    }
    void operator()(string test)
    {
        cout<<test<<endl;
        this->count++;
    }
    int count;//�ڲ��Լ���״̬
};
//�������������Ϊ��������
void doprint(myprint &mp,string test)
{
    mp(test);
}
void test()
{
    myprint myp;
    doprint(myp,"hello");
}

//�º�������bool���ͣ���Ϊν��
class greaterfive
{
public:
    bool operator()(int val)//һԪν��
    {
        return val>5;
    }
};
void test()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it=find_if(v.begin(),v.end(),greaterfive());
}

//��Ԫν��
class compare
{
public:
    bool operator()(int val1,int val2)//��Ԫν��
    {
        return val1>val2;
    }
};
void test()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(70);
    v.push_back(30);
    sort(v.begin(),v.end());
    sort(v.begin(),v.end(),compare());
}

//�����º���
void test()
{
    negate<int>n;
    n(50);//ȡ��
    plus<int>p;
    p(10,20);//��Ԫ���

}

//��ϵ�º���
void test()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(70);
    v.push_back(30);
    //greater<int>(),�ڽ��ķº���
    sort(v.begin(),v.end(),greater<int>());//��Ϊ����
}

//�߼��º���
void test()
{
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    //�����߼��ǽ�����v���˵�����2��ȥ
    vector<bool>v2;
    v2.resize(v.size());//���ٿռ�
    transform(v.begin(),v.end(),logical_not<bool>());
}
























