//#include<iostream>
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

