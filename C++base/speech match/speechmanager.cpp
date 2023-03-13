#include "speechmanager.h"

speechmanager::speechmanager()
{
    this->initspeech();
    this->creatspeaker();
    this->lordrecord();
}
void speechmanager::show_menu()
{
    cout<< "��ӭ�μ��ݽ�����"<<endl;
    cout<< "1����ʼ�ݽ�����"<<endl;
    cout<< "2���鿴�����¼"<<endl;
    cout<< "3����ձ�����¼"<<endl;
    cout<< "0���˳���������"<<endl;
}
void speechmanager::exitsystem()
{
    cout<< "��ӭ�´�ʹ��"<<endl;
    system("pause");
    exit(0);
}
void speechmanager::initspeech()
{
    this->v1.clear();
    this->v2.clear();
    this->victory.clear();
    this->m_speaker.clear();
    this->m_index=1;
    this->m_record.clear();
}
void speechmanager::creatspeaker()
{
    string nameseed="ABCDEFGHIJKL";
    for(int i=0;i<nameseed.size();i++)
    {
        string name="ѡ��";
        name+=nameseed[i];
        speaker sp;
        sp.m_name=name;
        for(int j=0;j<2;j++)
        {
            sp.m_score[j]=0;
        }
        this->v1.push_back(i+10001);
        this->m_speaker.insert(make_pair(i+10001,sp));
    }
}
void speechmanager::startspeech()
{
    //��һ�ֿ�ʼ����
    //��ǩ
    this->speechdraw();
    //����
    this->speechcontest();
    //��ʾ���
    this->showscore();
    //�ڶ��ֱ�����ʼ
    this->m_index++;
    //��ǩ
    this->speechdraw();
     //����
    this->speechcontest();
    //��ʾ���
    this->showscore();
    //�����¼���ļ���ȥ
    this->saverecord();
    //���ñ�������ȡ��¼
    this->initspeech();
    this->creatspeaker();
    this->lordrecord();
    cout<< "����������"<<endl;
    system("pause");
    system("cls");
}
void speechmanager::speechdraw()
{
    cout<< "��"<<this->m_index<< "�ֱ���ѡ�����ڳ�ǩ"<<endl;
    cout<< "��ǩ���˳������"<<endl;
    if(this->m_index==1)
    {
        random_shuffle(v1.begin(),v1.end());
        for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
        {
            cout<<*it<< " ";
        }
        cout<<endl;
    }
    else
    {
        random_shuffle(v2.begin(),v2.end());
        for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
        {
            cout<<*it<< " ";
        }
        cout<<endl;
    }
}
void speechmanager::speechcontest()
{
    cout<< "-----------��"<<this->m_index<< "�ֱ�����ʽ��ʼ------------"<<endl;
    //׼����ʱ���������С��ĳɼ�
    multimap<double,int,greater<double>>groupscore;
    int num=0;
    vector<int>v_src;//������Ա����
    if(this->m_index==1)
    {
        v_src=v1;
    }
    else
    {
        v_src=v2;
    }
    //��������ѡ�ֽ��б���
    for(vector<int>::iterator it=v_src.begin();it!=v_src.end();it++)
    {
        num++;//6����һ��
        //��ί���
        deque<double>d;
        for(int i=0;i<10;i++)
        {
            double score=(rand()%401+600)/10.f
            cout<<score<< " ";
            d.push_back(score);
        }
        sort(d.begin(),d.end(),greater<double>());//����
        d.pop_front();//ȥ����߷֣�
        d.pop_back();//ȥ����ͷ�
        double sum=accumulate(d.begin(),d.end(),0.of);
        double avg=sum/(double)d.size();
        this->m_speaker[*it].m_score[this->m_index-1]=avg;//��ƽ���ַ��뵽map������
        groupscore.insert(make_pair(avg,*it));
        //ÿ6����ȡ��ǰ����
        if(num%6==0)
        {
            cout<, "��"<<num/6<< "С���������"<<endl;
            for(multimap<double,int,greater<double>>::iterator it=groupscore.begin();it!=groupscore.end();it++)
                cout<< "���"<<it->second<< "����"<<this->m_speaker[it->second].m_name<< "�ɼ�"
                <<this->m_speaker[it->second].m_score[this->m_index-1]<<endl;
        }
        //ȡ��ǰ����
        for(multimap<double,int,greater<double>>::iterator it=groupscore.begin();it!=groupscore.end()&&cout<3;it++,cout++)
        {
            if(this->m_index==1)
            {
                v2.push_back((*it).second);
            }
            else
            {
                victory.push_back((*it).second);
            }
        }
        groupscore.clear();
    }
    cout<< "------------��"<<this->m_index<< "�ֱ�������-----------"<<endl;
    system("pause");
}

void speechmanager::showscore()
{
    cout<< "-------��"<<this->m_index<< "�ֵĽ���ѡ����Ϣ���£�-----------"
    vector<int>v;
    if(this->m_index==1)
    {
        v=v2;
    }
    else
    {
        v=victory;
    }
    for(vector<int>:;iterator it=v.begin();it!=v.end();it++)
    {
        cout<< "ѡ�ֱ��"<<*it<< "����:"<<this->m_speaker[*it].m_name<< "�ɼ�"
                <<this->m_speaker[*it].m_score[this->m_index-1]<<endl;
    }
    cout<<endl;
    system("pause")
    system("cls");
    this->showmenu();
}
//����ȫ����ǰ����
void speechmanager::savescore()
{
    ofstream ofs;
    ofs.open("speech.csv",ios::out|ios::app);
    for(vector<int>::iterator it=victory.begin();it!=victory.end();it++)
    {
        ofs<<*it<< ","<<this->m_speaker[*it].m_score[1]<< ",";
    }
    ofs<<endl;
    ofs.close();
    cout<< "��¼�Ѿ��������"<<endl;
    this->fileisempty=false;
}

void speechmanager::lordrecord()
{
    ifstream ifs("speech.csv",ios::in);
    {
        if(!ifs.is_open())
        {
            this->fileisempty=true;
            cout<< "�ļ�������"<<endl;
            ifs.close();
            return;
        }
        char ch;
        ifs>>ch;
        if(ifs.eof())
        {
            cout<< "�ļ�Ϊ��"<<endl;
            this->fileisempty=true;
            ifs.close();
            return;
        }
        //
        this->fileisempty=false;
        ifs.putback(ch);
        string data;
        while(ifs>>data)
        {
            //10002,86,675,1009
            vector<string>v;
            int pos=-1;
            int start=0;
            while(true)
            {
                pos=data.find(",",start);
            if(pos==-1)
            {
                break;
            }
            string temp=data.substr(start,pos-start);
            v.push_back(temp);
            start=pos+1;
            }
            this->m_record.insert(make_pair(index,v));
            index++;
        }
        ifs.close();

    }
}

void speechmanager::showrecord()
{
    if(this->fileisempty)
    {
        cout<< "�ļ�Ϊ�ջ��߲�����"<<endl;
    }
    else
    {
        for(int i=0;i<this->m_record.size();i++)
    {
        cout<< "��"<<i+1<< "��"
        << "�ھ����"<<this->m_record[i][0]<< "�÷�"<<this->m_record[i][1]<< " "
        << "�Ǿ����"<<this->m_record[i][1]<< "�÷�"<<this->m_record[i][2]<< " "
        << "�������"<<this->m_record[i][2]<< "�÷�"<<this->m_record[i][5]<< " "
    }
    }
    system("pause");
    system("cls");
}
speechmanager::~speechmanager()
{

}

















