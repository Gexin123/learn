#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include "globalflie.h"
#include <vector>
#include "orderfile.h"
#include <stdlib.h>
//学生类
class teacher:public identity
{
public:
    //默认构造
    teacher();
    //有参构造
    teacher(int empid,string name,string pwd);
    //菜单界面
    virtual void opermenu();
    //查看所有的预约
    void showallorder();
    //审核预约
    void validorder();
    int m_empid;

};
