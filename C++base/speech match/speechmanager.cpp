#include "speechmanager.h"

speechmanager::speechmanager()
{
    this->initspeech();
    this->creatspeaker();
    this->lordrecord();
}
void speechmanager::show_menu()
{
    cout<< "欢迎参加演讲比赛"<<endl;
    cout<< "1、开始演讲比赛"<<endl;
    cout<< "2、查看往届记录"<<endl;
    cout<< "3、清空比赛记录"<<endl;
    cout<< "0、退出比赛程序"<<endl;
}
void speechmanager::exitsystem()
{
    cout<< "欢迎下次使用"<<endl;
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
        string name="选手";
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
    //第一轮开始比赛
    //抽签
    this->speechdraw();
    //比赛
    this->speechcontest();
    //显示结果
    this->showscore();
    //第二轮比赛开始
    this->m_index++;
    //抽签
    this->speechdraw();
     //比赛
    this->speechcontest();
    //显示结果
    this->showscore();
    //保存记录到文件中去
    this->saverecord();
    //重置比赛，获取记录
    this->initspeech();
    this->creatspeaker();
    this->lordrecord();
    cout<< "本届比赛完毕"<<endl;
    system("pause");
    system("cls");
}
void speechmanager::speechdraw()
{
    cout<< "第"<<this->m_index<< "轮比赛选手正在抽签"<<endl;
    cout<< "抽签后的顺序如下"<<endl;
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
    cout<< "-----------第"<<this->m_index<< "轮比赛正式开始------------"<<endl;
    //准备临时容器，存放小组的成绩
    multimap<double,int,greater<double>>groupscore;
    int num=0;
    vector<int>v_src;//比赛人员容器
    if(this->m_index==1)
    {
        v_src=v1;
    }
    else
    {
        v_src=v2;
    }
    //遍历所有选手进行比赛
    for(vector<int>::iterator it=v_src.begin();it!=v_src.end();it++)
    {
        num++;//6个人一组
        //评委打分
        deque<double>d;
        for(int i=0;i<10;i++)
        {
            double score=(rand()%401+600)/10.f
            cout<<score<< " ";
            d.push_back(score);
        }
        sort(d.begin(),d.end(),greater<double>());//排序
        d.pop_front();//去除最高分；
        d.pop_back();//去除最低分
        double sum=accumulate(d.begin(),d.end(),0.of);
        double avg=sum/(double)d.size();
        this->m_speaker[*it].m_score[this->m_index-1]=avg;//将平均分放入到map容器中
        groupscore.insert(make_pair(avg,*it));
        //每6个人取出前三名
        if(num%6==0)
        {
            cout<, "第"<<num/6<< "小组比赛名次"<<endl;
            for(multimap<double,int,greater<double>>::iterator it=groupscore.begin();it!=groupscore.end();it++)
                cout<< "编号"<<it->second<< "姓名"<<this->m_speaker[it->second].m_name<< "成绩"
                <<this->m_speaker[it->second].m_score[this->m_index-1]<<endl;
        }
        //取走前三名
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
    cout<< "------------第"<<this->m_index<< "轮比赛结束-----------"<<endl;
    system("pause");
}

void speechmanager::showscore()
{
    cout<< "-------第"<<this->m_index<< "轮的晋级选手信息如下：-----------"
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
        cout<< "选手编号"<<*it<< "姓名:"<<this->m_speaker[*it].m_name<< "成绩"
                <<this->m_speaker[*it].m_score[this->m_index-1]<<endl;
    }
    cout<<endl;
    system("pause")
    system("cls");
    this->showmenu();
}
//保存全部的前三名
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
    cout<< "记录已经保存好了"<<endl;
    this->fileisempty=false;
}

void speechmanager::lordrecord()
{
    ifstream ifs("speech.csv",ios::in);
    {
        if(!ifs.is_open())
        {
            this->fileisempty=true;
            cout<< "文件不存在"<<endl;
            ifs.close();
            return;
        }
        char ch;
        ifs>>ch;
        if(ifs.eof())
        {
            cout<< "文件为空"<<endl;
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
        cout<< "文件为空或者不存在"<<endl;
    }
    else
    {
        for(int i=0;i<this->m_record.size();i++)
    {
        cout<< "第"<<i+1<< "届"
        << "冠军编号"<<this->m_record[i][0]<< "得分"<<this->m_record[i][1]<< " "
        << "亚军编号"<<this->m_record[i][1]<< "得分"<<this->m_record[i][2]<< " "
        << "季军编号"<<this->m_record[i][2]<< "得分"<<this->m_record[i][5]<< " "
    }
    }
    system("pause");
    system("cls");
}
speechmanager::~speechmanager()
{

}

















