#include<iostream>
using namespace std;
int func2(int a=10,int b=10);
int func(int a,int b=20,int c=30)//���ĳ��ֵ����Ĭ�ϲ����������������Ķ�����Ĭ��ֵ
{
    return a+b+c;
}
int main()
{
    cout<<func(10,30)<<endl;//���������ֵ����ô���������ֵ�����û�����룬��ʹ��Ĭ�ϵ�ֵ

}
int func2(int a,int b)
{
    return a+b;
}

//����ռλ����������ֵ���� ���������������ͣ�
void func3(int a,int)//��λ��ռ�ˣ����������͵�����
{
    cout<< "hhhh"<<endl;
}
int main()
{
    func3(10,10);
}

//��������
void func4()
{
    cout<< "func4"<<endl;
}
void func4(int a)//������ͬ
{
    cout<< "func4(int a)"<<endl;
}
void func4(double a)//���Ͳ�ͬ
{
    cout<< "func4(d)"<<endl;
}






