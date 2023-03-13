#pragma once
#include <iostream>
using namespace std;
//身份抽象类
class identity
{
public:
   //纯虚函数
   virtual void opermenu()=0;
   string m_name;
   string m_pwd;
};
