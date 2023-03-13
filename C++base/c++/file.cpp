#include<iostream>
using namespace std;
#include <fstream>//文本文件
//写文件
void test()
{
    ofstream ofs;//创建流对象
    ofs.open("test.txt",ios::out)//指定打开方式，写
    ofs<< "姓名：张三"<<endl;//写内容
    ofs<< "年龄：18"<<endl;
    ofs<< "性别：男"<<endl;
    ofs.close();//写完需要关闭
}
//读文件
void test02()
{
    ifstream ifs;
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<< "文件打开失败"<<endl;
        return;
    }
    //第一种读数据的方式
    char buf[1024]={0};//准备出字符数组
    while (ifs>>buf)
    {
        cout<<buf<<endl;
    }
    //2
    char buf[1024]={0};//准备出字符数组
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
//二进制文件
class person
{
public:
    char m_name[64];
    int m_age;
};
void test()
{
    ofstream ofs("person.txt",ios::out|ios::binary);
    person p=("张三",18);
    ofs.write((const char *)&p,sizeof(p));//写文件，以二进制的方式写文件
    ofs.close();
}





