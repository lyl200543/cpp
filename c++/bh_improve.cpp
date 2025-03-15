//一.模板：
//C++另一种编程思想就是泛型编程，主要利用的技术就是模板
//C++提供两种模板机制：函数模板和类模板

//1.函数模板的基本语法：
//template<typename T>  T：通用的数据结构
//函数声明或定义

//作用：建立一个通用函数，函数的返回值和形参的类型可以不具体指定，用一个虚拟的类型来代表

//#include<iostream>
//using namespace std;
//
//void SwapInt(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void SwapFloat(float& a, float& b)
//{
//	float tmp = a;
//	a = b;
//	b = tmp;
//}
//
////模板
//template<typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	/*SwapInt(a, b);*/
//
//	//1.自动推导类型
//	//Swap(a, b);
//
//	//2.显示指定类型
//	Swap<int>(a, b);
//
//	cout << a << " " << b << endl;
//
//	/*float c = 1.1;
//	float d = 2.2;
//	SwapFloat(c, d);
//	cout << c << " " << d << endl;*/
//}
//
//int main()
//{
//	test01();
//	return 0;
//}


//2.