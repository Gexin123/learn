#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include "globalflie.h"
#include <vector>
#include "orderfile.h"
#include <stdlib.h>
//ѧ����
class teacher:public identity
{
public:
    //Ĭ�Ϲ���
    teacher();
    //�вι���
    teacher(int empid,string name,string pwd);
    //�˵�����
    virtual void opermenu();
    //�鿴���е�ԤԼ
    void showallorder();
    //���ԤԼ
    void validorder();
    int m_empid;

};
