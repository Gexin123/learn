#include "boss.h"

 boss::boss(int id,string name,int depart)
 {
     this->m_id=id;
    this->m_name=name;
    this->m_depart=depart;
 }
void boss:: showinfo()
{
     cout<< "ְ�����: "<<this->m_id
     << "\tְ������: "<<this->m_name
     << "\t��λ: "<<this->getdepart()
     << "\t��λְ�������˾��������:"<<endl;
}
string boss::getdepart()
{
    return string("�ϰ�");
}
