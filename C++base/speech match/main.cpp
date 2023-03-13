#include <iostream>
using namespace std;
#include <stdlib.h>
#include "specstrings.h"
#include<string>
#include<ctime>
int main()
{
    srand(unsigned int)time(NULL);
    speechmanager sm;
    sm.show_menu();
    int choice=0;
while(true)
{
    sm.showmenu();
    cout<< "请输入您的选择"<<endl;
    cin>>choice;
      switch(choice)
    {
    case 1://开始比赛
        sm.startspeech();
        break;
    case 2://查看往届记录
        sm.showrecord();
        break;
    case 3://清空比赛记录
        wm.show_emp();
        break;
    case 0://退出
        sm.exitsystem();
        break;
    default:
        system("cls");
        break;
        }
}
    system("pause");
    return 0;
}
