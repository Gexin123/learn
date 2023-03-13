#pragma once
#include<iostream>
using namespace std;
#include "globalflie.h"
#include <fstream>
#include <map>
#include <string>
class orderfile
{
public:
    orderfile();
    //更新预约记录
    void updateorder();
    //记录预约条数
    int m_size;
    //记录所有预约信息的容器，key：记录条数。value：具体信息
    map<int,map<string,string> >m_orderdate;

};
