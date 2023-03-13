#include "workermanger.h"
#include <stdlib.h>
workermanager::workermanager()
{
    //1、文件不存在
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open())
    {
        cout<< "文件不存在"<<endl;
        this->m_empnum=0;
        this->m_emparray=NULL;
        this->m_fileisempty=true;
        ifs.close();
        return;
    }
    //2、文件存在但是为空
    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
         cout<< "文件为空"<<endl;
        this->m_empnum=0;
        this->m_emparray=NULL;
        this->m_fileisempty=true;
        ifs.close();
        return;
    }
    //3、文件存在并且有数据
    int num=this->get_empnum();
    cout<< "职工的人数为"<<num<<endl;
    this->m_empnum=num;
    this->m_fileisempty=false;

    this->m_emparray=new worker*[this->m_empnum];//开辟空间
    this->init_emp();

}
void workermanager:: showmenu()
{
    cout<< "欢迎使用职工系统"<<endl;
    cout<< "0、退出"<<endl;
    cout<< "1、增加职工信息"<<endl;
    cout<< "2、显示"<<endl;
    cout<< "3、删除"<<endl;
    cout<< "4、修改"<<endl;
    cout<< "5、查找"<<endl;
    cout<< "6、排序"<<endl;
    cout<< "7、清空"<<endl;
}
void workermanager::exitsystem()
{
    cout<< "欢迎下次使用"<<endl;
    system("pause");
    exit(0);//退出程序
}
void workermanager::add_emp()
{
    cout<< "请输入添加职工的数量"<<endl;
    int addnum=0;
    cin>>addnum;
    if(addnum>0)
    {
        //添加，计算添加新空间的大小
        int newsize=this->m_empnum+addnum;
        worker **newspace=new worker*[newsize];//开辟新空间
        //将原来空间下的数据，拷贝到新空间下面
        if(this->m_emparray!=NULL)
        {
            for(int i=0;i<this->m_empnum;i++)
                newspace[i]=this->m_emparray[i];
        }
        //批量添加新数据
        for(int i=0;i<addnum;i++)
        {
            int id;
            string name;
            int dselect;
            cout<< "请输入第"<<i+1<< "个新职员的编号"<<endl;
            cin>>id;
            cout<< "请输入第"<<i+1<< "个新职员的姓名"<<endl;
            cin>>name;
            cout<< "请选择该职员的岗位"<<endl;
            cout<< "1、普通职工"<<endl;
            cout<< "2、经理"<<endl;
            cout<< "3、老板"<<endl;
            cin>>dselect;
            worker *wor=NULL;
            switch(dselect)
            {
            case 1:
                wor=new employee(id,name,1);
                break;
            case 2:
                wor=new manager(id,name,2);
                break;
            case 3:
                wor=new boss(id,name,3);
                break;
            }
            //创建职工职责，保存到数组中
            newspace[this->m_empnum+i]=wor;
        }
        //释放原有的空间
        delete[]this->m_emparray;
        //更改新空间的指向
        this->m_emparray=newspace;
        //更新新的职工人数
        this->m_empnum=newsize;
        //更新职工不为空的标志
        this->m_fileisempty=false;
        cout<< "成功添加"<<addnum<< "名新职工"<<endl;
        this->save();//保存数据到文件中

    }
    else
    {
        cout<< "输入数据有误"<<endl;

    }
    system("pause");
    system("cls");
}


void workermanager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for(int i=0;i<this->m_empnum;i++)
    {
        ofs<<this->m_emparray[i]->m_id<< " "
        <<this->m_emparray[i]->m_name<< " "
        <<this->m_emparray[i]->m_depart<<endl;
    }
    ofs.close();
}
int workermanager::get_empnum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int depart;
    int num=0;
    while(ifs>>id&&ifs>>name&&ifs>>depart)
    {
        num++;//统计人数
    }
    return num;
}
void workermanager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int depart;
    int index=0;
    while(ifs>>id&&ifs>>name&&ifs>>depart)
    {
        worker *wor=NULL;
        if(depart==1)//普通职工
        {
            wor=new employee(id,name,depart);
        }
        else if(depart==2)
            {
               wor=new manager(id,name,depart);
            }
            else
            {
                wor=new boss(id,name,depart);
            }
            this->m_emparray[index]=wor;
            index++;
    }
    ifs.close();
}

void workermanager::show_emp()
{
    if(this->m_fileisempty)
    {
        cout<< "文件不存在或记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<m_empnum;i++)
        {
            this->m_emparray[i]->showinfo();
    }
        }
         system("pause");
         system("cls");
}


void workermanager::del_emp()
{
    if(!this->m_fileisempty)
    {
        cout<< "文件不存在"<<endl;
    }
    else
    {
        cout<< "请输入想要删除的职工编号"<<endl;
        int id=0;
        cin>>id;
        int index=this->isexist(id);
        if(index!=-1)
        {
            for(int i=0;i<this->m_empnum-1;i++)
            {
                //数据前移
                this->m_emparray[i]=this->m_emparray[i+1];
            }
            this->m_empnum--;
            //同步更新到文件中
            this->save();
            cout<< "删除成功"<<endl;
        }
        else
        {
            cout<< "未找到该职工"<<endl;
        }
    }
}
int workermanager::isexist(int id)
{
    int index=-1;
    for(int i=0;i<this->m_empnum;i++)
    {
        if(this->m_emparray[i]->m_id==id)
            index=i;
        break;
    }
}

void workermanager::mod_emp()
{
    if(this->m_fileisempty)
    {
        cout<< "文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<< "请输入修改职工的编号： "<<endl;
        int id;
        cin>>id;
        int ret=this->isexist(id);
        if(ret!=-1)
        {
            delete this->m_emparray[ret];
            int newid=0;
            string newname="";
            int newdepart=0;
            cout<< "查到"<<id<< "号职工，请输入新职工号："<<endl;
            cin>>newid;
            cout<< "请输入新名字"<<endl;
            cin>>newname;
            cout<< "请输入岗位"<<endl;
            cin>>newdepart;
            worker *wor=NULL;
            switch(newdepart)
            {
            case 1:
                wor=new employee(newid,newname,newdepart);
                break;
            case 2:
                wor=new manager(newid,newname,newdepart);
                break;
            case 3:
                wor=new boss(newid,newname,newdepart);
                break;
            default:
                break;
            }
            this->m_emparray[ret]=wor;
            cout<< "修改成功"<<endl;
        }
        else
        {
            cout<< "查无此人"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void workermanager::find_emp()
{
    if(this->m_fileisempty)
    {
        cout<< "kong"<<endl;
    }
    else
    {
        cout<< "请输入查找方式"<<endl;
        cout<< "1、按照编号的方式查找"<<endl;
        cout<< "2、按照姓名的方式查找"<<endl;
        int select=0;
        cin>>select;
        if(select==1)
        {
            int id;
            cout<< "请输入查找的职工编号"<<endl;
            cin>>id;
            int ret=isexist(id);
            if(ret!=-1)
            {
                cout<< "查找成功！该职工的信息如下："<<endl;
                this->m_emparray[ret]->showinfo();
            }
            else
            {
                cout<< "查无此人"<<endl;
            }
        }
        else if(select==2)
        {
            string name;
            cout<< "请输入查找的姓名"<<endl;
            cin>>name;
            bool flag=false;
            for(int i=0;i<m_empnum;i++)
            {
                if(this->m_emparray[i]->m_name==name)
                {
                    cout<< "查找成功，职工编号为"
                    <<this->m_emparray[i]->m_id;
                    flag=true;
                    this->m_emparray[i]->showinfo();
                }
            }
            if(flag==false)
            {
                cout<< "查找失败，查无此人"<<endl;
            }
        }
        else
        {
            cout<< "输入选项有误"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void workermanager::sort_emp()
{
    if(this->m_fileisempty)
    {
        cout<< "kong"<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<< "请选择排序方式"<<endl;
        cout<< "1、按照职工号升序"<<endl;
        cout<< "2、按照职工号降序"<<endl;
        int select=0;
        cin>>select;
        for(int i=0;i<m_empnum;i++)
        {
            int minormax=i;
            for(int j=i+1;j<this->m_empnum;j++)
            {
                if(select==1)
            {
                if(this->m_emparray[minormax]->m_id>this->m_emparray[j]->m_id)
                {
                    minormax=j;
                }
            }
            else
            {
                if(this->m_emparray[minormax]->m_id<this->m_emparray[j]->m_id)
                {
                    minormax=j;
                }
            }
            }
            //判断一开始认定的最小值或最大值是不是计算的最小值或最大值，如果不是交换数据
            if(i!=minormax)
            {
                worker*temp=this->m_emparray[i];
                this->m_emparray[i]=this->m_emparray[minormax];
                this->m_emparray[minormax]=temp;
            }
        }
        cout<< "排序成功！排序后的结果为："<<endl;
        this->save();
        this->show_emp();
    }
}

void workermanager::clean_file()
{
    cout<< "确定清空？"<<endl;
    cout<< "1 sure"<<endl;
    cout<< "2 return"<<endl;
    int select=0;
    cin>>select;
    if(select==1)
    {
        ofstream ofs(FILENAME,ios::trunc);//删除文件后重新创建
        ofs.close();
        if(this->m_emparray!=NULL)
    {
        for(int i=0;i<this->m_empnum;i++)
        {
            delete this->m_emparray[i];
        this->m_emparray[i]=NULL;
        }
        delete [] this->m_emparray;
        this->m_emparray=NULL;
        this->m_empnum=0;
        this->m_fileisempty=true;
    }
    }
}

workermanager::~workermanager()
{
    if(this->m_emparray!=NULL)
    {
        delete [] this->m_emparray;
        this->m_emparray=NULL;
    }

}

