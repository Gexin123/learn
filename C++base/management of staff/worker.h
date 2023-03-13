#pragma once//防止头文件重复包含
#include <iostream>//输入输出流文件
using namespace std;//使用标准命名空间
#include <string.h>
class worker//职工抽象类
{
public:
    //显示个人信息
    virtual void showinfo()=0;
    //获取岗位名称
    virtual string getdepart()=0;
    int m_id;
    string m_name;
    int m_depart;
};
