#include <iostream>
using namespace std;
#include "comunication.h"
#include <string>
#include <stdlib.h>
#define MAX 1000
struct person//��ϵ�˵Ľṹ��
{
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_address;
};
struct addressbooks//ͨѶ¼�б������ϵ������
{
    struct person personarray[MAX];
    int m_size;
};
void addperson(addressbooks *abs)
{
    if(abs->m_size==MAX)
    {
        cout << "��Ա����"<<endl;
        return;
    }
    else
    {
        //����
        string name;
        cout << "����������"<<endl;
        cin>>name;
        abs->personarray[abs->m_size].m_name=name;
        //�Ա�
        cout << "�������Ա�"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
        if(sex==1||sex==2)
        {
            abs->personarray[abs->m_size].m_sex=sex;
            break;
        }
        cout<< "������������"<<endl;
        }
        //����
        cout << "����������"<<endl;
        int age=0;
        cin>>age;
        abs->personarray[abs->m_size].m_age=age;
        //�绰
        cout << "��������ϵ�绰"<<endl;
        string phone;
        cin>>phone;
        abs->personarray[abs->m_size].m_phone=phone;
        //��ͥסַ
        cout << "�������ͥסַ"<<endl;
        string address;
        cin>>address;
        abs->personarray[abs->m_size].m_address=address;
        abs->m_size++;
        cout<< "��ӳɹ�"<<endl;
        system("pause");
        system("cls");
    }
}

void showperson(addressbooks *abs)
{
    if(abs->m_size==0)
    {
        cout << "��ǰ��¼Ϊ��"<<endl;
    }
    else
    {
        for(int i=0;i<abs->m_size;i++)
        {
            cout<< "����"<<abs->personarray[i].m_name<<endl;
        }
    }
    system("pause");
    system("cls");
}

int exist(addressbooks *abs,string name)
{
    for(int i=0;i<abs->m_size;i++)
    {
        if(abs->personarray[i].m_name==name)//�ҵ��û���������
        {
            return i;
        }
    }
    return -1;
}

void deletperson(addressbooks *abs)
{
  cout<< "��������Ҫɾ������ϵ��"<<endl;
  string name;
  cin>>name;
  int ret=exist(abs,name);
  if(ret!=-1)
  {
      for(int i=ret;i<abs->m_size;i++)
      {
          abs->personarray[i]=abs->personarray[i+1];
      }
      abs->m_size--;
      cout<< "ɾ���ɹ�"<<endl;
  }
  else
  {
      cout<< "���޴���"<<endl;
  }
  system("pause");
  system("cls");
}

//����ָ����ϵ����Ϣ
void findperson(addressbooks *abs)
{
    cout<< "��������Ҫ���ҵ���ϵ��"<<endl;
    string name;
    cin>>name;
    int ret=exist(abs,name);
    if(ret!=-1)
    {
        cout<< "����"<<abs->personarray[ret].m_name<<endl;
    }
    else
    {
        cout<< "���޴���"<<endl;
    }
    system("pause");
    system("cls");
}

//�޸�ָ����ϵ�˵���Ϣ
void modifyperson(addressbooks *abs)
{
    cout<< "��������Ҫ�޸ĵ���ϵ��"<<endl;
    string name;
    cin>>name;
    int ret=exist(abs,name);
    if(ret!=-1)
    {
        string name;
        cout<< "����������"<<endl;
        cin>>name;
        abs->personarray[ret].m_name=name;
        cout<< "�������Ա�"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
            if(sex==1||sex==2)
            {
                abs->personarray[ret].m_sex=sex;
                break;
            }
            cout<< "������������������ "<<endl;
        }
        cout<< "����������"<<endl;
        int age=0;
        cin>>age;
        abs->personarray[ret].m_age=age;
        cout<< "��������ϵ�˵绰"<<endl;
        string phone;
        cin>>phone;
        abs->personarray[ret].m_phone=phone;
        cout << "��������ϵ�˵�ַ"<<endl;
        string address;
        cin>>address;
        abs->personarray[ret].m_address=address;
    }
    else
    {
        cout<< "���޴���"<<endl;
    }
    system("pause");
    system("cls");
}

//���������ϵ��
void cleanperson(addressbooks *abs)
{
    abs->m_size=0;
    cout<< "ͨѶ¼�����"<<endl;
    system("pause");
    system("cls");
}
int main()
{
    addressbooks abs;
    abs.m_size=0;
while(true)
{
    showmenu();
    int select=0;
    cin>>select;
    switch(select)
    {
    case 1:
        addperson(&abs);//���õ�ַ���ݿ����޸�ʵ��
        break;
    case 2:
        showperson(&abs);
        break;
    case 3:
        deletperson(&abs);
        break;
    case 4:
        findperson(&abs);
        break;
    case 5:
        modifyperson(&abs);
        break;
    case 6:
        cleanperson(&abs);
    case 0:
        cout << "��ӭ�´�ʹ��"<<endl;
        return 0;
        break;
    default:
        break;
    }

}

}
