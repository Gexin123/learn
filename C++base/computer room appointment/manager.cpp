#include "manager.h"

manager::manager()
{

}
manager::manager(string name,string pwd)
{
    this->m_name=name;
    this->m_pwd=pwd;
    this->initvector();
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
void manager::opermenu()
{
        cout<< "��ӭ����Ա��"<<this->m_name<< "��¼!"<<endl;
        cout<< "\t\t------------------------\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       1.����˺�      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       2.�鿴�˺�      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       3.�鿴����      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       4.���ԤԼ      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       0.ע����¼      |\n";
        cout<< "\t\t------------------------\n";
}
void manager::addperson()
{
    cout<< "����������˺ŵ�����"<<endl;
    cout<< "1�����ѧ��"<<endl;
    cout<< "2�������ʦ"<<endl;
    string filename;
    string tip;
    string errotip;
    ofstream ofs;
    int select=0;
    cin>>select;
    if(select==1)
    {
        filename=STUDENT_FILE;
        tip="������ѧ�ţ�";
        errotip="ѧ���ظ���";
    }
    else
    {
        filename=TEACHER_FILE;
        tip="������ְ����ţ�";
        errotip="ְ�����ظ�!";
    }
    //����׷�ӵķ�ʽд�ļ�
    ofs.open(filename.c_str(),ios::out|ios::app);

    int id;
    string name;
    string pwd;

    while(true)
    {
        bool ret=checkrepeat(id,select);
        if(ret)
        {
            cout<< errotip<<endl;
        }
        else
        {
            break;
        }
    }
    cout<<tip<<endl;
    cin>>id;
    cout<< "������������"<<endl;
    cin>>name;
    cout<< "���������룺"<<endl;
    cin>>pwd;
    //���ļ����������
    ofs<<id<< " "<<name<< " "<<pwd<< " "<<endl;
    cout<< "��ӳɹ�"<<endl;
    system("pause");
    system("cls");
    ofs.close();
    //���ó�ʼ�������ӿڣ����»�ȡ�ļ��е�����
    this->initvector();

}
void printstudent(student &s)
{
    cout<< "ѧ�ţ�"<<s.m_id<< "������"<<s.m_name<<endl;
}
void printteacher(teacher &s)
{
    cout<< "ְ���ţ�"<<s.m_empid<< "������"<<s.m_name<<endl;
}
void manager::showperson()
{
    cout<< "��ѡ��鿴����"<<endl;
    cout<< "1��ѧ��"<<endl;
    cout<< "2����ʦ"<<endl;
    int select=0;
    cin>>select;
    if(select==1)
    {
        cout<< "����ѧ����Ϣ���£�"<<endl;
        for_each(vstu.begin(),vstu.end(),printstudent);
    }
    else
    {
        cout<< "������ʦ��Ϣ���£�"<<endl;
        for_each(vtea.begin(),vtea.end(),printteacher);
    }
    system("pause");
    system("cls");

}
void manager::showcomputer()
{
    cout<< "������Ϣ���£�"<<endl;
    for(vector<computerroom>::iterator it=vcom.begin();it!=vcom.end();it++)
    {
        cout<< "�������Ϊ��"<<it->m_comid<< "���������������"<<it->m_maxnum<<endl;
    }
    system("pause");
    system("cls");
}
void manager::cleanfile()
{
    ofstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();
    cout<< "��ճɹ���"<<endl;
    system("pause");
    system("cls");
}
void manager::initvector()
{
    vstu.clear();
    vtea.clear();
    //��ȡ��Ϣ��ѧ��
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if(!ifs.is_open())
    {
        cout<< "�ļ���ȡʧ��"<<endl;
        return;
    }
    student s;
    while(ifs>>s.m_id&&ifs>>s.m_name&&ifs>>s.m_pwd)
    {
        vstu.push_back(s);
    }
    cout<< "��ǰѧ��������Ϊ��"<<vstu.size()<<endl;
    ifs.close();
    //��ȡ��Ϣ: ��ʦ
    ifs.open(TEACHER_FILE,ios::in);
    teacher t;
    while(ifs>>t.m_empid&&ifs>>t.m_name&&ifs>>t.m_pwd)
    {
        vtea.push_back(t);
    }
    cout<< "��ǰ��ʦ������Ϊ��"<<vtea.size()<<endl;
    ifs.close();
}
bool manager::checkrepeat(int id,int type)
{
    if(type==1)
    {
        //���ѧ��
        for(vector<student>::iterator it=vstu.begin();it!=vstu.end();it++)
        {
            if(id==it->m_id)
            {
                return true;
            }
        }
    }
    else
    {
        for(vector<teacher>::iterator it=vtea.begin();it!=vtea.end();it++)
        {
            if(id==it->m_empid)
            {
                return true;
            }
        }
    }
}













