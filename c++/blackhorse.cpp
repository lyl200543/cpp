//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}

//一.内存分区模型：代码区，常量区，栈区，堆区
//程序运行前：代码区，常量区
//程序运行后：代码区，常量区，栈区，堆区

//常量区：全局变量，静态变量，常量（字符串常量，const修饰的全局变量）
//const修饰的局部变量不是常量


//二.引用：
//1.引用的本质：是一个指针常量
//#include<iostream>
//int main()
//{
//	int a = 10;
//	//自动转换为 int* const ref= &a; 指针常量的指针指向不能改
//	//这也说明了为什么引用不能更改
//	int& ref = a;   
//	ref = 20;  //相当于 *ref=20;
//	return 0;
//}

//2.常量引用：
//#include<iostream>
//int main()
//{
//	//int& ref = 10;  //不合法：引用的右值不能是常量
//	const int& ref = 10;   //合法
//	//编译器自动转换：int tmp=10; const int& ref=tmp;
//	return 0;
//}


//三.函数高级：
//1.占位参数：
//作为函数的参数，但是只有类型，没有名字

//#include<iostream>
//void fuc(int a, int)
//{
//	std::cout << "hello world\n";
//}
//占位参数也能使用默认参数
//void fuc(int a, int = 10)
//{
//	std::cout << "hello world\n";
//}
//int main()
//{
//	fuc(10,10);   //调用时占位参数必须填补
//	return 0;
//}


//四.类和对象：
//1.封装：

//设计一个学生类：
//#include<iostream>
//#include<string>
//using namespace std;
//class student
//{
//public:
//	string name;
//	string number;
//
//	void Print()
//	{
//		cout << name << " " << number << endl;
//	}
//};
//int main()
//{
//	student stu;
//	stu.name = "lyl";
//	stu.number = "123456789";
//	stu.Print();
//	return 0;
//}


//1>****将成员属性设置为私有：
//可以自己控制成员属性的读写权限
//对于写权限，我们可以检测数据的有效性

//#include<iostream>
//#include<string>
//using namespace std;
//class person
//{
//private:
//	string m_name;   //可读可写
//	int m_age = 18;  //只读
//	string m_idol;   //只写
//public:
//	//可读可写
//	void SetName(string name)
//	{
//		m_name = name;
//	}
//	string GetName()
//	{
//		return m_name;
//	}
//
//	//只读  
//	int GetAge()
//	{
//		return m_age;
//	}
//	
//	//写权限：检测数据
//	void SetAge(int age)
//	{
//		if (age < 0 || age>100)
//		{
//			cout << "年龄输入错误，赋值失败" << endl;
//			return;
//		}
//		m_age = age;
//	}
//
//	//只写
//	void SetIdol(string idol)
//	{
//		m_idol = idol;
//	}
//};
//int main()
//{
//	person p;
//	p.SetName("lyl");
//	cout << "姓名： " << p.GetName() << endl;
//	p.SetAge(250);
//	cout << "年龄： " << p.GetAge() << endl;
//	p.SetIdol("zyz");
//	return 0;
//}


//设计一个立方体类
//#include<iostream>
//using namespace std;
//class Cube
//{
//private:
//	double m_l, m_w, m_h;
//public:
//	void Set(double l, double w, double h)
//	{
//		m_l = l;
//		m_w = w;
//		m_h = h;
//	}
//	double GetL() 
//	{
//		return m_l;
//	}
//	double GetW()
//	{
//		return m_w;
//	}
//	double GetH()
//	{
//		return m_h;
//	}
//	double calculateS()
//	{
//		return (m_l * m_w + m_l * m_h + m_h * m_w) * 2;
//	}
//	double calculateV()
//	{
//		return m_l * m_w * m_h;
//	}
//
//
//	//**注意全局函数和成员函数的区别（参数）
//	bool is_equal(Cube& c)
//	{
//		if (m_l == c.GetL() && m_w == c.GetW() && m_h == c.GetH())
//			return true;
//		return false;
//	}
//};
//bool is_equal(Cube& c1, Cube& c2)
//{
//	if (c1.GetL() == c2.GetL() && c1.GetW() == c2.GetW() && c1.GetH() == c2.GetH())
//		return true;
//	return false;
//}
//int main()
//{
//	Cube c1, c2;
//	c1.Set(10,10,10);
//	c2.Set(10,10,10);
//	cout << "面积： " << c1.calculateS() << endl << "体积： " << c1.calculateV() << endl;
//	cout << "面积： " << c2.calculateS() << endl << "体积： " << c2.calculateV() << endl;
//	cout << c1.is_equal(c2) << endl;
//	cout << is_equal(c1, c2) << endl;
//	return 0;
//}


//设计点和圆类（处理点和圆的关系）
//#include<iostream>
//#include<cmath>  //pow()的头文件
//using namespace std;
//
////当一个类的定义依赖于另一个尚未定义的类时:前向声明和分离定义
//
////前向声明：
//class Circle;
//
//class Point
//{
//private:
//	double x1, y1;
//public:
//	void Set(double x, double y)
//	{
//		x1 = x;
//		y1 = y;
//	}
//	double GetX()
//	{
//		return x1;
//	}
//	double GetY()
//	{
//		return y1;
//	}
//
//	//此时Circle尚未定义，编译器会报错
//	//声明：
//	void position(Circle& c);
//	/*{
//		if (pow(x1 - c.GetX(), 2) + pow(y1 - c.GetY(), 2) == pow(c.GetR(), 2))
//			cout << "点在圆上" << endl;
//		else if (pow(x1 - c.GetX(), 2) + pow(y1 - c.GetY(), 2) > pow(c.GetR(), 2))
//			cout << "点在圆外" << endl;
//		else
//			cout << "点在圆内" << endl;
//	}*/
//};
//class Circle
//{
//private:
//	double x0, y0, m_r;
//public:
//	void set(double x, double y, double r)
//	{
//		x0 = x;
//		y0 = y;
//		m_r = r;
//	}
//	double GetX()
//	{
//		return x0;
//	}
//	double GetY()
//	{
//		return y0;
//	}
//	double GetR()
//	{
//		return m_r;
//	}
//
//	//声明:
//	void position(Point& p);
//	/*{
//		if (pow(p.GetX () - x0, 2) + pow(p.GetY () - y0, 2) == pow(m_r, 2))
//			cout << "点在圆上" << endl;
//		else if (pow(p.GetX() - x0, 2) + pow(p.GetY() - y0, 2) > pow(m_r, 2))
//			cout << "点在圆外" << endl;
//		else
//			cout << "点在圆内" << endl;
//	}*/
//};
//
////分离定义：
//void Point::position(Circle& c)
//{
//	if (pow(x1 - c.GetX(), 2) + pow(y1 - c.GetY(), 2) == pow(c.GetR(), 2))
//		cout << "点在圆上" << endl;
//	else if (pow(x1 - c.GetX(), 2) + pow(y1 - c.GetY(), 2) > pow(c.GetR(), 2))
//		cout << "点在圆外" << endl;
//	else
//		cout << "点在圆内" << endl;
//}
//
//void Circle::position(Point& p)
//{
//	if (pow(p.GetX () - x0, 2) + pow(p.GetY () - y0, 2) == pow(m_r, 2))
//		cout << "点在圆上" << endl;
//	else if (pow(p.GetX() - x0, 2) + pow(p.GetY() - y0, 2) > pow(m_r, 2))
//		cout << "点在圆外" << endl;
//	else
//		cout << "点在圆内" << endl;
//}
//
//int main()
//{
//	Point p;
//	p.Set(1, 2);
//	Circle c;
//	c.set(0, 0, 2);
//	p.position(c);
//	c.position(p);
//	return 0;
//}


//标准版：
//一个类的成员属性可以是另一个类
//类的分离（文件）

//在 C++ 中，类对象之间是可以直接赋值的
//但这种赋值行为需要类支持赋值运算符（operator=）
//C++ 会自动为每个类生成默认的赋值运算符，除非你显式地定义了自己的赋值运算符
//默认的赋值运算符会逐成员赋值，即将源对象的每个成员变量的值复制到目标对象的对应成员变量中

//#include<iostream>
//#include<cmath>  //pow()的头文件
//#include"point.h"
//#include"circle.h"
//using namespace std;
//
////class Point
////{
////private:
////	double x1, y1;
////public:
////	void Set(double x, double y)
////	{
////		x1 = x;
////		y1 = y;
////	}
////	double GetX()
////	{
////		return x1;
////	}
////	double GetY()
////	{
////		return y1;
////	}
////};
//
////class Circle
////{
////private:
////	//类中包含另一个类
////	Point c0;
////	double m_r;
////public:
////	void set(Point c, double r)
////	{
////		c0 = c;
////		m_r = r;
////	}
////	Point GetC()
////	{
////		return c0;
////	}
////	double GetR()
////	{
////		return m_r;
////	}
////};
//
//void position(Circle& c, Point& p)
//{
//	double dist = pow(c.GetC().GetX() - p.GetX(), 2) + pow(c.GetC().GetY() - p.GetY(), 2);
//	double cdist = pow(c.GetR(), 2);
//	if (dist == cdist)
//		cout << "点在圆上" << endl;
//	else if (dist < cdist)
//		cout << "点在圆内" << endl;
//	else
//		cout << "点在圆外" << endl;
//}
//
//int main()
//{
//	Point c0;
//	c0.Set(0, 0);
//	Circle c;
//	c.set(c0, 3);
//	Point p;
//	p.Set(1, 2);
//	position(c, p);
//	return 0;
//}


//2.对象的初始化和清理：

//1>构造函数和析构函数：
//作用：进行初始化和清理工作
//系统自动调用，且只调用一次
//构造函数可以有参数，以此可以重载
//析构函数不可以有参数
//如果我们没有自定义构造函数和析构函数，编译器会提供默认函数，且函数为空实现（函数体为空的函数）

//2>构造函数的分类:
//按参数分类：无参构造函数（默认构造函数），有参构造函数
//按类型分类：普通构造函数，拷贝构造函数

//3>构造函数的调用：括号法，显示法，隐式转换法

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_age;
//
//	//普通构造函数：
//	Person()
//	{
//		cout << "默认构造函数调用" << endl;
//	}
//	Person(int age)
//	{
//		m_age = age;
//		cout << "有参构造函数调用" << endl;
//	}
//	//拷贝构造函数：
//	Person(const Person& p)
//	{
//		m_age = p.m_age;
//		cout << "拷贝构造函数调用" << endl;
//	}
//
//	~Person()
//	{
//		cout << "析构函数调用" << endl;
//	}
//};
//int main()
//{
//	//1.括号法：
//	//Person p1;
//	//Person p2(10);
//	//Person p3(p2);
//	//cout << "p2: " << p2.m_age << endl;
//	//cout << "p3: " << p3.m_age << endl;
//	
//	//注意事项1：调用默认构造函数时不要加括号，编译器会认为是函数声明 void print()
//	//Person p1();
//
//	//2.显示法：
//	//Person p1;
//	//Person p2 = Person(10);
//	//Person p3 = Person(p2);
//
//	//注意事项2：
//	//Person(10)是匿名对象，当前行结束后，系统会立即回收匿名对象
//	//不要利用拷贝构造函数，初始化匿名对象
//	//Person(p3);  -->出问题：“Person p3”: 重定义
//	//编译器会认为Person(p3) == Person p3 
//
//	//3.隐式转换法：
//	Person p1;
//	Person p2 = 10;    //相当于Person p2 = Person(10);
//	Person p3 = p2;    //相当于Person p3 = Person(p2);
//	return 0;
//}


//4>拷贝构造函数调用时机：
//使用一个已经创建好的对象初始化新对象
//以值传递的形式给函数传参
//以值方式返回局部对象


//5>构造函数调用规则：
//默认情况下，c++编译器至少给一个类添加3个默认函数：
//默认构造函数（无参，函数体为空）
//默认析构函数（无参，函数体为空）
//默认拷贝构造函数，对属性进行值拷贝

//自定义了有参构造函数，编译器不再提供默认无参构造函数，任提供拷贝构造函数
//自定义了拷贝构造函数，编译器不再提供其他构造函数

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_age;
//	/*Person()
//	{
//		cout << "调用默认无参构造函数" << endl;
//	}*/
//	/*Person(int age)
//	{
//		cout << "调用有参构造函数" << endl;
//		m_age = age;
//	}*/
//	/*Person(const Person& p)
//	{
//		cout << "调用拷贝构造函数" << endl;
//		m_age = p.m_age;
//	}*/
//	
//};
//
//int main()
//{
//	//Person p1;   //错误：类 "Person" 不存在默认构造函数
//	//Person p(18);  //错误：没有与参数列表匹配的构造函数 "Person::Person" 实例
//	return 0;
//}



//6>深拷贝和浅拷贝：
//浅拷贝：简单的赋值拷贝（默认拷贝构造函数是浅拷贝）
//深拷贝：在堆区重新申请空间，进行拷贝操作
//***注意：成员属性包括堆区开辟变量时，要自定义拷贝构造函数（深拷贝）

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_age;
//	int* m_height;
//	Person(int age, int height)
//	{
//		m_age = age;
//		m_height = new int(height);
//	}
//	Person(const Person& p)
//	{
//		//默认拷贝构造函数是浅拷贝（如下代码）
//		//如果成员属性有在堆区开辟的变量，会直接赋值相同的地址
//		//析构函数中，同一块空间被释放两次，发生错误
//		/*m_age = p.m_age;
//		m_height = p.m_height;*/
//
//		//深拷贝：
//		m_age = p.m_age;
//		m_height = new int(*p.m_height);
//	}
//	~Person()
//	{
//		//析构函数的作用：释放在堆区开辟的空间
//		if (m_height != NULL)
//		{
//			delete m_height;
//			m_height = NULL;
//		}
//	}
//};
//int main()
//{
//	Person p1(19, 158);
//	cout << "pl: " << p1.m_age << " " << *p1.m_height << endl;
//	Person p2(p1);
//	cout << "p2: " << p2.m_age << " " << *p2.m_height << endl;
//	return 0;
//}



//7>初始化成员列表：-->尽量使用初始化成员列表来初始化
//语法：构造函数（）：属性1（值1），属性2（值2）...

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_a;
//	int m_b;
//	int m_c;
//	Person(int a, int b, int c) :m_a(a), m_b(b), m_c(c) { ; }
//
//};
//int main()
//{
//	Person p(10, 20, 30);
//	cout << p.m_a << " " << p.m_b << " " << p.m_c << endl;
//		return 0;
//}



//8>类对象作为类成员：
//当一个A类中包含其他B类对象时：
//先调用B类的构造函数，再调用A类的构造函数
//先调用A类的析构函数，再调用B类的析构函数

//类对象作为类成员初始化时：必须使用成员初始化列表
//类对象成员不能在构造函数体内通过赋值初始化
//初始化列表会调用成员对象的构造函数，确保它们在构造函数体执行之前已经被正确初始化

//#include<iostream>
//#include<string>
//using namespace std;
//class Phone
//{
//public:
//	int m_id;
//	string m_pname;
//	Phone(int id, string pname) :m_id(id), m_pname(pname)
//	{
//		cout << "Phone的构造函数调用" << endl;
//	}
//	~Phone()
//	{
//		cout << "Phone的析构函数调用" << endl;
//	}
//};
//class Person
//{
//public:
//	string m_name;
//	Phone m_phone;   //对象成员
//
//	//注意对象成员的初始化  
//	Person(string name, int id, string pname) :m_name(name), m_phone(id, pname)  
//	{
//		cout << "Person的构造函数调用" << endl;
//	}
//	~Person()
//	{
//		cout << "Person的析构函数调用" << endl;
//	}
//
//};
//int main()
//{
//	Person("lyl", 19, "vivo");
//	return 0;
//}



//9>静态成员：
