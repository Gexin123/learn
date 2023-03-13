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
//学生类
class student:public identity
{
public:
    //默认构造
    student();
    //有参构造
    student(int id,string name,string pwd);
    //菜单界面
    virtual void opermenu();
    //申请预约
    void applyorder();
    //查看自身预约
    void showmyorder();
    //查看所有的预约
    void showallorder();
    //取消预约
    void cancelorder();
    int m_id;
    vector<computerroom>vcom;

};
