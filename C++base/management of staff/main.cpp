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
    cout<< "����������ѡ��"<<endl;
    cin>>choice;
      switch(choice)
    {
    case 0:
        wm.exitsystem();
        break;//�˳�ϵͳ
    case 1://����
        wm.add_emp();
        break;
    case 2://��ʾ
        wm.show_emp();
        break;
    case 3://ɾ��
        {
            wm.del_emp();
        break;
        }
    case 4://�޸�
        wm.mod_emp();
        break;
    case 5://����
        wm.find_emp();
        break;
    case 6://����
        wm.sort_emp();
    case 7://���
        wm.clean_file();
        return 0;
        break;
    default:
        break;
    }
}
 //���ó�Ա����

 system("pause");
 return 0;
}
