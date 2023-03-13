#include "manager.h"

 manager::manager(int id,string name,int depart)
 {
     this->m_id=id;
    this->m_name=name;
    this->m_depart=depart;
 }
void manager:: showinfo()
{
     cout<< "职工编号: "<<this->m_id
     << "\t职工姓名: "<<this->m_name
     << "\t岗位: "<<this->getdepart()
     << "\t岗位职责：完成老板交给的任务，并且下发任务给员工"<<endl;
}
string manager::getdepart()
{
    return string("经理");
}
