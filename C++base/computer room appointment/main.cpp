#include <iostream>
using namespace std;
#include <stdlib.h>
#include "identity.h"
#include <fstream>
#include <string>
#include "globalflie.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"


//����ѧ�����Ӳ˵�
void studentmenu(identity* &stud)
{
    while(true)
    {
        //����ѧ���Ӳ˵�
        stud->opermenu();
        student* stu=(student*)stud;
        int select=0;
        cin>>select;
        if(select==1)//
        {
            stu->applyorder();
        }
        else if(select==2)//
        {
            stu->showmyorder();
        }
        else if(select==3)//
        {
              stu->showallorder();
        }
        else if(select==4)//
        {
            stu->cancelorder();
        }
        else
        {
            delete stu;
            cout<< "ע���ɹ�"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void teachermenu(identity* &teach)
{
        while(true)
    {
        //���ù���Ա�Ӳ˵�
        teach->opermenu();
        teacher* tea=(teacher*)teach;
        int select=0;
        cin>>select;
        if(select==1)//����˺�
        {
            tea->showallorder();
        }
        else if(select==2)//�鿴�˺�
        {
            tea->validorder();
        }
        else
        {
            delete teach;
            cout<< "ע���ɹ�"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
//�������Ա�Ӳ˵�ҳ��
void managermenu(identity*&manag)
{
    while(true)
    {
        //���ù���Ա�Ӳ˵�
        manag->opermenu();
        manager* man=(manager*)manag;
        int select=0;
        cin>>select;
        if(select==1)//����˺�
        {
            man->addperson();
        }
        else if(select==2)//�鿴�˺�
        {
            man->showperson();
        }
        else if(select==3)//�鿴������Ϣ
        {
              man->showcomputer();
        }
        else if(select==4)//���ԤԼ
        {
            man->cleanfile();
        }
        else
        {
            delete manag;
            cout<< "ע���ɹ�"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }

}
//��¼���� ����1 �����ļ��� ����2 �����������
    void loginin(const string& filename,int type)
    {
        identity *person=NULL;
        //���ļ�
        ifstream ifs;
        ifs.open(filename.c_str(),ios::in);
        if(!ifs.is_open())
        {
            cout<< "�ļ�������"<<endl;
            ifs.close();
            return;
        }
        int id=0;
        string name;
        string pwd;
        //�ж����
        if(type==1)
        {
            cout<< "���������ѧ�ţ�"<<endl;
            cin>>id;
        }
        else if(type==2)
        {
            cout<< " ����������ְ���ţ�"<<endl;
            cin>>id;
        }
        cout<< "�������û�����"<<endl;
        cin>>name;
        cout<< "���������룺"<<endl;
        cin>>pwd;
        int fid=0;
        string fname;
        string fpwd;
        if(type==1)
        {
            //ѧ�������֤
            while(ifs>>fid &&ifs>>fname &&ifs>>fpwd)
            {
             if(fid==id&&fname==name&&fpwd==pwd)
                {
                    cout<< "ѧ����¼�ɹ�"<<endl;
                    system("pause");
                    system("cls");
                    person=new student(id,name,pwd);
                    //����ѧ����ݵ��Ӳ˵�
                    studentmenu(person);
                    return;

                }
            }
        }
        else if(type==2)
        {
            //��ʦ�����֤
        while(ifs>>fid &&ifs>>fname &&ifs>>fpwd)
            {
             if(fid==id&&fname==name&&fpwd==pwd)
                {
                    cout<< "��ʦ��¼�ɹ�"<<endl;
                    system("pause");
                    system("cls");
                    person=new teacher(id,name,pwd);
                    //�����ʦ��ݵ��Ӳ˵�
                    teachermenu(person);
                    return;
                }
            }
        }
        else if(type==3)
        {
            //����Ա�����֤
        while(ifs>>fname &&ifs>>fpwd)
            {
             if(fname==name&&fpwd==pwd)
                {
                    cout<< "����Ա��¼�ɹ�"<<endl;
                    system("pause");
                    system("cls");
                    person=new manager(name,pwd);
                    //�������Ա��ݵ��Ӳ˵�
                    managermenu(person);
                    return;
                }
            }
        }
        cout<< "��֤��¼ʧ��!"<<endl;
        system("pause");
        system("cls");
        return;
    }
int main()
{
    int select=0;
    while(true)
    {
        cout<< "�������������"<<endl;
        cout<< "\t\t------------------------\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       1.ѧ������      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       2.��ʦ          |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       3.����Ա        |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       0.�˳�          |\n";
        cout<< "\t\t------------------------\n";
        cin>>select;
        switch(select)
        {
        case 1:
            loginin(STUDENT_FILE,1);
            break;
        case 2:
            loginin(TEACHER_FILE,2);
            break;
        case 3:
            loginin(ADMIN_FILE,3);
            break;
        case 0:
            cout<< "��ӭ��һ��ʹ��"<<endl;
            system("pause");
            return 0;
            break;
        default:
            cout<< "������������������"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    system("cls");
}
