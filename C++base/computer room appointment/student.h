#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include <vector>
#include "computerroom.h"
#include <fstream>
#include "globalflie.h"
#include <stdlib.h>
#include "orderfile.h"
//ѧ����
class student:public identity
{
public:
    //Ĭ�Ϲ���
    student();
    //�вι���
    student(int id,string name,string pwd);
    //�˵�����
    virtual void opermenu();
    //����ԤԼ
    void applyorder();
    //�鿴����ԤԼ
    void showmyorder();
    //�鿴���е�ԤԼ
    void showallorder();
    //ȡ��ԤԼ
    void cancelorder();
    int m_id;
    vector<computerroom>vcom;

};
