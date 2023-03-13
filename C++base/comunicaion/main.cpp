#include <iostream>
using namespace std;
#include "comunication.h"
#include <string>
#include <stdlib.h>
#define MAX 1000
struct person//联系人的结构体
{
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_address;
};
struct addressbooks//通讯录中保存的联系人数组
{
    struct person personarray[MAX];
    int m_size;
};
void addperson(addressbooks *abs)
{
    if(abs->m_size==MAX)
    {
        cout << "人员已满"<<endl;
        return;
    }
    else
    {
        //姓名
        string name;
        cout << "请输入姓名"<<endl;
        cin>>name;
        abs->personarray[abs->m_size].m_name=name;
        //性别
        cout << "请输入性别"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
        if(sex==1||sex==2)
        {
            abs->personarray[abs->m_size].m_sex=sex;
            break;
        }
        cout<< "有误，重新输入"<<endl;
        }
        //年龄
        cout << "请输入年龄"<<endl;
        int age=0;
        cin>>age;
        abs->personarray[abs->m_size].m_age=age;
        //电话
        cout << "请输入联系电话"<<endl;
        string phone;
        cin>>phone;
        abs->personarray[abs->m_size].m_phone=phone;
        //家庭住址
        cout << "请输入家庭住址"<<endl;
        string address;
        cin>>address;
        abs->personarray[abs->m_size].m_address=address;
        abs->m_size++;
        cout<< "添加成功"<<endl;
        system("pause");
        system("cls");
    }
}

void showperson(addressbooks *abs)
{
    if(abs->m_size==0)
    {
        cout << "当前记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<abs->m_size;i++)
        {
            cout<< "姓名"<<abs->personarray[i].m_name<<endl;
        }
    }
    system("pause");
    system("cls");
}

int exist(addressbooks *abs,string name)
{
    for(int i=0;i<abs->m_size;i++)
    {
        if(abs->personarray[i].m_name==name)//找到用户的姓名了
        {
            return i;
        }
    }
    return -1;
}

void deletperson(addressbooks *abs)
{
  cout<< "请输入您要删除的联系人"<<endl;
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
      cout<< "删除成功"<<endl;
  }
  else
  {
      cout<< "查无此人"<<endl;
  }
  system("pause");
  system("cls");
}

//查找指定联系人信息
void findperson(addressbooks *abs)
{
    cout<< "请输入您要查找的联系人"<<endl;
    string name;
    cin>>name;
    int ret=exist(abs,name);
    if(ret!=-1)
    {
        cout<< "姓名"<<abs->personarray[ret].m_name<<endl;
    }
    else
    {
        cout<< "查无此人"<<endl;
    }
    system("pause");
    system("cls");
}

//修改指定联系人的信息
void modifyperson(addressbooks *abs)
{
    cout<< "请输入您要修改的联系人"<<endl;
    string name;
    cin>>name;
    int ret=exist(abs,name);
    if(ret!=-1)
    {
        string name;
        cout<< "请输入姓名"<<endl;
        cin>>name;
        abs->personarray[ret].m_name=name;
        cout<< "请输入性别"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
            if(sex==1||sex==2)
            {
                abs->personarray[ret].m_sex=sex;
                break;
            }
            cout<< "输入有误，请重新输入 "<<endl;
        }
        cout<< "请输入年龄"<<endl;
        int age=0;
        cin>>age;
        abs->personarray[ret].m_age=age;
        cout<< "请输入联系人电话"<<endl;
        string phone;
        cin>>phone;
        abs->personarray[ret].m_phone=phone;
        cout << "请输入联系人地址"<<endl;
        string address;
        cin>>address;
        abs->personarray[ret].m_address=address;
    }
    else
    {
        cout<< "查无此人"<<endl;
    }
    system("pause");
    system("cls");
}

//清空所有联系人
void cleanperson(addressbooks *abs)
{
    abs->m_size=0;
    cout<< "通讯录被清空"<<endl;
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
        addperson(&abs);//利用地址传递可以修改实参
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
        cout << "欢迎下次使用"<<endl;
        return 0;
        break;
    default:
        break;
    }

}

}
