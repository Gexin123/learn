#include "workermanger.h"
#include <stdlib.h>
workermanager::workermanager()
{
    //1���ļ�������
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open())
    {
        cout<< "�ļ�������"<<endl;
        this->m_empnum=0;
        this->m_emparray=NULL;
        this->m_fileisempty=true;
        ifs.close();
        return;
    }
    //2���ļ����ڵ���Ϊ��
    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
         cout<< "�ļ�Ϊ��"<<endl;
        this->m_empnum=0;
        this->m_emparray=NULL;
        this->m_fileisempty=true;
        ifs.close();
        return;
    }
    //3���ļ����ڲ���������
    int num=this->get_empnum();
    cout<< "ְ��������Ϊ"<<num<<endl;
    this->m_empnum=num;
    this->m_fileisempty=false;

    this->m_emparray=new worker*[this->m_empnum];//���ٿռ�
    this->init_emp();

}
void workermanager:: showmenu()
{
    cout<< "��ӭʹ��ְ��ϵͳ"<<endl;
    cout<< "0���˳�"<<endl;
    cout<< "1������ְ����Ϣ"<<endl;
    cout<< "2����ʾ"<<endl;
    cout<< "3��ɾ��"<<endl;
    cout<< "4���޸�"<<endl;
    cout<< "5������"<<endl;
    cout<< "6������"<<endl;
    cout<< "7�����"<<endl;
}
void workermanager::exitsystem()
{
    cout<< "��ӭ�´�ʹ��"<<endl;
    system("pause");
    exit(0);//�˳�����
}
void workermanager::add_emp()
{
    cout<< "���������ְ��������"<<endl;
    int addnum=0;
    cin>>addnum;
    if(addnum>0)
    {
        //��ӣ���������¿ռ�Ĵ�С
        int newsize=this->m_empnum+addnum;
        worker **newspace=new worker*[newsize];//�����¿ռ�
        //��ԭ���ռ��µ����ݣ��������¿ռ�����
        if(this->m_emparray!=NULL)
        {
            for(int i=0;i<this->m_empnum;i++)
                newspace[i]=this->m_emparray[i];
        }
        //�������������
        for(int i=0;i<addnum;i++)
        {
            int id;
            string name;
            int dselect;
            cout<< "�������"<<i+1<< "����ְԱ�ı��"<<endl;
            cin>>id;
            cout<< "�������"<<i+1<< "����ְԱ������"<<endl;
            cin>>name;
            cout<< "��ѡ���ְԱ�ĸ�λ"<<endl;
            cout<< "1����ְͨ��"<<endl;
            cout<< "2������"<<endl;
            cout<< "3���ϰ�"<<endl;
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
            //����ְ��ְ�𣬱��浽������
            newspace[this->m_empnum+i]=wor;
        }
        //�ͷ�ԭ�еĿռ�
        delete[]this->m_emparray;
        //�����¿ռ��ָ��
        this->m_emparray=newspace;
        //�����µ�ְ������
        this->m_empnum=newsize;
        //����ְ����Ϊ�յı�־
        this->m_fileisempty=false;
        cout<< "�ɹ����"<<addnum<< "����ְ��"<<endl;
        this->save();//�������ݵ��ļ���

    }
    else
    {
        cout<< "������������"<<endl;

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
        num++;//ͳ������
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
        if(depart==1)//��ְͨ��
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
        cout<< "�ļ������ڻ��¼Ϊ��"<<endl;
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
        cout<< "�ļ�������"<<endl;
    }
    else
    {
        cout<< "��������Ҫɾ����ְ�����"<<endl;
        int id=0;
        cin>>id;
        int index=this->isexist(id);
        if(index!=-1)
        {
            for(int i=0;i<this->m_empnum-1;i++)
            {
                //����ǰ��
                this->m_emparray[i]=this->m_emparray[i+1];
            }
            this->m_empnum--;
            //ͬ�����µ��ļ���
            this->save();
            cout<< "ɾ���ɹ�"<<endl;
        }
        else
        {
            cout<< "δ�ҵ���ְ��"<<endl;
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
        cout<< "�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        cout<< "�������޸�ְ���ı�ţ� "<<endl;
        int id;
        cin>>id;
        int ret=this->isexist(id);
        if(ret!=-1)
        {
            delete this->m_emparray[ret];
            int newid=0;
            string newname="";
            int newdepart=0;
            cout<< "�鵽"<<id<< "��ְ������������ְ���ţ�"<<endl;
            cin>>newid;
            cout<< "������������"<<endl;
            cin>>newname;
            cout<< "�������λ"<<endl;
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
            cout<< "�޸ĳɹ�"<<endl;
        }
        else
        {
            cout<< "���޴���"<<endl;
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
        cout<< "��������ҷ�ʽ"<<endl;
        cout<< "1�����ձ�ŵķ�ʽ����"<<endl;
        cout<< "2�����������ķ�ʽ����"<<endl;
        int select=0;
        cin>>select;
        if(select==1)
        {
            int id;
            cout<< "��������ҵ�ְ�����"<<endl;
            cin>>id;
            int ret=isexist(id);
            if(ret!=-1)
            {
                cout<< "���ҳɹ�����ְ������Ϣ���£�"<<endl;
                this->m_emparray[ret]->showinfo();
            }
            else
            {
                cout<< "���޴���"<<endl;
            }
        }
        else if(select==2)
        {
            string name;
            cout<< "��������ҵ�����"<<endl;
            cin>>name;
            bool flag=false;
            for(int i=0;i<m_empnum;i++)
            {
                if(this->m_emparray[i]->m_name==name)
                {
                    cout<< "���ҳɹ���ְ�����Ϊ"
                    <<this->m_emparray[i]->m_id;
                    flag=true;
                    this->m_emparray[i]->showinfo();
                }
            }
            if(flag==false)
            {
                cout<< "����ʧ�ܣ����޴���"<<endl;
            }
        }
        else
        {
            cout<< "����ѡ������"<<endl;
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
        cout<< "��ѡ������ʽ"<<endl;
        cout<< "1������ְ��������"<<endl;
        cout<< "2������ְ���Ž���"<<endl;
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
            //�ж�һ��ʼ�϶�����Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ��������ǽ�������
            if(i!=minormax)
            {
                worker*temp=this->m_emparray[i];
                this->m_emparray[i]=this->m_emparray[minormax];
                this->m_emparray[minormax]=temp;
            }
        }
        cout<< "����ɹ��������Ľ��Ϊ��"<<endl;
        this->save();
        this->show_emp();
    }
}

void workermanager::clean_file()
{
    cout<< "ȷ����գ�"<<endl;
    cout<< "1 sure"<<endl;
    cout<< "2 return"<<endl;
    int select=0;
    cin>>select;
    if(select==1)
    {
        ofstream ofs(FILENAME,ios::trunc);//ɾ���ļ������´���
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

