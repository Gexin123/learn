#include "teacher.h"

teacher::teacher()
{

}
teacher::teacher(int empid,string name,string pwd)
{
    this->m_empid=empid;
    this->m_name=name;
    this->m_pwd=pwd;
}
void teacher::opermenu()
{
        cout<< "��ӭ��ʦ��"<<this->m_name<< "��¼!"<<endl;
        cout<< "\t\t------------------------\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       1.�鿴����ԤԼ  |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       2.���ԤԼ      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       0.ע����¼      |\n";
        cout<< "\t\t------------------------\n";
}
void teacher::showallorder()
{
    orderfile of;
     if(of.m_size==0)
     {
         cout<< "��ԤԼ��¼��"<<endl;
         system("pause");
         system("cls");
         return;
     }
     for(int i=0;i<of.m_size;i++)
     {
         cout<<i+1<< "��";
         cout<< "ԤԼ���ڣ���"<<of.m_orderdate[i]["date"];
         cout<< "ʱ��Σ�"<<(of.m_orderdate[i]["inrerval"])=="1" ? "����" : "����";
         cout<< "ѧ�ţ�"<<of.m_orderdate[i]["stuid"];
         cout<< "������"<<of.m_orderdate[i]["stuname"];
         cout<< "�����ţ�"<<of.m_orderdate[i]["roomid"];
         string status="״̬��";
             if(of.m_orderdate[i]["status"]=="1")
             {
                 status+="�����";
             }
             else if(of.m_orderdate[i]["status"]=="2")
             {
                 status+="ԤԼ�ɹ�";
             }
             else if(of.m_orderdate[i]["status"]=="-1")
             {
                 status+="ԤԼʧ��";
             }
             else
             {
                 status+="ԤԼ��ȡ��";
             }
             cout<<status<<endl;
     }
    system("pause");
     system("cls");

}
void teacher::validorder()
{
    orderfile of;
     if(of.m_size==0)
     {
         cout<< "��ԤԼ��¼��"<<endl;
         system("pause");
         system("cls");
         return;
     }
     cout<< "����˵�ԤԼ��¼���£�"<<endl;
     //�������������е��±���
     vector<int>v;
     int index=0;
     for(int i=0;i<of.m_size;i++)
     {
             if(of.m_orderdate[i]["status"]=="1")
             {
                 v.push_back(i);
                 cout<<index++<< "��";
                 cout<< "ԤԼ���ڣ���"<<of.m_orderdate[i]["date"];
             cout<< "ʱ���"<<(of.m_orderdate[i]["inrerval"])=="1" ? "����" : "����";
             cout<< "ѧ�ţ�"<<of.m_orderdate[i]["stuid"];
             cout<< "������"<<of.m_orderdate[i]["stuname"];
             cout<< "�����ţ�"<<of.m_orderdate[i]["roomid"];
             string status="�����";
             cout<<status<<endl;
             }
     }
     cout<< "��������˵�ԤԼ��¼"<<endl;
     int select=0;
     int ret=0;//����ԤԼ��¼���
     while(true)
     {
         cin>>select;
         if(select>=0&&select<=v.size())
         {
             if(select==0)
             {
                 break;
             }
             else
             {
                 cout<< "��������˽��"<<endl;
                 cout<< "1��ͨ��"<<endl;
                 cout<< "2����ͨ��"<<endl;
                 cin>>ret;
                 if(ret==1)
                 {
                     of.m_orderdate[v[select-1]]["status"]="2";
                 }
                 else
                 {
                     of.m_orderdate[v[select-1]]["status"]="-1";
                 }
                 of.updateorder();
                 cout<< "������"<<endl;
                 break;
             }
         }
         cout<< "����������������"<<endl;
     }
    system("pause");
    system("cls");
}
