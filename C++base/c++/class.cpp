const double pi=3.14;
class circle//类
{
public：
    int r;
    double calcluate()
    {
        return 2*pi*r;
    }
};
int main()
circle c1;//对象
c1.r=10;
cout<<c1.calcluate()<<endl;

//设计一个学生类
class student
{
public://类中的属性和行为统一称为成员
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
public://类内类外都可以访问
    string m_name;
protected://类内可以访问，类外不可以访问
    string m_car;
private://类内可以访问，类外不可以访问
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
p1.m_car="benchi";//不可以访问


class person//可以提供可读可写的操作
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

//设计立方体类，求出面积和体积

class cube
{
public://行为
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
    int m_l;//属性
    int m_w;
    int m_h;
};
bool issame(cube &c1,cube &c2)//全局函数
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
    cout<< "c1的面积为"<<c1.calculates()<<endl;
    cout<< "c1的体积为"<<c1.calculatev()<<endl;
    cube c2;
    c2.setl(10);
    c2.setw(10);
    c2.seth(10);
    bool ret=issame(c1,c2);
    if(ret)
    {
       cout<< "相等"<<endl;
    }
    else
    {
        cout<< "不相等"<<endl;
    }
    ret=c1.issamebyclass(c2);
    if(ret)
    {
       cout<< "class相等"<<endl;
    }
    else
    {
        cout<< "class不相等"<<endl;
    }
}

//圆和点的位置判断
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
    point m_center;//在类中可以让另一个类作为新的成员存在
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






