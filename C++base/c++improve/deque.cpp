#include <iostream>
using namespace std;
#include <deque>
//���캯��,��vectorһ��
void printdeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<< " ";
    }
    cout<<endl;
}
void test()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d.push_back(i);
    }

    printdeque(d1);
     deque<int>d2(d1.begin(),d1.end());
     deque<int>d3(10,100);
     deque<int>d4(d3);
}

//��ֵ��vectorһ����
//��С����
if(d1.empty())
{
    cout<< "Ϊ��"<<endl;
}
else
{
    cout<< "��Ϊ��"<<endl;
    cout<< "d1�Ĵ�СΪ"<<d1.size<<endl;
    //dequeû�������ĸ���
}

//ɾ��
d1.push_back(10);//β��
d1.push_front(100);//ͷ��
d1.pop_back();//βɾ
d1.pop_front();//ͷɾ
d1.insert(d1.begin(),1000);

deque<int>d2;
d2.push_back(10);
d2.push_back(30);
d1.insert(d1.begin(),d2.begin(),d2.end());

















