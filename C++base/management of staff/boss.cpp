#include "boss.h"

 boss::boss(int id,string name,int depart)
 {
     this->m_id=id;
    this->m_name=name;
    this->m_depart=depart;
 }
void boss:: showinfo()
{
     cout<< "职工编号: "<<this->m_id
     << "\t职工姓名: "<<this->m_name
     << "\t岗位: "<<this->getdepart()
     << "\t岗位职责：完管理公司所有事务:"<<endl;
}
string boss::getdepart()
{
    return string("老板");
}
