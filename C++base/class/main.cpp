#include <iostream>
#include "point.h"
using namespace std;
class point
{
public:
    void point::setX(int x)
    {
        m_x=x;
    }
    int point::getX()
    {
        return(m_x);
    }
    void point::setY(int y)
    {
        m_y=y;
    }
    int point::getY()
    {
        return(m_y);
    }
private:
    int m_x;
    int m_y;
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
