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


//进入学生的子菜单
void studentmenu(identity* &stud)
{
    while(true)
    {
        //调用学生子菜单
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
            cout<< "注销成功"<<endl;
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
        //调用管理员子菜单
        teach->opermenu();
        teacher* tea=(teacher*)teach;
        int select=0;
        cin>>select;
        if(select==1)//添加账号
        {
            tea->showallorder();
        }
        else if(select==2)//查看账号
        {
            tea->validorder();
        }
        else
        {
            delete teach;
            cout<< "注销成功"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
//进入管理员子菜单页面
void managermenu(identity*&manag)
{
    while(true)
    {
        //调用管理员子菜单
        manag->opermenu();
        manager* man=(manager*)manag;
        int select=0;
        cin>>select;
        if(select==1)//添加账号
        {
            man->addperson();
        }
        else if(select==2)//查看账号
        {
            man->showperson();
        }
        else if(select==3)//查看机房信息
        {
              man->showcomputer();
        }
        else if(select==4)//清空预约
        {
            man->cleanfile();
        }
        else
        {
            delete manag;
            cout<< "注销成功"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }

}
//登录功能 参数1 操作文件名 参数2 操作身份类型
    void loginin(const string& filename,int type)
    {
        identity *person=NULL;
        //读文件
        ifstream ifs;
        ifs.open(filename.c_str(),ios::in);
        if(!ifs.is_open())
        {
            cout<< "文件不存在"<<endl;
            ifs.close();
            return;
        }
        int id=0;
        string name;
        string pwd;
        //判断身份
        if(type==1)
        {
            cout<< "请输入你的学号："<<endl;
            cin>>id;
        }
        else if(type==2)
        {
            cout<< " 请输入您的职工号："<<endl;
            cin>>id;
        }
        cout<< "请输入用户名："<<endl;
        cin>>name;
        cout<< "请输入密码："<<endl;
        cin>>pwd;
        int fid=0;
        string fname;
        string fpwd;
        if(type==1)
        {
            //学生身份验证
            while(ifs>>fid &&ifs>>fname &&ifs>>fpwd)
            {
             if(fid==id&&fname==name&&fpwd==pwd)
                {
                    cout<< "学生登录成功"<<endl;
                    system("pause");
                    system("cls");
                    person=new student(id,name,pwd);
                    //进入学生身份的子菜单
                    studentmenu(person);
                    return;

                }
            }
        }
        else if(type==2)
        {
            //教师身份验证
        while(ifs>>fid &&ifs>>fname &&ifs>>fpwd)
            {
             if(fid==id&&fname==name&&fpwd==pwd)
                {
                    cout<< "教师登录成功"<<endl;
                    system("pause");
                    system("cls");
                    person=new teacher(id,name,pwd);
                    //进入教师身份的子菜单
                    teachermenu(person);
                    return;
                }
            }
        }
        else if(type==3)
        {
            //管理员身份验证
        while(ifs>>fname &&ifs>>fpwd)
            {
             if(fname==name&&fpwd==pwd)
                {
                    cout<< "管理员登录成功"<<endl;
                    system("pause");
                    system("cls");
                    person=new manager(name,pwd);
                    //进入管理员身份的子菜单
                    managermenu(person);
                    return;
                }
            }
        }
        cout<< "验证登录失败!"<<endl;
        system("pause");
        system("cls");
        return;
    }
int main()
{
    int select=0;
    while(true)
    {
        cout<< "请输入您的身份"<<endl;
        cout<< "\t\t------------------------\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       1.学生代表      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       2.老师          |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       3.管理员        |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       0.退出          |\n";
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
            cout<< "欢迎下一次使用"<<endl;
            system("pause");
            return 0;
            break;
        default:
            cout<< "输入有误，请重新输入"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    system("cls");
}
