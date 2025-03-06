#pragma once
class Point
{
private:
	double x1, y1;
public:
	void Set(double x, double y);
	/*{
		x1 = x;
		y1 = y;
	}*/

	double GetX();
	/*{
		return x1;
	}*/

	double GetY();
	/*{
		return y1;
	}*/
};
