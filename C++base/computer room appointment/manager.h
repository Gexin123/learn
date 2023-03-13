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

//管理员
class manager:public identity
{
public:
    //默认构造
    manager();
    //有参构造
    manager(string name,string pwd);
    //菜单界面
    virtual void opermenu();
    //添加账号
    void addperson();
    //查看账号
    void showperson();
    //查看机房信息
    void showcomputer();
    //清空所有预约记录
    void cleanfile();
    //初始化容器
    void initvector();
    //检测重复
    bool checkrepeat(int id,int type);
    vector<student>vstu;
    vector<teacher>vtea;
    vector<computerroom>vcom;

};
