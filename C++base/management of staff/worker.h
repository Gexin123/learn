#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//����������ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include <string.h>
class worker//ְ��������
{
public:
    //��ʾ������Ϣ
    virtual void showinfo()=0;
    //��ȡ��λ����
    virtual string getdepart()=0;
    int m_id;
    string m_name;
    int m_depart;
};
