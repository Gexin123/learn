#include "manager.h"

manager::manager()
{

}
manager::manager(string name,string pwd)
{
    this->m_name=name;
    this->m_pwd=pwd;
    this->initvector();
    //初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);
    computerroom c;
    while(ifs>>c.m_comid&&ifs>>c.m_maxnum)
    {
        vcom.push_back(c);
    }
    cout<< "当前机房的数量为："<<vcom.size()<<endl;
    ifs.close();
}
void manager::opermenu()
{
        cout<< "欢迎管理员："<<this->m_name<< "登录!"<<endl;
        cout<< "\t\t------------------------\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       1.添加账号      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       2.查看账号      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       3.查看机房      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       4.清空预约      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       0.注销登录      |\n";
        cout<< "\t\t------------------------\n";
}
void manager::addperson()
{
    cout<< "请输入添加账号的类型"<<endl;
    cout<< "1、添加学生"<<endl;
    cout<< "2、添加老师"<<endl;
    string filename;
    string tip;
    string errotip;
    ofstream ofs;
    int select=0;
    cin>>select;
    if(select==1)
    {
        filename=STUDENT_FILE;
        tip="请输入学号：";
        errotip="学号重复！";
    }
    else
    {
        filename=TEACHER_FILE;
        tip="请输入职工编号：";
        errotip="职工号重复!";
    }
    //利用追加的方式写文件
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
    cout<< "请输入姓名："<<endl;
    cin>>name;
    cout<< "请输入密码："<<endl;
    cin>>pwd;
    //向文件中添加数据
    ofs<<id<< " "<<name<< " "<<pwd<< " "<<endl;
    cout<< "添加成功"<<endl;
    system("pause");
    system("cls");
    ofs.close();
    //调用初始化容器接口，重新获取文件中的数据
    this->initvector();

}
void printstudent(student &s)
{
    cout<< "学号："<<s.m_id<< "姓名："<<s.m_name<<endl;
}
void printteacher(teacher &s)
{
    cout<< "职工号："<<s.m_empid<< "姓名："<<s.m_name<<endl;
}
void manager::showperson()
{
    cout<< "请选择查看内容"<<endl;
    cout<< "1、学生"<<endl;
    cout<< "2、老师"<<endl;
    int select=0;
    cin>>select;
    if(select==1)
    {
        cout<< "所有学生信息如下："<<endl;
        for_each(vstu.begin(),vstu.end(),printstudent);
    }
    else
    {
        cout<< "所有老师信息如下："<<endl;
        for_each(vtea.begin(),vtea.end(),printteacher);
    }
    system("pause");
    system("cls");

}
void manager::showcomputer()
{
    cout<< "机房信息如下："<<endl;
    for(vector<computerroom>::iterator it=vcom.begin();it!=vcom.end();it++)
    {
        cout<< "机房编号为："<<it->m_comid<< "机房的最大容量："<<it->m_maxnum<<endl;
    }
    system("pause");
    system("cls");
}
void manager::cleanfile()
{
    ofstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();
    cout<< "清空成功！"<<endl;
    system("pause");
    system("cls");
}
void manager::initvector()
{
    vstu.clear();
    vtea.clear();
    //读取信息：学生
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if(!ifs.is_open())
    {
        cout<< "文件读取失败"<<endl;
        return;
    }
    student s;
    while(ifs>>s.m_id&&ifs>>s.m_name&&ifs>>s.m_pwd)
    {
        vstu.push_back(s);
    }
    cout<< "当前学生的数量为："<<vstu.size()<<endl;
    ifs.close();
    //读取信息: 老师
    ifs.open(TEACHER_FILE,ios::in);
    teacher t;
    while(ifs>>t.m_empid&&ifs>>t.m_name&&ifs>>t.m_pwd)
    {
        vtea.push_back(t);
    }
    cout<< "当前老师的数量为："<<vtea.size()<<endl;
    ifs.close();
}
bool manager::checkrepeat(int id,int type)
{
    if(type==1)
    {
        //检测学生
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













