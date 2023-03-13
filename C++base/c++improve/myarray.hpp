#pragma once
#include <iostream>
using namespace std;

template<class T>
class myarray
{
public:
    myarray(int capacity)
    {
        this->m_capacity=capacity;
        this->m_size=0;
        this->paddress=new T[this->m_capacity];//数组
    }
    //拷贝构造
    myarray(const myarray& arr)
    {
        this->m_capacity=arr.m_capacity;
        this->m_size=arr.m_size;
        this->padress=new T[arr.m_capacity];
        for(int i=0;i<this->m_size;i++)
        {
            this->padress[i]=arr.padress[i];
        }
    }
    //数组等号重载
    myarray& operator=(comst myarray& arr)
    {
        if(this->padress!=NULL)
        {
            delete[]this->padress;
            this->padress=NULL;
            this->m_capacity=0;
            this->m_size=0;
        }
        //深拷贝
        this->m_capacity=arr.m_capacity;
        this->m_size=arr.m_size;
        this->paddress=new T[arr.m_capacity];
        for(int i=0;i<this->m_size;i++)
        {
            this->padress[i]=arr.padress[i];
        }
        return *this;
    }
    //尾插法
    void push_back(const T &val)
    {
        if(this->m_capacity==thi->m_size)
        {
            return;
        }
        this->padress[this->m_size]=val;
        this->m_size++;
    }
    //尾删法
    void pop_back()
    {
        if(this->m_size==0)
        {
            return;
        }
        this->m_size--;
    }

    //通过下标方式访问数组中的元素,arr[0]=100，想要做一个赋值的操作需要返回原类型的引用
    T& operator[](int index)
    {
        return this->padress[index];
    }

    //返回数组容量
    int getcpacity()
    {
        return this->m_capacity;
    }

    //返回数组的大小
    int getsize()
    {
        return this->m_size;
    }

    //析构函数
    ~myarray()
    {
        if(this->paddress!=NULL)
        {
            delete[]this->paddress;
            this->paddress=NULL;
        }
    }
private:
    T *paddress;
    int m_capacity;
    int m_size;
};
