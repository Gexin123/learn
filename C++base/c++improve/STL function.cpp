#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>//内建函数对象头文件
//仿函数，有参数也有返回值
class myadd
{
public:
    int operator()(int v1,int v2)
    {
        return v1+v2;
    }

};
class myprint
{
public:
    myprint()
    {
        this->count=0;
    }
    void operator()(string test)
    {
        cout<<test<<endl;
        this->count++;
    }
    int count;//内部自己的状态
};
//函数对象可以作为参数传递
void doprint(myprint &mp,string test)
{
    mp(test);
}
void test()
{
    myprint myp;
    doprint(myp,"hello");
}

//仿函数返回bool类型，称为谓词
class greaterfive
{
public:
    bool operator()(int val)//一元谓词
    {
        return val>5;
    }
};
void test()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it=find_if(v.begin(),v.end(),greaterfive());
}

//二元谓词
class compare
{
public:
    bool operator()(int val1,int val2)//二元谓词
    {
        return val1>val2;
    }
};
void test()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(70);
    v.push_back(30);
    sort(v.begin(),v.end());
    sort(v.begin(),v.end(),compare());
}

//算术仿函数
void test()
{
    negate<int>n;
    n(50);//取反
    plus<int>p;
    p(10,20);//二元相加

}

//关系仿函数
void test()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(70);
    v.push_back(30);
    //greater<int>(),内建的仿函数
    sort(v.begin(),v.end(),greater<int>());//改为降序
}

//逻辑仿函数
void test()
{
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    //利用逻辑非将容器v搬运到容器2中去
    vector<bool>v2;
    v2.resize(v.size());//开辟空间
    transform(v.begin(),v.end(),logical_not<bool>());
}
























