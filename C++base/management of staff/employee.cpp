#include "employee.h"
#include <string>
employee::employee(int id,string name,int depart)
{
    this->m_id=id;
    this->m_name=name;
    this->m_depart=depart;
}
 void employee::showinfo()//显示个人信息
 {
     cout<< "职工编号: "<<this->m_id
     << "\t职工姓名: "<<this->m_name
     << "\t岗位: "<<this->getdepart()
     << "\t岗位职责：完成经理交给的任务:"<<endl;
 }
  string employee::getdepart()
  {
      return string("员工");
  }
