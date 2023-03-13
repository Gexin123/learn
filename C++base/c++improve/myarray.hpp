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
        this->paddress=new T[this->m_capacity];//����
    }
    //��������
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
    //����Ⱥ�����
    myarray& operator=(comst myarray& arr)
    {
        if(this->padress!=NULL)
        {
            delete[]this->padress;
            this->padress=NULL;
            this->m_capacity=0;
            this->m_size=0;
        }
        //���
        this->m_capacity=arr.m_capacity;
        this->m_size=arr.m_size;
        this->paddress=new T[arr.m_capacity];
        for(int i=0;i<this->m_size;i++)
        {
            this->padress[i]=arr.padress[i];
        }
        return *this;
    }
    //β�巨
    void push_back(const T &val)
    {
        if(this->m_capacity==thi->m_size)
        {
            return;
        }
        this->padress[this->m_size]=val;
        this->m_size++;
    }
    //βɾ��
    void pop_back()
    {
        if(this->m_size==0)
        {
            return;
        }
        this->m_size--;
    }

    //ͨ���±귽ʽ���������е�Ԫ��,arr[0]=100����Ҫ��һ����ֵ�Ĳ�����Ҫ����ԭ���͵�����
    T& operator[](int index)
    {
        return this->padress[index];
    }

    //������������
    int getcpacity()
    {
        return this->m_capacity;
    }

    //��������Ĵ�С
    int getsize()
    {
        return this->m_size;
    }

    //��������
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
