#include "employee.h"
#include <string>
employee::employee(int id,string name,int depart)
{
    this->m_id=id;
    this->m_name=name;
    this->m_depart=depart;
}
 void employee::showinfo()//��ʾ������Ϣ
 {
     cout<< "ְ�����: "<<this->m_id
     << "\tְ������: "<<this->m_name
     << "\t��λ: "<<this->getdepart()
     << "\t��λְ����ɾ�����������:"<<endl;
 }
  string employee::getdepart()
  {
      return string("Ա��");
  }
