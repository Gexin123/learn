const double pi=3.14;
class circle//��
{
public��
    int r;
    double calcluate()
    {
        return 2*pi*r;
    }
};
int main()
circle c1;//����
c1.r=10;
cout<<c1.calcluate()<<endl;

//���һ��ѧ����
class student
{
public://���е����Ժ���Ϊͳһ��Ϊ��Ա
    string m_name;
    int m_id;
    void showstudent()
    {
        cout<< "name"<<m_name<< "id="<<m_id<<endl;
    }
    void setname(string name)
    {
        m_name=name;
    }
};
int main()
{
    student s1;
    s1.setname("zhangsan");
    s1.m_id=1;

}

class person
{
public://�������ⶼ���Է���
    string m_name;
protected://���ڿ��Է��ʣ����ⲻ���Է���
    string m_car;
private://���ڿ��Է��ʣ����ⲻ���Է���
    int m_password;
public:
    void funct()
    {
        m_name="zhangsan";
        m_car="tuolaji";
        m_password=12345;
    }
};
int main()
person p1;
p1.m_name="lisi";
p1.m_car="benchi";//�����Է���


class person//�����ṩ�ɶ���д�Ĳ���
{
public:
    void setname(string name)
    {
        m_name=name;
    }
    string getname()
    {
        return m_name;
    }
private:
    string m_name;
    int m_age;

};
int main()
{
    person p;
    p.setname("zhangsan");
    cout<<p.getname()<<endl;
}

//����������࣬�����������

class cube
{
public://��Ϊ
    void setl(int l)
    {
        m_l=l;
    }
    int getl()
    {
        return m_l;
    }
    void setw(int w)
    {
        m_w=w;
    }
    int getw()
    {
        return m_w;
    }
    void seth(int h)
    {
        m_h=h;
    }
    int geth()
    {
        return m_h;
    }
    int calculates()
    {
        return 2*m_l*m_w+2*m_w*m_h+2*m_h*m_l;
    }
    int calculatev()
    {
        return m_l*m_w*m_h;
    }
    bool issamebyclass(cube &c)
    {
        if(m_l==c.getl()&&m_w==c.getw()&&m_h==c.geth())
    }
private:
    int m_l;//����
    int m_w;
    int m_h;
};
bool issame(cube &c1,cube &c2)//ȫ�ֺ���
{
    if(c1.getl()==c2.getl()&&c1.getw()==c2.getw()&&c1.geth()==c2.geth())
    {
        return true;
    }
   return false;
}
int main()
{
    cube c1;
    c1.setl(10);
    c1.setw(10);
    c1.seth(10);
    cout<< "c1�����Ϊ"<<c1.calculates()<<endl;
    cout<< "c1�����Ϊ"<<c1.calculatev()<<endl;
    cube c2;
    c2.setl(10);
    c2.setw(10);
    c2.seth(10);
    bool ret=issame(c1,c2);
    if(ret)
    {
       cout<< "���"<<endl;
    }
    else
    {
        cout<< "�����"<<endl;
    }
    ret=c1.issamebyclass(c2);
    if(ret)
    {
       cout<< "class���"<<endl;
    }
    else
    {
        cout<< "class�����"<<endl;
    }
}

//Բ�͵��λ���ж�
class point
{
public:
    void setX(int x)
    {
        m_x=x;
    }
    int getX()
    {
        return(m_x);
    }
    void setY(int y)
    {
        m_y=y;
    }
    int getY()
    {
        return(m_y);
    }
private:
    int m_x;
    int m_y;
};
class circle
{
public:
    void setr(int r)
    {
        m_r=r;
    }
    int getr()
    {
        return m_r;
    }
    void setcenter(point center)
    {
        m_center=center;
    }
    point getcenter()
    {
        return m_center;
    }
private:
    int m_r;
    point m_center;//�����п�������һ������Ϊ�µĳ�Ա����
};
void isincircle(circle &c,point &p)
{
    int distance=
}
int main()
{
    circle c;
    c.setr(10);
    point center;
    center.setX(10);
    center.setY(0);
    c.setcenter(center);
    point p;
    p.setX(10);
    p.setY(11);
}






