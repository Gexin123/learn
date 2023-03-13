#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include <fstream>
#include "globalflie.h"
#include <stdlib.h>
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerroom.h"

//����Ա
class manager:public identity
{
public:
    //Ĭ�Ϲ���
    manager();
    //�вι���
    manager(string name,string pwd);
    //�˵�����
    virtual void opermenu();
    //����˺�
    void addperson();
    //�鿴�˺�
    void showperson();
    //�鿴������Ϣ
    void showcomputer();
    //�������ԤԼ��¼
    void cleanfile();
    //��ʼ������
    void initvector();
    //����ظ�
    bool checkrepeat(int id,int type);
    vector<student>vstu;
    vector<teacher>vtea;
    vector<computerroom>vcom;

};
