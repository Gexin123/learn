#include<iostream>
using namespace std;
int func2(int a=10,int b=10);
int func(int a,int b=20,int c=30)//如果某个值有了默认参数，则这个数后面的都得有默认值
{
    return a+b+c;
}
int main()
{
    cout<<func(10,30)<<endl;//如果输入了值，那么就用输入的值，如果没有输入，才使用默认的值

}
int func2(int a,int b)
{
    return a+b;
}

//函数占位参数。返回值类型 数据名（数据类型）
void func3(int a,int)//把位置占了，必须是整型的输入
{
    cout<< "hhhh"<<endl;
}
int main()
{
    func3(10,10);
}

//函数重载
void func4()
{
    cout<< "func4"<<endl;
}
void func4(int a)//个数不同
{
    cout<< "func4(int a)"<<endl;
}
void func4(double a)//类型不同
{
    cout<< "func4(d)"<<endl;
}






