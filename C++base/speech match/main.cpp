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
    cout<< "����������ѡ��"<<endl;
    cin>>choice;
      switch(choice)
    {
    case 1://��ʼ����
        sm.startspeech();
        break;
    case 2://�鿴�����¼
        sm.showrecord();
        break;
    case 3://��ձ�����¼
        wm.show_emp();
        break;
    case 0://�˳�
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
