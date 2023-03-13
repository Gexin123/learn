//普通员工文件
#pragma once//防止头文件重复包含
#include <iostream>//输入输出流文件
using namespace std;//使用标准命名空间
#include "worker.h"

class employee:public worker//继承worker类
{
public:
    employee(int id,string name,int depart);
     virtual void showinfo();
    //获取岗位名称
    virtual string getdepart();
};
