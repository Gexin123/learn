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

//���õĻ����﷨
int a=10;
int &b=a;//����Ҫ��ʼ����һ����ʼ��֮��Ͳ��ܸ���
//ֵ����
void swap01(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}
//��ַ����
void swap02(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//���ô���
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
    swap01(a,b);//ֵ����ʵ�β���ı�
    cout<< "a="<<a<<endl;
    cout<< "a="<<b<<endl;
    swap02(&a,&b);
    swap03(a,b);//���ô��ݣ��β�Ҳ������ʵ�Ρ�
}
//��Ҫ���ؾֲ�����������
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
test02=1000;//��������ķ��������ã�Ҳ������Ϊ��ֵʹ��.�����a=1000

//���õı��ʾ���ָ�룬�ɱ�����Ϊ��������ת��Ϊָ��Ĳ���

//�������ã����������βΣ���ֹ�����
int a=10;
const int &ref=10;//����const֮���Ϊֻ���������޸�

void showvalue(const int &val)//ֻ����ӡ�������޸Ĳ���
{
    //val=1000;
    cout<<val<<endl;
}
int a=100;
showvalue(a);










