#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//����������ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include<fstream>
#define FILENAME "empfile.txt"
class workermanager
{
public:
    workermanager();
    void showmenu();
    void exitsystem();
    int m_empnum;//��¼ְ������
    worker **m_emparray;//ְ������ָ��
    void add_emp();//���ְ��
    void save();//�����ļ�
    bool m_fileisempty;//�ж��ļ��Ƿ�Ϊ��
    int get_empnum();//ͳ���ļ��е�����
    void init_emp();//��ʼ��Ա��
    void show_emp();//��ʾԱ��
    void del_emp();//ɾ��ְ��
    int isexist(int id);//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������λ�ã��������򷵻�-1
    void mod_emp();//�޸�ְ����Ϣ
    void find_emp();//����ְ��
    void sort_emp();//����
    void clean_file();//����ļ�
    ~workermanager();
};
