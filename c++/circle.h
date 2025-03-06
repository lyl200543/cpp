#pragma once
#include"point.h"
class Circle
{
private:
	//类中包含另一个类
	Point c0;
	double m_r;
public:
	void set(Point c, double r);
	/*{
		c0 = c;
		m_r = r;
	}*/

	Point GetC();
	/*{
		return c0;
	}*/

	double GetR();
	/*{
		return m_r;
	}*/
};