//��ͨԱ���ļ�
#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//����������ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "worker.h"

class employee:public worker//�̳�worker��
{
public:
    employee(int id,string name,int depart);
     virtual void showinfo();
    //��ȡ��λ����
    virtual string getdepart();
};
