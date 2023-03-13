#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include<algorithm>
#include <deque>
#include <functional>
#include<numeric>
#include<string>
#include<fstream>
class speechmanager
{
public:
    speechmanager();
    void show_menu();
    void exitsystem();
    ~speechmanager();
    void initspeech();
    void creatspeaker();
    void startspeech();
    void speechdraw();//抽签函数
    void speechcontest();//比赛
    void showscore();
    void saverecord();
    void lordrecord();
    void showrecord();//显示往届的记录
    bool fileisempty;
    map<int,vector<string>>m_record;//存放往届记录的容器
    vector<int>v1;//保存第一轮选手的编号容器
    vector<int>v2;//第一轮晋级的
    vector<int>victory;//前三名
    map<int,speaker>m_speaker;
    int m_index;
};
