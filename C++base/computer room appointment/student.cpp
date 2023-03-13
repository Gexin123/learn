#include "student.h"


student::student()
{

}
student::student(int id,string name,string pwd)
{
    this->m_id=id;
    this->m_name=name;
    this->m_pwd=pwd;
    //��ʼ��������Ϣ
    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);
    computerroom c;
    while(ifs>>c.m_comid&&ifs>>c.m_maxnum)
    {
        vcom.push_back(c);
    }
    cout<< "��ǰ����������Ϊ��"<<vcom.size()<<endl;
    ifs.close();
}
void student::opermenu()
{
        cout<< "��ӭѧ������"<<this->m_name<< "��¼!"<<endl;
        cout<< "\t\t------------------------\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       1.����ԤԼ      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       2.�鿴�ҵ�ԤԼ  |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       3.�鿴����Ԥ    |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       4.ȡ��ԤԼ      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       0.ע����¼      |\n";
        cout<< "\t\t------------------------\n";

}
void student::applyorder()
{
    cout<< "����������ԤԼ��ʱ��:"<<endl;
    cout<< "1����һ"<<endl;
    cout<< "2���ܶ�"<<endl;
    cout<< "3������"<<endl;
    cout<< "4������"<<endl;
    cout<< "5������"<<endl;
    int date=0;
    int interval=0;
    int room=0;
    while(true)
    {
        cin>>date;
        if(date>=1&&date<=5)
        {
            break;
        }
        cout<< "������������������"<<endl;
    }
    cout<< "����������ԤԼ��ʱ��Σ�"<<endl;
    cout<< "1������"<<endl;
    cout<< "2������"<<endl;
    while(true)
    {
        cin>>interval;
        if(interval>=1&&interval<=2)
        {
            break;
        }
        cout<< "������������������"<<endl;
    }
    cout<< "��ѡ�������"<<endl;
    for(int i=0;i<vcom.size();i++)
    {
        cout<<vcom[i].m_comid<< "�Ż���������Ϊ��"<<vcom[i].m_maxnum<<endl;
    }
    while(true)
    {
        cin>>room;
        if(room>=1&&room<=3)
        {
            break;
        }
        cout<< "������������������"<<endl;
    }
    cout<< "ԤԼ�ɹ��������"<<endl;
    ofstream ofs;
    ofs.open(ORDER_FILE,ios::app);
    ofs<< "date:"<<date<< " ";
    ofs<< "interval:"<<interval<< " ";
    ofs<< "stuid:"<<this->m_id<< " ";
    ofs<< "stuname:"<<this->m_name<< " ";
    ofs<< "roomid:"<<room<< " ";
    ofs<< "status:"<<1<<endl;
    ofs.close();
    system("pause");
    system("cls");
}
void student::showmyorder()
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
         if(this->m_id==atoi(of.m_orderdate[i]["stuid"].c_str()))
         {
             cout<< "ԤԼ���ڣ���"<<of.m_orderdate[i]["date"];
             cout<< "ʱ���"<<(of.m_orderdate[i]["inrerval"])=="1" ? "����" : "����";
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
     }
     system("pause");
     system("cls");
 }
void student::showallorder()
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
void student::cancelorder()
{
    orderfile of;
     if(of.m_size==0)
     {
         cout<< "��ԤԼ��¼��"<<endl;
         system("pause");
         system("cls");
         return;
     }
     cout<< "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼"<<endl;
     //�������������е��±���
     vector<int>v;
     int index=1;
     for(int i=0;i<of.m_size;i++)
     {
         if(this->m_id==atoi(of.m_orderdate[i]["stuid"].c_str()))
         {
             if(of.m_orderdate[i]["status"]=="1"||of.m_orderdate[i]["status"]=="2")
             {
                 v.push_back(i);
                 cout<<index++<< "��";
                 cout<< "ԤԼ���ڣ���"<<of.m_orderdate[i]["date"];
             cout<< "ʱ���"<<(of.m_orderdate[i]["inrerval"])=="1" ? "����" : "����";
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
             cout<<status<<endl;
             }
         }
     }
     cout<< "������ȡ���ļ�¼"<<endl;
     int select=0;
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
                 of.m_orderdate[v[select-1]]["status"]="0";
                 of.updateorder();
                 cout<< "��ȡ��ԤԼ"<<endl;
                 break;
             }
         }
         cout<< "����������������"<<endl;
     }
    system("pause");
    system("cls");
}

