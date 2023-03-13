#include <iostream>
using namespace std;
#include <stdlib.h>
#include "workermanger.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{
 workermanager wm;
int choice=0;
while(true)
{
    wm.showmenu();
    cout<< "请输入您的选择"<<endl;
    cin>>choice;
      switch(choice)
    {
    case 0:
        wm.exitsystem();
        break;//退出系统
    case 1://增加
        wm.add_emp();
        break;
    case 2://显示
        wm.show_emp();
        break;
    case 3://删除
        {
            wm.del_emp();
        break;
        }
    case 4://修改
        wm.mod_emp();
        break;
    case 5://查找
        wm.find_emp();
        break;
    case 6://排序
        wm.sort_emp();
    case 7://清空
        wm.clean_file();
        return 0;
        break;
    default:
        break;
    }
}
 //调用成员函数

 system("pause");
 return 0;
}
