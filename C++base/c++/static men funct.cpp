#include<iostream>
using namespace std;
class person
{
public:
    static void func()
    {
        m_a=100;
        m_b=200;//��̬��Ա���������Է��ʷǾ�̬��Ա����
        cout<< "��̬��������"<<endl;
    }
    static int m_a;
    int m_b;
};
void test01()
{
    person p;//ͨ���������
    p.func();
    person::func();//ͨ����������
}


//��Ա�����ͳ�Ա�����Ƿֿ��洢��
class person
{
   int m_a;
   void func(){}
};
void test01()
{
    person p;
    cout<< "size of p="<<sizeof(p)<<endl;//�ն���ռ�õ��ڴ�ռ��ǣ�1
    //��Ϊ������ÿһ���ն���ռ�õ��ڴ�ռ�
}
void test02()
{
    person p;
    cout<< "size of p="<<sizeof(p)<<endl;//�ǿն���ռ�õ��ڴ�ռ��ǣ�4
    //����int���ڴ��С��staticҲ��4
}

//thisָ�����
class person
{
public:
    person(int age)
    {
        //������Ƴ�ͻ
        this->age=age;//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
    }
    person& personage(person &p)
    {
        this->age+=p.age;
        return *this;//thisָ��p2��ָ�룬��*this�������������
    }
    int age;//��Ա����Ӧ�úͲ�����������
};
void test01()
{
    person p1(18);
    cout<< "p1�������ǣ�"<<p1.age<<endl;//
}
void test02()
{
    personp1(10);
    personp2(10);
    p2.personage(p1).personage(p1).personage(p1);//��ʽ���˼��
    cout<< "p2������Ϊ��"<<p2.age<<endl;//
}
class person
{
public:
    void showperson() const//�ڳ�Ա���������const�����ε���thisָ����ָ�벻�����޸�
    {
        this->m_b=100;
        m_a=100;//
    }
    int m_a=100;
    mutable int m_b;//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ
};
const person p;//��Ϊ������


//��Ԫ����һ���������������һ�����е�˽�г�Ա
class building
{
    friend void goodgay(building *build)//goodgay���ȫ�ֺ�����building�ĺ����ѣ����Է��������˽�г�Ա
public:
    building()
    {
        m_sittingroom="����"��
        m_bedroom="����"��
    }
public:
    string m_sittingtoom;
private:
    string m_bedroom;
};
void goodgay(building *build)
{
    cout<< "�û���ȫ�ֺ��������ڷ���"<<build->m_sittingroom<<endl;
    cout<< "�û���ȫ�ֺ��������ڷ���"<<build->m_bedroom<<endl;
}
void test01()
{
    building build;
    goodgay(&build);

}

//������Ԫ
class building;
class goodgay
{
public:
    goodgay();
public:
    void visit();//����buildi�е�����
    building *build;
};
class building
{
    friend class goodgay;//goodgay��building�ĺ�����
public:
    building();
public:
    string m_sittingtoom;
private:
    string m_bedroom;

};
  building::building();//�����⹹���Ա����
  {
      m_sittingroom="����"��
        m_bedroom="����"��
  }
   goodgay::goodgay()
   {
       build=new building;

   }
   void goodgay:: visit()
   {
       cout<< "�û������ڷ���"<<build->m_sittingroom<<endl;
       cout<< "�û������ڷ���"<<build->m_bedroom<<endl;
   }


//��Ա��������Ԫ
class building;
class goodgay
{
public:
    goodgay();
    void visit();
    void visit2();
    building *build;
};
class building
{
    friend void goodgay::visit();//goodgay���µ�vivst��Ա������Ϊ����ĺ����ѣ����Է���˽�г�Ա
public:
    building();
public:
    string m_sittingroom;
private:
    string m_beroom;

};
building::building()
{
    m_sittingroom="����";
    m_bedroom="����";
}
goodgay::goodgay()
{
    build=new building;
}
    void goodgay::visit()
    {
        cout<< "visit���ڷ���"<<build->m_bedroom<<endl;
    }
    void goodgay::visit2()





