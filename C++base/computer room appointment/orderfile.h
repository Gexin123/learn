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
    //����ԤԼ��¼
    void updateorder();
    //��¼ԤԼ����
    int m_size;
    //��¼����ԤԼ��Ϣ��������key����¼������value��������Ϣ
    map<int,map<string,string> >m_orderdate;

};
