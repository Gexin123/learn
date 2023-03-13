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
    void speechdraw();//��ǩ����
    void speechcontest();//����
    void showscore();
    void saverecord();
    void lordrecord();
    void showrecord();//��ʾ����ļ�¼
    bool fileisempty;
    map<int,vector<string>>m_record;//��������¼������
    vector<int>v1;//�����һ��ѡ�ֵı������
    vector<int>v2;//��һ�ֽ�����
    vector<int>victory;//ǰ����
    map<int,speaker>m_speaker;
    int m_index;
};
