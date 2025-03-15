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
//静态成员变量：
//所有对象共享一份数据
//在编译阶段分配内存
//类内声明，类外初始化

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	static int m_a;  //类内声明
//};
//
////类外初始化
//int Person::m_a = 10;
//
//void test1()
//{
//	//共享一份数据
//	/*Person p;
//	cout << p.m_a << endl;
//	Person p2;
//	p2.m_a = 30;
//	cout << p.m_a << endl;*/
//}
//
//void test2()
//{
//	//1.通过类对象访问静态成员变量
//	Person p;
//	cout << p.m_a << endl;
//	//2.通过类名访问静态成员变量
//	cout << Person::m_a << endl;
//}
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}


//静态成员函数：
//所有对象共享一个函数
//静态成员函数只能访问静态成员变量

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	static int m_a;
//	int m_b;
//	static void func()
//	{
//		m_a = 10;
//		//m_b = 10;    //非静态成员引用必须与特定对象相对
//		cout << "func()函数调用" << endl;
//	}
//};
//
//int Person::m_a = 0;
//
//int main()
//{
//	//1.通过类对象访问静态成员函数
//	Person p;
//	p.func();
//	//2.通过类名访问静态成员函数
//	Person::func();
//	return 0;
//}



//3.c++对象模型和this指针：
//1>成员变量和成员函数分开存储：
//空对象所占内存大小为1字节
//只有非静态成员变量在类对象上

//#include<iostream>
//using namespace std;
//class Person
//{
//};
//
//class Student
//{
//public:
//	int m_a;  //非静态成员变量在类对象上
//	static int m_b;   //静态成员变量不在类对象上
//
//	void func1()    //非静态成员函数不在类对象上
//	{ }
//	static void func2()   //静态成员函数不在类对象上
//	{ }
//};
//void test1()
//{
//	Person p;
//	cout << sizeof(p) << endl;  //1字节
//	//区分空对象占内存的位置，每个空对象有一个独一无二的内存地址
//}
//
//void test2()
//{
//	Student s;
//	cout << sizeof(s) << endl;    //4字节
//}
//
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}


//2>this指针：指向某个具体对象的指针

//每一个非静态成员函数只会诞生一个函数实例，也就是说多个同类型的对象会共用一块代码
//这一块代码通过this指针判断是哪一个对象调用函数
//this指针指向被调用的成员函数所属的对象

//this指针是隐含在每一个非静态成员函数内的一种指针
//this指针不需要定义，直接使用就行


//*1.解决名字冲突问题
//#include<iostream>
//class Person
//{
//public:
//	int age;
//	Person(int age)/*:age(age)*/
//	{
//		//age = age;    //名称相同，编译器认为都是形参，没有给成员属性赋值
//		this->age = age;   //成员初始化列表也可以解决
//	}
//};
//using namespace std;
//int main()
//{
//	Person p(19);
//	cout << p.age << endl;
//	return 0;
//}


//*2.在成员函数中返回对象本身（return *this） --》链式编程
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int age;
//	Person(int age)
//	{
//		this->age = age;
//	}
//	//注意：返回时一定要返回引用，不然返回的是该对象的拷贝对象
//	//不是该对象，无法实现链式编程
//	Person& Add(Person& p)
//	{
//		age += p.age;
//		return *this;
//	}
//};
//int main()
//{
//	Person p1(10);
//	Person p2(10);
//	//链式编程
//	p1.Add(p2).Add(p2).Add(p2);  
//	//返回Person& -->40
//	//返回Person -->20
//	cout << p1.age << endl;
//	return 0;
//}



//3>空指针访问成员函数:
//C++中空指针是可以调用成员函数的,但要注意到有无this指针的情况

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int age;
//	//该函数正常调用
//	void PrintClassName()  
//	{
//		cout << "Person" << endl;
//	}
//	//该函数报错
//	//因为使用成员变量时:age  -->实际上:  this->age  
//	//使用了this指针,但是this为空指针,故报错
//	void PrintAge()
//	{
//		//增加代码健壮性
//		if (this == NULL)
//			return;
//
//		cout << age << endl;   //报错:this是空指针
//	}
//};
//int main()
//{
//	Person* p = NULL;
//	//p->PrintClassName();
//	p->PrintAge();
//	return 0;
//}



//4>const修饰成员函数:
//常函数:成员函数后加const
//常函数内不能修改成员属性
//成员属性加上mutable关键字修饰后,常函数内也可以修改

//常对象:对象前加const
//常对象只能调用常函数

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_a;
//	mutable int m_b;
//	//this指针实质上是指针常量,本例中为 Person* const this
//	//this的指向不能修改
//	//成员函数加上const修饰后:指针变为 const Person* const this
//	//即指针指向的值也不能修改,而 m_a == this->m_a,故不能修改
//	void func1() const
//	{
//		//m_a = 10;   //不可以修改
//		m_b = 10;   //可以修改
//	}
//	void func2()
//	{
//		m_a = 10;
//	}
//};
//int main()
//{
//	//常对象只能调用常成员函数
//	//因为普通成员函数能修改成员属性,常对象调用就能修改成员属性
//	//而常对象不能修改成员属性
//	const Person p;
//	//p.m_a = 10;   //报错:表达式必须是可修改的左值
//	p.m_b = 10;
//	p.func1();
//	//p.func2();   //报错
//	return 0;
//}



//4.友元:
// 目的:让一个函数或类访问另一个类中的私有属性
// 关键字:friend

//1>全局函数做友元:
//在类中用friend修饰要访问私有属性的全局函数的声明

//#include<iostream>
//using namespace std;
//class Building
//{
//	//友元
//	friend void GoodGay(Building& building);
//
//private:
//	string m_bedroom;
//public:
//	string m_settingroom;
//	Building(string settingroom, string bedroom) :m_settingroom(settingroom), m_bedroom(bedroom)
//	{
//		;
//	}
//};
//
//void GoodGay(Building& building)
//{
//	cout << "好基友全局函数正在访问: " << building.m_settingroom << endl;
//	cout << "好基友全局函数正在访问: " << building.m_bedroom << endl;   //报错
//}
//int main()
//{
//	Building building("客厅", "卧室");
//	GoodGay(building);
//	return 0;
//}


//2>类做友元:

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Building;
//
//class GoodGay
//{
//public:
//	Building* building;
//	GoodGay();
//	void visit();
//	~GoodGay();
//};
//
//class Building
//{
//	friend class GoodGay;
//private:
//	string m_bedroom;
//public:
//	string m_settingroom;
//	Building();
//};
//
////成员函数可以在类外定义
//GoodGay::GoodGay()
//{
//	//******* new分配内存，同时调用对象的构造函数来初始化这块内存
//	building = new Building;
//}
//
//Building::Building()
//{
//	m_settingroom = "客厅";
//	m_bedroom = "卧室";
//}
//
//void GoodGay::visit()
//{
//	cout << "好基友类正在访问: " << building->m_settingroom << endl;
//	cout << "好基友类正在访问: " << building->m_bedroom << endl;
//}
//
//GoodGay::~GoodGay()
//{
//	delete building;
//}
//
//int main()
//{
//	GoodGay gg;
//	gg.visit();
//	return 0;
//}


//3>成员函数做友元:

//#include<iostream>
//using namespace std;
//class Building;
//class GoodGay
//{
//public:
//	Building* building;
//	GoodGay();
//	void visit();
//	void visit2();
//	~GoodGay();
//};
//
//class Building
//{
//	//告诉编译器，GoodGay下的visit()函数是我的好朋友，可以访问我的私有成员属性
//	friend void GoodGay::visit();
//
//private:
//	string m_bedroom;
//public:
//	string m_settingroom;
//	Building();
//};
//
//Building::Building()
//{
//	m_settingroom = "客厅";
//	m_bedroom = "卧室";
//}
//
//GoodGay::GoodGay()
//{
//	building = new Building;
//}
//
//GoodGay::~GoodGay()
//{
//	delete building;
//}
//
//void GoodGay::visit()
//{
//	cout << "visit 函数正在访问： " << building->m_settingroom << endl;
//	cout << "visit 函数正在访问： " << building->m_bedroom << endl;
//	
//}
//
//void GoodGay::visit2()
//{
//	cout << "visit2 函数正在访问： " << building->m_settingroom << endl;
//	//cout << "visit 函数正在访问： " << building->m_bedroom << endl;
//}
//int main()
//{
//	GoodGay gg;
//	gg.visit();
//	gg.visit2();
//	return 0;
//}



//5.运算符重载:
//对已有运算符重新进行定义，赋予其另一种功能，使其使用不同的数据类型

//1>加号（+）运算符重载：

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_a;
//	int m_b;
//	//通过成员函数重载+号：
//	/*Person operator+(Person& p)
//	{
//		Person tmp;
//		tmp.m_a = this->m_a + p.m_a;
//		tmp.m_b = this->m_b + p.m_b;
//		return tmp;
//	}*/
//};
//
////通过全局函数重载+号：
//Person operator+(Person& p1, Person& p2)
//{
//	Person tmp;
//	tmp.m_a = p1.m_a + p2.m_a;
//	tmp.m_b = p1.m_b + p2.m_b;
//	return tmp;
//}
//
////函数重载：
//Person operator+(Person& p, int n)
//{
//	Person tmp;
//	tmp.m_a = p.m_a + n;
//	tmp.m_b = p.m_b + n;
//	return tmp;
//}
//
//int main()
//{
//	Person p1;
//	p1.m_a = 10;
//	p1.m_b = 10;
//	Person p2;
//	p2.m_a = 20;
//	p2.m_b = 20;
//
//	//简化版：
//	//Person p3 = p1 + p2;
//	
//	//通过成员函数重载+号的本质：
//	//Person p3 = p1.operator+(p2);
//
//    //通过全局函数重载+号的本质：
//	//Person p3 = operator+(p1, p2);
//	
//
//	//运算符重载 也能发生函数重载
//	Person p3 = p1 + 100;
//	//Person p3 = 100 + p1;    //没有与这些操作数匹配的 "+" 运算符
//	//*********注意：重载运算符左右操作数必须严格与函数参数一一对应！！！！
//
//	cout << p3.m_a << " " << p3.m_b << endl;
//	return 0;
//}



//2>左移（<<）运算符重载：输出自定义类型
//std::cout 是 std::ostream 类的一个实例

//重载<<运算符不能通过成员函数：
//<< 运算符的第一个参数必须是 std::ostream& 类型
//而类的成员函数的第一个参数总是隐式的 this 指针
//cout<<p -->本质：cout.operator<<(class& p) 或 operator<<(ostream& cout,class& p)

//要实现链式调用：必须返回ostream&

//#include<iostream>
//using namespace std;
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//private:
//	int m_a;
//	int m_b;
//public:
//	Person(int a, int b) :m_a(a), m_b(b) { ; }
//
//	/*ostream& operator<<(ostream& cout)
//	{
//		cout << m_a << " " << m_b << endl;
//		return cout;
//	}*/
//};
//
//ostream& operator<<(ostream& cout, Person& p)
//{
//	cout << p.m_a << " " << p.m_b;
//	return cout;
//}
//
//int main()
//{
//	Person p(1, 2);
//	cout << p << endl;
//	//使用成员函数：
//	//p << cout << endl;
//	return 0;
//}


//3>递增（++）运算符重载：

//#include<iostream>
//using namespace std;
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger m);
//private:
//	int m_int;
//public:
//	MyInteger()
//	{
//		m_int = 0;
//	}
//
//	//前置++
//	//必须返回ClassName& 才能实现链式编程 ++（++m）
//	MyInteger operator++()
//	{
//		m_int++;
//		return *this;
//	}
//
//	//后置++
//	//int为占位参数，是编译器设置用来区分前置和后置的
//	//后置返回值，不能链式编程
//	MyInteger operator++(int)
//	{
//		MyInteger tmp = *this;
//		m_int++;
//		return tmp;
//	}
//
//	//递减操作符：
//	MyInteger& operator--()
//	{
//		m_int--;
//		return *this;
//	}
//
//	MyInteger operator--(int)
//	{
//		MyInteger tmp = *this;
//		m_int--;
//		return tmp;
//	}
//};
//
//ostream& operator<<(ostream& cout, MyInteger m)
//{
//	cout << m.m_int;
//	return cout;
//}
//
//int main()
//{
//	MyInteger m;
//	//cout << ++(++m) << endl;
//	//cout << m << endl;
//	//cout << (m++)++ << endl;
//	//cout << m << endl;
//	//cout << --(--m) << endl;
//	cout << m-- << endl;
//	cout << m << endl;
//	return 0;
//}



//4>赋值（=）运算符重载：
//c++编译器至少给一个类添加4个函数：
//默认构造函数（无参，函数体为空）
//默认析构函数（无参，函数体为空）
//默认拷贝构造函数，为值拷贝（浅拷贝）
//赋值运算符重载（operator=），为值拷贝（浅拷贝）
//当成员属性包含堆中创建的变量时，赋值操作会导致堆中同一块空间被释放两次

//一旦成员属性中包含堆中创建的变量时：
//拷贝构造函数和赋值运算符重载函数都要自己定义——>变为深拷贝

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int* m_age;
//	Person(int age)
//	{
//		m_age = new int(age);
//	}
//	~Person()
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//	}
//
//	//重载运算符=
//	Person& operator= (Person& p)
//	{
//		//*******释放之前分配的空间
//		delete m_age;
//		m_age = NULL; 
//
//		//重新分配空间并拷贝值
//		m_age = new int(*p.m_age);
//		return *this;
//	}
//};
//
//int main()
//{
//	Person p1(18);
//	Person p2(20);
//	Person p3(30);
//
//	//拷贝构造函数和operator=的区别：
//	//Person p4(p1); -->调用的是拷贝构造函数
//	//Person p4(40);  p4=p1;  -->调用的是赋值运算符
//
//	p3 = p2 = p1;
//	cout << *p1.m_age << " " << *p2.m_age << " " << *p3.m_age << endl;
//	return 0;
//}



//5>关系运算符(>, <, ==, !=)重载：

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	string m_name;
//	int m_age;
//	Person(string name, int age) :m_name(name), m_age(age) { ; }
//
//	bool operator==(Person& p)
//	{
//		if (m_name == p.m_name && m_age == p.m_age)
//			return true;
//		return false;
//	}
//	bool operator!=(Person& p)
//	{
//		if (m_name == p.m_name && m_age == p.m_age)
//			return false;
//		return true;
//	}
//};
//int main()
//{
//	Person p1("Tom", 19);
//	Person p2("Tom", 19);
//	if (p1 != p2)
//		cout << "p1和p2不相等" << endl;
//	else
//		cout << "p1和p2相等" << endl;
//	
//	return 0;
//}


//6>函数调用运算符()重载：
//因为重载后使用的方式很像函数调用，所以被称为仿函数
//仿函数没有固定写法，很灵活

//#include<iostream>
//#include<string>
//using namespace std;
//class MyPrint
//{
//public:
//	void operator()(string text)
//	{
//		cout << text << endl;
//	}
//};
//
//void Print(string text)
//{
//	cout << text << endl;
//}
//void test01()
//{
//	MyPrint myprint;
//	myprint("hello world");
//	Print("hello world");
//}
//
//class MyAdd
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//void test02()
//{
//	MyAdd myadd;
//	int ret = myadd(1, 2);
//	cout << ret << endl;
//
//	//匿名函数对象：
//	//代码所在行执行结束后就被销毁
//	cout << MyAdd()(2, 3) << endl;
//
//
//}
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}


//6.继承:减少重复代码

//1>继承的基本语法：class 子类（派生类）：继承方式 父类（基类）
//#include<iostream>
//using namespace std;
//class BasePage
//{
//public:
//	void Header()
//	{
//		cout << "首页，注册，登录，公开课 ...(公共头部)" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心，交流合作，站内导航...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "Java,Python,C++...（公共分类列表）" << endl;
//	}
//};
//
////继承：
//class Java:public BasePage
//{
//public:
////	void Header()
////	{
////		cout << "首页，注册，登录，公开课 ...(公共头部)" << endl;
////	}
////	void footer()
////	{
////		cout << "帮助中心，交流合作，站内导航...(公共底部)" << endl;
////	}
////	void left()
////	{
////		cout << "Java,Python,C++...（公共分类列表）" << endl;
////	}
//	void java()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//
//class Python : public BasePage
//{
//public:
////	void Header()
////	{
////		cout << "首页，注册，登录，公开课 ...(公共头部)" << endl;
////	}
////	void footer()
////	{
////		cout << "帮助中心，交流合作，站内导航...(公共底部)" << endl;
////	}
////	void left()
////	{
////		cout << "Java,Python,C++...（公共分类列表）" << endl;
////	}
//	void python()
//	{
//		cout << "python学科视频" << endl;
//	}
//};
//
//void test01()
//{
//	Java java;
//	java.Header();
//	java.footer();
//	java.left();
//	java.java();
//
//	cout << "---------------------------" << endl;
//	Python python;
//	python.Header();
//	python.footer();
//	python.left();
//	python.python();
//}
//int main()
//{
//	test01();
//	return 0;
//}


//2>继承方式：
//公共继承（public），保护继承（protected），私有继承（private）
//三种继承方式下，子类都不能访问父类的private成员
//public继承下，继承的成员权限不变
//protected继承下，继承的成员权限都变为protected
//private继承下，继承的成员权限都变为private

//#include<iostream>
//using namespace std;
//class Father
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//
////公共继承：
//class Son1 :public Father
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;   //报错：子类不能访问父类中的private成员
//	}
//};
//
//void test01()
//{
//	Son1 son;
//	son.m_a = 10;     //public继承下，父类中的public成员在子类中也是public
//	//son.m_b = 10;     //报错：public继承下，父类中的protected成员在子类中也是protected
//}
//
////保护继承：
//class Son2 :protected Father
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;    //报错：子类不能访问父类中的private成员
//	}
//};
//
//void test02()
//{
//	Son2 son;
//	//报错：protected继承下，父类中的public,protected成员在子类中都是protected
//	//son.m_a = 10;    
//	//son.m_b = 10;
//}
//
////私有继承：
//class Son3 :private Father
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;      //报错：子类不能访问父类中的private成员
//	}
//};
//
//class GrandSon :public Son3
//{
//public:
//	void func()
//	{
//		//报错：private继承下，父类中的public,protected成员在子类中都是private
//		//m_a = 10;
//		//m_b = 10;
//	}
//};
//
//int main()
//{
//	return 0;
//}


//3>继承中的对象模型：
//父类中所有非静态成员属性都会被子类继承
//父类中的私有成员也被子类继承了，只是被编译器隐藏了无法访问

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//
//class Son : public Base
//{
//public:
//	int m_d;
//};
//
//int main()
//{
//	cout << sizeof(Son) << endl;   //size为16字节，说明父类中的私有成员也被继承了
//	return 0;
//}

//可以使用vs 2022 开发人员命令提示符 
//通过命令 cl /d1 reportSingleClassLayout类名 所在文件名  查看子类的成员组成



//4>继承中构造和析构顺序：
//继承中，先调用父类的构造函数，再调用子类的构造函数，析构的调用顺序相反（栈区：先进后出）

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base的构造函数" << endl;
//	}
//	~Base()
//	{
//		cout << "Base的析构函数" << endl;
//	}
//};
//
//class Son :public Base
//{
//public:
//	Son()
//	{
//		cout << "Son的构造函数" << endl;
//	}
//	~Son()
//	{
//		cout << "Son的析构函数" << endl;
//	}
//};
//int main()
//{
//	//Base b;
//	Son s;
//	return 0;
//}



//5>继承同名成员处理方式：
//如果子类和父类中有同名成员：
//访问子类同名成员，直接访问即可
//访问父类同名成员，需要加作用域
//原因：当子类拥有与父类同名的成员函数时，子类会隐藏父类中的同名成员函数（包括重载函数），因此要加作用域

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	int m_a;
//	Base() :m_a(100) { ; }
//
//	void func()
//	{
//		cout << "Base的func函数调用" << endl;
//	}
//	//重载函数：
//	void func(int n)
//	{
//		cout << "Base的func(int n)函数调用" << endl;
//	}
//};
//
//class Son : public Base
//{
//public:
//	int m_a;
//	Son() :m_a(200) { ; }
//
//	void func()
//	{
//		cout << "Son的func函数调用" << endl;
//	}
//};
//
////同名成员属性：
//void test01()
//{
//	Son s;
//	cout << "Son的m_a: " << s.m_a << endl;
//	cout << "Base的m_a: " << s.Base::m_a << endl;
//}
//
////同名成员函数：
//void test02()
//{
//	Son s;
//	s.func();
//	s.Base::func();
//	//s.func(3);  //报错：函数调用中的参数太多 -->父类中所有同名函数都被隐藏（包括重载函数）
//	s.Base::func(3);
//}
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}


//6>继承同名静态成员处理方式：
//与继承普通成员处理方式一样，不过要注意静态成员有两种访问方式

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	static int m_a;
//	static void func()
//	{
//		cout << "Base下func()函数调用" << endl;
//	}
//};
//
//int Base::m_a = 100;
//
//class Son :public Base
//{
//public:
//	static int m_a;
//	static void func()
//	{
//		cout << "Son下func()函数调用" << endl;
//	}
//};
//
//int Son::m_a = 200;
//
//void test01()
//{
//	//1.通过对象访问：
//	Son s;
//	cout << "Son: " << s.m_a << endl;
//	cout << "Base: " << s.Base::m_a << endl;
//
//	//2.通过类名访问：
//	cout << "Son: " << Son::m_a  << endl;
//	cout << "Base: " << Son::Base::m_a  << endl;
//	//注意：第一个::代表通过类名访问，第二个::代表在父类Base作用域下
//}
//
//void test02()
//{
//	//1.通过对象访问：
//	Son s;
//	s.func();
//	s.Base::func();
//
//	//2.通过类名访问：
//	Son::func();
//	Son::Base::func();
//
//}
//
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}


//7>多继承语法：
//C++允许一个类继承多个类
//格式：class 子类：继承方式 父类1，继承方式 父类2 ...

//#include<iostream>
//using namespace std;
//class Base1
//{
//public:
//	int m_a;
//	Base1() :m_a(100) { ; }
//};
//
//class Base2
//{
//public:
//	int m_a;
//	Base2() :m_a(200) { ; }
//};
//
//class Son :public Base1, public Base2
//{
//public:
//	int m_c, m_d;
//	Son() :m_c(300), m_d(400) { ; }
//
//};
//int main()
//{
//	Son s;
//	cout << sizeof(Son) << endl;
//	cout << s.Base1::m_a << endl;
//	cout << s.Base2::m_a << endl;
//	//父类中有同名成员时，使用要加作用域
//	//故实际开发中不建议使用
//	return 0;
//}



//8>菱形继承：
//B类，C类分别继承了A类，D类又同时继承了B类和C类，称为菱形继承（钻石继承）
//菱形继承导致子类（D类）继承了两份相同的数据，导致资源浪费
//可以通过【虚继承】的方式解决菱形继承的问题

//#include<iostream>
//using namespace std;
//class Animals
//{
//public:
//	int m_age;
//};
//
////继承之前加上关键字virtual变为虚继承
////Animals类称为虚基类
//
////原理：
////虚继承下，子类会继承虚基类指针（vbptr）,指向一个虚基类表（vbtable）
////虚基类表中记录了偏移量，指针加上偏移量后指向m_age(只有一份数据)
//
//
//class Sheep : virtual public Animals
//{
//};
//
//class Tuo : virtual public Animals
//{
//};
//
//class SheepTuo :public Sheep, public Tuo
//{
//};
//
//int main()
//{
//	SheepTuo st;
//	//cout << st.m_age << endl;    //报错：出现二义性：不知道是Sheep类还是Tuo类的m_age
//	//可以通过加作用域的方法分别访问Sheep类和Tuo类的m_age，但是没意义且浪费空间
//
//	st.m_age = 20;
//	st.Sheep::m_age = 19;   //对同一份数据进行更改
//	cout << st.m_age << endl;  //19
//	return 0;
//}


//没使用虚继承：
//class SheepTuo  size(8) :
//	+-- -
//	0 | +-- - (base class Sheep)
//	0      | | +-- - (base class Animals)
//	0      | | | m_age
//	| | +-- -
//	| +-- -
//	4 | +-- - (base class Tuo)
//	4      | | +-- - (base class Animals)
//	4      | | | m_age
//	| | +-- -
//	| +-- -
//	+-- -


//使用虚继承：
//	class SheepTuo  size(12) :
//	+-- -
//	0 | +-- - (base class Sheep)
//	0      | | {vbptr}
//| +-- -
//4 | +-- - (base class Tuo)
//4      | | {vbptr}
//| +-- -
//+-- -
//+-- - (virtual base Animals)
//8 | m_age
//+ -- -
//
//SheepTuo::$vbtable@Sheep@:
//0 | 0
//1 | 8 (SheepTuod(Sheep + 0)Animals)
//
//SheepTuo::$vbtable@Tuo@:
//0 | 0
//1 | 4 (SheepTuod(Tuo + 0)Animals)
//vbi : class  offset o.vbptr  o.vbte fVtorDisp
//Animals       8       0       4 0




//7.多态:
//多态分为两类：
//静态多态：函数重载和运算符重载属于静态多态，复用函数名 -->函数地址早绑定（编译阶段确定函数地址）
//动态多态：派生类和【虚函数】实现运行时多态 -->函数地址晚绑定（运行阶段确定函数地址）

//1>多态的基本语法：
//多态满足条件：*1.有继承关系  *2.子类重写父类中的虚函数
//多态使用条件：父类指针或引用指向子类对象

//重写：函数返回值类型，函数名，参数列表完全一致

//#include<iostream>
//using namespace std;
//class Animals
//{
//public:
//	//父类中：虚函数
//	virtual void Speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//class Cat : public Animals
//{
//public:
//	void Speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//
//class Dog : public Animals
//{
//public:
//	void Speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//};
//
//void DoSpeak(Animals& animal)   //子类对象可以作为参数传入原本参数为父类的函数
//{
//	animal.Speak();
//}
//
//int main()
//{
//	//没使用虚函数（多态）：
//	//打印“动物在说话”，为静态多态，函数地址早绑定
//	
//	//使用虚函数（多态）：
//	//打印小猫在说话，小狗在说话，为动态多态
//
//	Cat cat;
//	Dog dog;
//	DoSpeak(cat);  
//	DoSpeak(dog);
//
//	return 0;
//}


//2>多态的原理刨析：

//#include<iostream>
//using namespace std;
//class Animals
//{
//public:
//	virtual void Speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//class Cat : public Animals
//{
//public:
//	void Speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//
//void DoSpeak(Animals& animal)   
//{
//	animal.Speak();
//}
//
//int main()
//{
//	//Animals类中的speak()函数：
//	//没加vitual关键字：大小为1字节
//	//加vitual关键字：大小为4/8字节（x64/x86）-->产生了一个指针
//	cout << sizeof(Animals) << endl;  
//
//	return 0;
//}


//没加vitual:
//class Animals   size(1) :
//	+-- -
//	+-- -

//加vitual:
//class Animals   size(4) :
//	+-- -
//	0 | {vfptr}
//+ -- -
//
//Animals::$vftable@ :
//	| &Animals_meta
//	| 0
//	0 | &Animals::Speak
//
//	Animals::Speak this adjustor : 0

//函数 F 变为虚函数后，会生成一个虚函数（表）指针 vfptr,指向该类 A 的虚函数表 vftable
//虚函数表 vftable 中存放了该类 A 作用域下的函数 F 地址
//当该类 A 的子类 B 没有重写函数 F 时：子类 B 继承 A 类的 vfptr 指针
//并指向子类 B 自己的虚函数表 vftable ，里面存放的是类 A 作用域下的函数 F 地址
//当 B 类重写函数 F 时：继承的 vfptr 指针指向子类 B 自己的虚函数表 vftable 
//但是里面存放的是 B 类作用域下的函数 F 地址



//3>多态案例一：计算类

//#include<iostream>
//#include<string>
//using namespace std;
//
////普通写法：
//class Calculator
//{
//public:
//	int m_num1;
//	int m_num2;
//
//	int GetResult(string oper)
//	{
//		if (oper == "+")
//			return m_num1 + m_num2;
//		else if (oper == "-")
//			return m_num1 - m_num2;
//		else if (oper == "*")
//			return m_num1 * m_num2;
//		//如果想扩展新功能，需要修改源代码
//		//在实际开发中，提倡开闭原则
//		//开闭原则：对扩展进行开放，对修改进行关闭
//	}
//};
//
//void test01()
//{
//	Calculator c;
//	c.m_num1 = 10;
//	c.m_num2 = 10;
//	cout << c.GetResult("+") << endl;
//	cout << c.GetResult("-") << endl;
//	cout << c.GetResult("*") << endl;
//}
//
//
////多态写法：
////好处：代码组织结构清晰，可读性强，利于前期和后期的维护
//
////抽象类
//class AbstractCalculator
//{
//public:
//	int m_num1;
//	int m_num2;
//
//	virtual int GetResult()
//	{
//		return 0;
//	}
//};
//
////加法类
//class AddCalculator :public AbstractCalculator
//{
//public:
//    int GetResult()
//	{
//		return m_num1 + m_num2;
//	}
//};
//
////减法类
//class SubCalculator :public AbstractCalculator
//{
//public:
//	int GetResult()
//	{
//		return m_num1 - m_num2;
//	}
//};
//
////乘法类
//class MulCalculator :public AbstractCalculator
//{
//public:
//	int GetResult()
//	{
//		return m_num1 * m_num2;
//	}
//};
//
//void test02()
//{
//	AbstractCalculator* abc = new AddCalculator;
//	abc->m_num1 = 10;
//	abc->m_num2 = 10;
//	cout << abc->GetResult() << endl;
//	delete abc;
//
//	abc = new SubCalculator;
//	abc->m_num1 = 10;
//	abc->m_num2 = 10;
//	cout << abc->GetResult() << endl;
//	delete abc;
//
//	abc = new MulCalculator;
//	abc->m_num1 = 10;
//	abc->m_num2 = 10;
//	cout << abc->GetResult() << endl;
//	delete abc;
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}



//4>纯虚函数和抽象类：-->规范使用多态

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	//纯虚函数
//	virtual void Func() = 0;
//	//含有纯虚函数的类叫作抽象类
//	//抽象类的特点：
//	//1.抽象类不能实例化对象
//	//2.抽象类的子类必须重写纯虚函数，否则也不能实例化对象
//};
//
//class Son :public Base
//{
//public:
//	void Func()
//	{
//		cout << "Func()函数调用" << endl;
//	}
//};
//int main()
//{
//	//Base b;
//	//Base* b = new Base;
//	Base* b = new Son;
//	b->Func();
//	return 0;
//}



//5>多态案例二：制作饮品

//#include<iostream>
//using namespace std;
//class AbstractDrinking
//{
//public:
//	virtual void Boil() = 0;
//	virtual void Brew() = 0;
//	virtual void PourInCap() = 0;
//	virtual void AddSomething() = 0;
//	void MakingDrink()
//	{
//		Boil();
//		Brew();
//		PourInCap();
//		AddSomething();
//	}
//};
//
//class Coffee :public AbstractDrinking
//{
//public:
//	void Boil()
//	{
//		cout << "煮农夫山泉" << endl;
//	}
//	void Brew()
//	{
//		cout << "冲泡咖啡" << endl;
//	}
//	void PourInCap()
//	{
//		cout << "倒入玻璃杯中" << endl;
//	}
//	void AddSomething()
//	{
//		cout << "加牛奶" << endl;
//	}
//};
//
//class Tea :public AbstractDrinking
//{
//public:
//	void Boil()
//	{
//		cout << "煮百岁山" << endl;
//	}
//	void Brew()
//	{
//		cout << "冲泡茶叶" << endl;
//	}
//	void PourInCap()
//	{
//		cout << "倒入红酒杯中" << endl;
//	}
//	void AddSomething()
//	{
//		cout << "加枸杞" << endl;
//	}
//};
//
//void DoWork(AbstractDrinking* abd)
//{
//	abd->MakingDrink();
//	delete abd;
//}
//
//int main()
//{
//	DoWork(new Coffee);
//	cout << "--------------------" << endl;
//	DoWork(new Tea);
//	return 0;
//}



//6>虚析构和纯虚析构(?)：
//多态使用时，如果子类有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码，造成内存泄露
//解决方法：使用虚析构或纯虚析构
//共性：可以解决父类指针释放子类；都要有具体的函数实现
//差异：如果是纯虚析构函数，该类属于抽象类，无法实例化对象

//总结：只有子类中有堆区数据存在时，才需要写虚析构和纯虚析构

//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//	virtual void speak() = 0;
//	Animal()
//	{
//		cout << "Animal构造函数调用 " << endl;
//	}
//
//	//虚析构函数：
//	/*virtual*/ ~Animal()
//	{
//		cout << "Animal虚析构函数调用 " << endl;
//	}
//
//	//纯虚析构函数：
//	//virtual ~Animal() = 0;   //声明
//};
//
////实现
////Animal::~Animal()
////{
////	cout << "Animal纯虚析构函数调用" << endl;
////}
//
//class Cat :public Animal
//{
//public:
//	string* m_name;
//	void speak()
//	{
//		cout << *m_name << "小猫在说话" << endl;
//	}
//	Cat(string name)
//	{
//		cout << "Cat构造函数调用" << endl;
//		m_name = new string(name);
//	}
//	~Cat()
//	{
//		cout << "Cat析构函数调用" << endl;
//		if (m_name != NULL)
//		{
//			delete m_name;
//			m_name = NULL;
//		}
//	}
//};
//int main()
//{
//	Animal* animal = new Cat("Tom");
//	animal->speak();
//	delete animal;
//
//	return 0;
//}



//7>多态案例三：电脑组装

//#include<iostream>
//using namespace std;
////抽象类
//class Cpu
//{
//public:
//	virtual void Calculate() = 0;
//};
//
//class VedioCard
//{
//public:
//	virtual void display() = 0;
//};
//
//class Memory
//{
//public:
//	virtual void Storage() = 0;
//};
//
//
//class Computer
//{
//private:
//	Cpu* m_cpu;
//	VedioCard* m_vc;
//	Memory* m_mem;
//public:
//	Computer(Cpu* cpu, VedioCard* vc, Memory* mem)
//	{
//		m_cpu = cpu;
//		m_vc = vc;
//		m_mem = mem;
//	}
//	void Dowork()
//	{
//		m_cpu->Calculate();
//		m_vc->display();
//		m_mem->Storage();
//	}
//	~Computer()
//	{
//		cout << "Computer析构函数调用" << endl;
//		delete m_cpu;
//		delete m_vc;
//		delete m_mem;
//	}
//};
//
////Inter
//class InterCpu :public Cpu
//{
//public:
//	void Calculate()
//	{
//		cout << "Inter的CPU开始计算了" << endl;
//	}
//};
//
//class InterVedioCard :public VedioCard
//{
//public:
//	void display()
//	{
//		cout << "Inter的显卡开始显示了" << endl;
//	}
//};
//
//class InterMemory:public Memory
//{
//public:
//	void Storage()
//	{
//		cout << "Inter的内存条开始存储了" << endl;
//	}
//};
//
////Lenovo
//class LenovoCpu :public Cpu
//{
//public:
//	void Calculate()
//	{
//		cout << "Lenovo的CPU开始计算了" << endl;
//	}
//};
//
//class LenovoVedioCard :public VedioCard
//{
//public:
//	void display()
//	{
//		cout << "Lenovo的显卡开始显示了" << endl;
//	}
//};
//
//class LenovoMemory :public Memory
//{
//public:
//	void Storage()
//	{
//		cout << "Lenovo的内存条开始存储了" << endl;
//	}
//};
//
//int main()
//{
//	Cpu* interCpu = new InterCpu;
//	VedioCard* lenovoVC = new LenovoVedioCard;
//	Memory* intermemory = new InterMemory;
//	Computer computer(interCpu, lenovoVC, intermemory);
//	computer.Dowork();
//	return 0;
//}




//五.文件操作:
//*1.包含头文件fstream   *2.创建流对象   *3.打开文件   *4.读写文件   *5.关闭文件

//1.文本文件：
//1>写文件

//#include<iostream>
////包含头文件
//#include<fstream>
//using namespace std;
//int main()
//{
//	//文件输出流对象
//	ofstream f;
//	//打开文件：open("文件路径"，打开方式)
//	//ios::in(读文件),ios::out（写文件）,ios::ate(初始位置：文件尾)，ios::app(追加方式写文件)
//	//ios::binary(二进制文件)，ios::trunc(如果文件存在先删除，再创建)
//	f.open("text.txt", ios::out);
//	//写文件
//	f << "我喜欢你" << endl;
//	f << "明天会更好" << endl;
//	//关闭文件
//	f.close();
//	return 0;
//}

//2>读文件

//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//int main()
//{
//	ifstream i;
//	i.open("text.txt", ios::in);
//	//判断文件是否打开成功
//	if (!i.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return 0;
//	}
//
//	//写文件：
//	//*1.
//	/*char buf[1024] = { 0 };
//	while (i >> buf)
//	{
//		cout << buf << endl;
//	}*/
//
//	//*2.
//	/*char buf[1024] = { 0 };
//	while (i.getline(buf, sizeof(buf)))
//	{
//		cout << buf << endl;
//	}*/
//
//	//*3.
//	//string buf;
//	//while (getline(i, buf))   //getline包含在string头文件中
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//*4.前面都是一行一行读取，下面是一个字符一个字符读取
//	char c;
//	while ((c = i.get()) != EOF)
//	{
//		cout << c;
//	}
//
//	i.close();
//	return 0;
//}



//2.二进制文件：
//1>写文件
//ostream& write(const char* buffer, int len);

//#include<iostream>
//#include<fstream>
//using namespace std;
//class Person
//{
//public:
//	char m_name[64];
//	int m_age;
//};
//int main()
//{
//	//ofstream 有构造函数，可以直接传入路径和打开方式
//	ofstream ofs("person.txt", ios::out | ios::binary);   //通过 | 可以将不同的打开方式叠加
//	Person p = { "张三",20 };
//	ofs.write((const char*)&p, sizeof(Person));
//	ofs.close();
//	return 0;
//}


//2>读文件
//istream& read(char* buffer, int len);

//#include<iostream>
//#include<fstream>
//using namespace std;
//class Person
//{
//public:
//	char m_name[64];
//	int m_age;
//};
//int main()
//{
//	ifstream ifs;
//	ifs.open("person.txt", ios::in | ios::binary);
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return 0;
//	}
//	Person p;
//	ifs.read((char*)&p, sizeof(Person));
//	cout << p.m_name << " " << p.m_age << endl;
//	ifs.close();
//	return 0;
//}



