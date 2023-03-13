#include <iostream>
using namespace std;
#include<list>
void printlist(const list<int>&L)
{
  for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
  {
      cout<<*it;
  }
  cout<<endl;
}
void test1()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    list<int>L2(L1.begin(),L1.end());
    list<int>L3(L2);
    list<int>L4(10,1000);//�������������һ��
}

//��ֵ
void test2()
{
  list<int>L2;
  L2=L1;
  list<int>L3;
  L3.assign(L2.begin(),L2.end());
  list<int>L4;
  L4.assign(10,1000);
  //����
  L1.swap(L4);
}

void test1()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    if(L1.empty())
    {
        cout<< "��"<<endl;
    }
    L1.resize(10,1000);
    L1.resize(2);
    //�����ɾ��
    L1.push_front(100);
    L1.pop_back();
    L1.pop_front();
    L1.insert(L1.begin(),1000);
    L1.erase(L1.begin());
    L1.remove(1000);//ɾ������������ƥ���ֵ
    L1.clear();



}

bool mycompare(int v1,int v2)
{
    return v1>v2;//����
}
void test3()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(30);
    L1.push_back(60);
    //L1[]��L1.at()���ǲ�����ʹ�õ�

    //��ת
    L1.reverse();
    //����
    //sort(L1.begin(),L1.end());//���в�֧��������ʵ���������������֧���ñ�׼�㷨
    L1.sort();//Ĭ��������
    L1.sort(mycompare);//����ʵ�ֽ���
}

//������
class person
{
public:
    person(string name;int age,int height)
    {
        this->m_name=name;
        this->m_age=age;
        this->m_height=height;
    }
    string m_name;
    int m_age;
    int m_height;
};

bool compareperson(person &p1,person &p2)
{
    if(p1.m_age==p2.m_age)
    {
        return p1.m_height>p2.m_height;//������ߵĽ�������
    }
    else
    {
        return p1.m_age<p2.m_age;//�������
    }
}
void test4()
{
    list<person>L;
    person p1("a",23,170);
    person p2("b",20,180);
    person p3("c",25,190);
    person p4("d",35,200);
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);

}













