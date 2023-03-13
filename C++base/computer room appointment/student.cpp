#include "student.h"


student::student()
{

}
student::student(int id,string name,string pwd)
{
    this->m_id=id;
    this->m_name=name;
    this->m_pwd=pwd;
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
void student::opermenu()
{
        cout<< "欢迎学生代表："<<this->m_name<< "登录!"<<endl;
        cout<< "\t\t------------------------\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       1.申请预约      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       2.查看我的预约  |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       3.查看所有预    |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       4.取消预约      |\n";
        cout<< "\t\t|                       |\n";
        cout<< "\t\t|       0.注销登录      |\n";
        cout<< "\t\t------------------------\n";

}
void student::applyorder()
{
    cout<< "请输入申请预约的时间:"<<endl;
    cout<< "1、周一"<<endl;
    cout<< "2、周二"<<endl;
    cout<< "3、周三"<<endl;
    cout<< "4、周四"<<endl;
    cout<< "5、周五"<<endl;
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
        cout<< "输入有误，请重新输入"<<endl;
    }
    cout<< "请输入申请预约的时间段："<<endl;
    cout<< "1、上午"<<endl;
    cout<< "2、下午"<<endl;
    while(true)
    {
        cin>>interval;
        if(interval>=1&&interval<=2)
        {
            break;
        }
        cout<< "输入有误，请重新输入"<<endl;
    }
    cout<< "请选择机房："<<endl;
    for(int i=0;i<vcom.size();i++)
    {
        cout<<vcom[i].m_comid<< "号机房的容量为："<<vcom[i].m_maxnum<<endl;
    }
    while(true)
    {
        cin>>room;
        if(room>=1&&room<=3)
        {
            break;
        }
        cout<< "输入有误，请重新输入"<<endl;
    }
    cout<< "预约成功！审核中"<<endl;
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
         cout<< "无预约记录！"<<endl;
         system("pause");
         system("cls");
         return;
     }
     for(int i=0;i<of.m_size;i++)
     {
         if(this->m_id==atoi(of.m_orderdate[i]["stuid"].c_str()))
         {
             cout<< "预约日期：周"<<of.m_orderdate[i]["date"];
             cout<< "时间段"<<(of.m_orderdate[i]["inrerval"])=="1" ? "上午" : "下午";
             cout<< "机房号："<<of.m_orderdate[i]["roomid"];
             string status="状态：";
             if(of.m_orderdate[i]["status"]=="1")
             {
                 status+="审核中";
             }
              else if(of.m_orderdate[i]["status"]=="2")
             {
                 status+="预约成功";
             }
             else if(of.m_orderdate[i]["status"]=="-1")
             {
                 status+="预约失败";
             }
             else
             {
                 status+="预约已取消";
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
         cout<< "无预约记录！"<<endl;
         system("pause");
         system("cls");
         return;
     }
     for(int i=0;i<of.m_size;i++)
     {
         cout<<i+1<< "、";
         cout<< "预约日期：周"<<of.m_orderdate[i]["date"];
         cout<< "时间段："<<(of.m_orderdate[i]["inrerval"])=="1" ? "上午" : "下午";
         cout<< "学号："<<of.m_orderdate[i]["stuid"];
         cout<< "姓名："<<of.m_orderdate[i]["stuname"];
         cout<< "机房号："<<of.m_orderdate[i]["roomid"];
         string status="状态：";
             if(of.m_orderdate[i]["status"]=="1")
             {
                 status+="审核中";
             }
             else if(of.m_orderdate[i]["status"]=="2")
             {
                 status+="预约成功";
             }
             else if(of.m_orderdate[i]["status"]=="-1")
             {
                 status+="预约失败";
             }
             else
             {
                 status+="预约已取消";
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
         cout<< "无预约记录！"<<endl;
         system("pause");
         system("cls");
         return;
     }
     cout<< "审核中或预约成功的记录可以取消，请输入取消的记录"<<endl;
     //存放在最大容器中的下标编号
     vector<int>v;
     int index=1;
     for(int i=0;i<of.m_size;i++)
     {
         if(this->m_id==atoi(of.m_orderdate[i]["stuid"].c_str()))
         {
             if(of.m_orderdate[i]["status"]=="1"||of.m_orderdate[i]["status"]=="2")
             {
                 v.push_back(i);
                 cout<<index++<< "、";
                 cout<< "预约日期：周"<<of.m_orderdate[i]["date"];
             cout<< "时间段"<<(of.m_orderdate[i]["inrerval"])=="1" ? "上午" : "下午";
             cout<< "机房号："<<of.m_orderdate[i]["roomid"];
             string status="状态：";
             if(of.m_orderdate[i]["status"]=="1")
             {
                 status+="审核中";
             }
              else if(of.m_orderdate[i]["status"]=="2")
             {
                 status+="预约成功";
             }
             cout<<status<<endl;
             }
         }
     }
     cout<< "请输入取消的记录"<<endl;
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
                 cout<< "已取消预约"<<endl;
                 break;
             }
         }
         cout<< "输入有误，重新输入"<<endl;
     }
    system("pause");
    system("cls");
}

