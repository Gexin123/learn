#include<iostream>
using namespace std;
#include <fstream>//�ı��ļ�
//д�ļ�
void test()
{
    ofstream ofs;//����������
    ofs.open("test.txt",ios::out)//ָ���򿪷�ʽ��д
    ofs<< "����������"<<endl;//д����
    ofs<< "���䣺18"<<endl;
    ofs<< "�Ա���"<<endl;
    ofs.close();//д����Ҫ�ر�
}
//���ļ�
void test02()
{
    ifstream ifs;
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<< "�ļ���ʧ��"<<endl;
        return;
    }
    //��һ�ֶ����ݵķ�ʽ
    char buf[1024]={0};//׼�����ַ�����
    while (ifs>>buf)
    {
        cout<<buf<<endl;
    }
    //2
    char buf[1024]={0};//׼�����ַ�����
    while (ifs.getline(buf,sizeof(buf)))
    {
        cout<<buf<<endl;
    }
    //3
    string buf;
    while(getline(ifs,buf))
    {
        cout<<buf<<endl;
    }
    //4
    char c;
    while((c=ifs.get()!=EOF))
    {
        cout<<c;
    }
    ifs.close();
}
//�������ļ�
class person
{
public:
    char m_name[64];
    int m_age;
};
void test()
{
    ofstream ofs("person.txt",ios::out|ios::binary);
    person p=("����",18);
    ofs.write((const char *)&p,sizeof(p));//д�ļ����Զ����Ƶķ�ʽд�ļ�
    ofs.close();
}





