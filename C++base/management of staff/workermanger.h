#pragma once//防止头文件重复包含
#include <iostream>//输入输出流文件
using namespace std;//使用标准命名空间
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
    int m_empnum;//记录职工人数
    worker **m_emparray;//职工数组指针
    void add_emp();//添加职工
    void save();//保存文件
    bool m_fileisempty;//判断文件是否为空
    int get_empnum();//统计文件中的人数
    void init_emp();//初始化员工
    void show_emp();//显示员工
    void del_emp();//删除职工
    int isexist(int id);//判断职工是否存在，如果存在返回职工所在数组的位置，不存在则返回-1
    void mod_emp();//修改职工信息
    void find_emp();//查找职工
    void sort_emp();//排序
    void clean_file();//清空文件
    ~workermanager();
};
