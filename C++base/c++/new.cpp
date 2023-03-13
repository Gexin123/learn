#include<iostrem>
using namespace std;
int *func()
{
    int *p=new int(10);
    return p;
}
void test01()
{
    int *p=func();
    cout<<*p<<endl;
    delete p;
}
void test02()
{
    int *arr=new int[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=i+100;
    }
    delete[] arr;
}

//引用的基本语法
int a=10;
int &b=a;//引用要初始化，一旦初始化之后就不能改了
//值传递
void swap01(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}
//地址传递
void swap02(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//引用传递
void swap03(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int a=20;
    int b=10;
    swap01(a,b);//值传递实参不会改变
    cout<< "a="<<a<<endl;
    cout<< "a="<<b<<endl;
    swap02(&a,&b);
    swap03(a,b);//引用传递，形参也会修饰实参。
}
//不要返回局部变量的引用
int &test01()
{
    int a=10;
    return a;
}
int &ref=test01();
cout<< ref<<endl;

int &test02()
{
    static int a=10;
    return a;
}
int &ref2=test02();
test02=1000;//如果函数的返回是引用，也可以作为左值使用.结果是a=1000

//引用的本质就是指针，由编译器为我们做了转换为指针的操作

//常量引用，用来修饰形参，防止误操作
int a=10;
const int &ref=10;//加入const之后变为只读，不能修改

void showvalue(const int &val)//只做打印，不会修改参数
{
    //val=1000;
    cout<<val<<endl;
}
int a=100;
showvalue(a);










