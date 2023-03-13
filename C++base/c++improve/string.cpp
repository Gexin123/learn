#include <iostream>
using namespace std;
void test01()
{
    string s1;
    const char *str= "hello word";
    string s2(str);
    cout<< "s2="<<s2<<endl;
    string s3(s2);
    string s4(10,'a');
}

//string赋值操作
void test()
{
    string str1;
    str1="hello word";
    cout<< "str="<<str1<<endl;

    string str2;
    str2=str1;

    string str3
    str3='a';

    string str4;
    str4.assign=("hello");

    string str5;
    str5.assign("hello",5);

    string str6;
    str6.assign(str5);

    string str7;
    str7.assign(10,'w');//10个w
}

//字符串的拼接
string str1="hello";
str1+="word";
str+=':';
string str2="lol dnf";
str1+=str2;
string str3="i";
str3.append("love");
str3.append("game adobe",4);//i love game
str3.append(str2);
str3.append(str2,0,3);//只截取lol

//string查找和替换
void test()
{
    string str="abcdef";
    int pos=str.find("de");//3
    if(pos==-1)
    {
        cout<< "没有找到"<<endl;
    }
    else
    {
        cout<< "找到"<<pos<<endl;
    }
    //rfind是从右往左查
    pos=str.rfind("de");
}
//替换
void test()
{
    string str="abcdef";
    str.replace(1,3,"1111");//a1111f
}

//string字符串的比较
void test()
{
    string str1="hello";
    string str2="hello";
    if(str.compare(str2)==0)
    {
        cout<< "str1等于str2"<<endl;
    }
    else if(str1.compare(str2)>0)
    {
        cout<< "str1大于str2"<<endl;
    }
    else
    {
        cout<< "str1小于str2"<<endl;
    }
}

//string字符存取
string str="hello";

for(int  i=0;i<str.size(),i++)
{
    cout<<str[i]<< " ";
}
cout<<endl;

for(int i=0;i<str.size();i++)
{
    cout<<str.at(i)<<" ";
}

str[0]='x';//xello

//插入和删除
string str="hello";
str.insert(1,"111");//h111elo
str.erase(1,3)//hello

//string子串
string str="abcdef";
string Substr=str.substr(1,3);//bcd
//实用
string email="zhangsan@sina.com"
int pos=email.find("@");//8
string name=email.substr(0,pos);//zhangsan









