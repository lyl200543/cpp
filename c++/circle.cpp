#include"circle.h"
//class Circle
//{
//private:
//	//���а�����һ����
//	Point c0;
//	double m_r;
//public:
    void Circle::set(Point c, double r)
	{
		c0 = c;
		m_r = r;
	}
	Point Circle::GetC()
	{
		return c0;
	}
	double Circle::GetR()
	{
		return m_r;
	}
//};