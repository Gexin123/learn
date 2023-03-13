#pragma once
#include<iostream>
using namespace std;
#include<string>
template <class T1,class T2>
class person()
{
public:
    person(T1 name,T2 age);
    T1 m_name;
    T2 m_age;
    void showperson();
}
