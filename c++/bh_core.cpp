//һ.�ڴ����ģ�ͣ�����������������ջ��������
//��������ǰ����������������
//�������к󣺴���������������ջ��������

//��������ȫ�ֱ�������̬�������������ַ���������const���ε�ȫ�ֱ�����
//const���εľֲ��������ǳ���


//��.���ã�
//1.���õı��ʣ���һ��ָ�볣��
//#include<iostream>
//int main()
//{
//	int a = 10;
//	//�Զ�ת��Ϊ int* const ref= &a; ָ�볣����ָ��ָ���ܸ�
//	//��Ҳ˵����Ϊʲô���ò��ܸ���
//	int& ref = a;   
//	ref = 20;  //�൱�� *ref=20;
//	return 0;
//}

//2.�������ã�
//#include<iostream>
//int main()
//{
//	//int& ref = 10;  //���Ϸ������õ���ֵ�����ǳ���
//	const int& ref = 10;   //�Ϸ�
//	//�������Զ�ת����int tmp=10; const int& ref=tmp;
//	return 0;
//}


//��.�����߼���
//1.ռλ������
//��Ϊ�����Ĳ���������ֻ�����ͣ�û������

//#include<iostream>
//void fuc(int a, int)
//{
//	std::cout << "hello world\n";
//}
//ռλ����Ҳ��ʹ��Ĭ�ϲ���
//void fuc(int a, int = 10)
//{
//	std::cout << "hello world\n";
//}
//int main()
//{
//	fuc(10,10);   //����ʱռλ���������
//	return 0;
//}


//��.��Ͷ���
//1.��װ��

//���һ��ѧ���ࣺ
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


//1>****����Ա��������Ϊ˽�У�
//�����Լ����Ƴ�Ա���ԵĶ�дȨ��
//����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��

//#include<iostream>
//#include<string>
//using namespace std;
//class person
//{
//private:
//	string m_name;   //�ɶ���д
//	int m_age = 18;  //ֻ��
//	string m_idol;   //ֻд
//public:
//	//�ɶ���д
//	void SetName(string name)
//	{
//		m_name = name;
//	}
//	string GetName()
//	{
//		return m_name;
//	}
//
//	//ֻ��  
//	int GetAge()
//	{
//		return m_age;
//	}
//	
//	//дȨ�ޣ��������
//	void SetAge(int age)
//	{
//		if (age < 0 || age>100)
//		{
//			cout << "����������󣬸�ֵʧ��" << endl;
//			return;
//		}
//		m_age = age;
//	}
//
//	//ֻд
//	void SetIdol(string idol)
//	{
//		m_idol = idol;
//	}
//};
//int main()
//{
//	person p;
//	p.SetName("lyl");
//	cout << "������ " << p.GetName() << endl;
//	p.SetAge(250);
//	cout << "���䣺 " << p.GetAge() << endl;
//	p.SetIdol("zyz");
//	return 0;
//}


//���һ����������
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
//	//**ע��ȫ�ֺ����ͳ�Ա���������𣨲�����
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
//	cout << "����� " << c1.calculateS() << endl << "����� " << c1.calculateV() << endl;
//	cout << "����� " << c2.calculateS() << endl << "����� " << c2.calculateV() << endl;
//	cout << c1.is_equal(c2) << endl;
//	cout << is_equal(c1, c2) << endl;
//	return 0;
//}


//��Ƶ��Բ�ࣨ������Բ�Ĺ�ϵ��
//#include<iostream>
//#include<cmath>  //pow()��ͷ�ļ�
//using namespace std;
//
////��һ����Ķ�����������һ����δ�������ʱ:ǰ�������ͷ��붨��
//
////ǰ��������
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
//	//��ʱCircle��δ���壬�������ᱨ��
//	//������
//	void position(Circle& c);
//	/*{
//		if (pow(x1 - c.GetX(), 2) + pow(y1 - c.GetY(), 2) == pow(c.GetR(), 2))
//			cout << "����Բ��" << endl;
//		else if (pow(x1 - c.GetX(), 2) + pow(y1 - c.GetY(), 2) > pow(c.GetR(), 2))
//			cout << "����Բ��" << endl;
//		else
//			cout << "����Բ��" << endl;
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
//	//����:
//	void position(Point& p);
//	/*{
//		if (pow(p.GetX () - x0, 2) + pow(p.GetY () - y0, 2) == pow(m_r, 2))
//			cout << "����Բ��" << endl;
//		else if (pow(p.GetX() - x0, 2) + pow(p.GetY() - y0, 2) > pow(m_r, 2))
//			cout << "����Բ��" << endl;
//		else
//			cout << "����Բ��" << endl;
//	}*/
//};
//
////���붨�壺
//void Point::position(Circle& c)
//{
//	if (pow(x1 - c.GetX(), 2) + pow(y1 - c.GetY(), 2) == pow(c.GetR(), 2))
//		cout << "����Բ��" << endl;
//	else if (pow(x1 - c.GetX(), 2) + pow(y1 - c.GetY(), 2) > pow(c.GetR(), 2))
//		cout << "����Բ��" << endl;
//	else
//		cout << "����Բ��" << endl;
//}
//
//void Circle::position(Point& p)
//{
//	if (pow(p.GetX () - x0, 2) + pow(p.GetY () - y0, 2) == pow(m_r, 2))
//		cout << "����Բ��" << endl;
//	else if (pow(p.GetX() - x0, 2) + pow(p.GetY() - y0, 2) > pow(m_r, 2))
//		cout << "����Բ��" << endl;
//	else
//		cout << "����Բ��" << endl;
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


//��׼�棺
//һ����ĳ�Ա���Կ�������һ����
//��ķ��루�ļ���

//�� C++ �У������֮���ǿ���ֱ�Ӹ�ֵ��
//�����ָ�ֵ��Ϊ��Ҫ��֧�ָ�ֵ�������operator=��
//C++ ���Զ�Ϊÿ��������Ĭ�ϵĸ�ֵ���������������ʽ�ض������Լ��ĸ�ֵ�����
//Ĭ�ϵĸ�ֵ����������Ա��ֵ������Դ�����ÿ����Ա������ֵ���Ƶ�Ŀ�����Ķ�Ӧ��Ա������

//#include<iostream>
//#include<cmath>  //pow()��ͷ�ļ�
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
////	//���а�����һ����
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
//		cout << "����Բ��" << endl;
//	else if (dist < cdist)
//		cout << "����Բ��" << endl;
//	else
//		cout << "����Բ��" << endl;
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


//2.����ĳ�ʼ��������

//1>���캯��������������
//���ã����г�ʼ����������
//ϵͳ�Զ����ã���ֻ����һ��
//���캯�������в������Դ˿�������
//���������������в���
//�������û���Զ��幹�캯�����������������������ṩĬ�Ϻ������Һ���Ϊ��ʵ�֣�������Ϊ�յĺ�����

//2>���캯���ķ���:
//���������ࣺ�޲ι��캯����Ĭ�Ϲ��캯�������вι��캯��
//�����ͷ��ࣺ��ͨ���캯�����������캯��

//3>���캯���ĵ��ã����ŷ�����ʾ������ʽת����

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_age;
//
//	//��ͨ���캯����
//	Person()
//	{
//		cout << "Ĭ�Ϲ��캯������" << endl;
//	}
//	Person(int age)
//	{
//		m_age = age;
//		cout << "�вι��캯������" << endl;
//	}
//	//�������캯����
//	Person(const Person& p)
//	{
//		m_age = p.m_age;
//		cout << "�������캯������" << endl;
//	}
//
//	~Person()
//	{
//		cout << "������������" << endl;
//	}
//};
//int main()
//{
//	//1.���ŷ���
//	//Person p1;
//	//Person p2(10);
//	//Person p3(p2);
//	//cout << "p2: " << p2.m_age << endl;
//	//cout << "p3: " << p3.m_age << endl;
//	
//	//ע������1������Ĭ�Ϲ��캯��ʱ��Ҫ�����ţ�����������Ϊ�Ǻ������� void print()
//	//Person p1();
//
//	//2.��ʾ����
//	//Person p1;
//	//Person p2 = Person(10);
//	//Person p3 = Person(p2);
//
//	//ע������2��
//	//Person(10)���������󣬵�ǰ�н�����ϵͳ������������������
//	//��Ҫ���ÿ������캯������ʼ����������
//	//Person(p3);  -->�����⣺��Person p3��: �ض���
//	//����������ΪPerson(p3) == Person p3 
//
//	//3.��ʽת������
//	Person p1;
//	Person p2 = 10;    //�൱��Person p2 = Person(10);
//	Person p3 = p2;    //�൱��Person p3 = Person(p2);
//	return 0;
//}


//4>�������캯������ʱ����
//ʹ��һ���Ѿ������õĶ����ʼ���¶���
//��ֵ���ݵ���ʽ����������
//��ֵ��ʽ���ؾֲ�����


//5>���캯�����ù���
//Ĭ������£�c++���������ٸ�һ�������3��Ĭ�Ϻ�����
//Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
//Ĭ�������������޲Σ�������Ϊ�գ�
//Ĭ�Ͽ������캯���������Խ���ֵ����

//�Զ������вι��캯���������������ṩĬ���޲ι��캯�������ṩ�������캯��
//�Զ����˿������캯���������������ṩ�������캯��

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_age;
//	/*Person()
//	{
//		cout << "����Ĭ���޲ι��캯��" << endl;
//	}*/
//	/*Person(int age)
//	{
//		cout << "�����вι��캯��" << endl;
//		m_age = age;
//	}*/
//	/*Person(const Person& p)
//	{
//		cout << "���ÿ������캯��" << endl;
//		m_age = p.m_age;
//	}*/
//	
//};
//
//int main()
//{
//	//Person p1;   //������ "Person" ������Ĭ�Ϲ��캯��
//	//Person p(18);  //����û��������б�ƥ��Ĺ��캯�� "Person::Person" ʵ��
//	return 0;
//}



//6>�����ǳ������
//ǳ�������򵥵ĸ�ֵ������Ĭ�Ͽ������캯����ǳ������
//������ڶ�����������ռ䣬���п�������
//***ע�⣺��Ա���԰����������ٱ���ʱ��Ҫ�Զ��忽�����캯���������

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
//		//Ĭ�Ͽ������캯����ǳ���������´��룩
//		//�����Ա�������ڶ������ٵı�������ֱ�Ӹ�ֵ��ͬ�ĵ�ַ
//		//���������У�ͬһ��ռ䱻�ͷ����Σ���������
//		/*m_age = p.m_age;
//		m_height = p.m_height;*/
//
//		//�����
//		m_age = p.m_age;
//		m_height = new int(*p.m_height);
//	}
//	~Person()
//	{
//		//�������������ã��ͷ��ڶ������ٵĿռ�
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



//7>��ʼ����Ա�б�-->����ʹ�ó�ʼ����Ա�б�����ʼ��
//�﷨�����캯������������1��ֵ1��������2��ֵ2��...

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



//8>�������Ϊ���Ա��
//��һ��A���а�������B�����ʱ��
//�ȵ���B��Ĺ��캯�����ٵ���A��Ĺ��캯��
//�ȵ���A��������������ٵ���B�����������

//�������Ϊ���Ա��ʼ��ʱ������ʹ�ó�Ա��ʼ���б�
//������Ա�����ڹ��캯������ͨ����ֵ��ʼ��
//��ʼ���б����ó�Ա����Ĺ��캯����ȷ�������ڹ��캯����ִ��֮ǰ�Ѿ�����ȷ��ʼ��

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
//		cout << "Phone�Ĺ��캯������" << endl;
//	}
//	~Phone()
//	{
//		cout << "Phone��������������" << endl;
//	}
//};
//class Person
//{
//public:
//	string m_name;
//	Phone m_phone;   //�����Ա
//
//	//ע������Ա�ĳ�ʼ��  
//	Person(string name, int id, string pname) :m_name(name), m_phone(id, pname)  
//	{
//		cout << "Person�Ĺ��캯������" << endl;
//	}
//	~Person()
//	{
//		cout << "Person��������������" << endl;
//	}
//
//};
//int main()
//{
//	Person("lyl", 19, "vivo");
//	return 0;
//}



//9>��̬��Ա��
//��̬��Ա������
//���ж�����һ������
//�ڱ���׶η����ڴ�
//���������������ʼ��

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	static int m_a;  //��������
//};
//
////�����ʼ��
//int Person::m_a = 10;
//
//void test1()
//{
//	//����һ������
//	/*Person p;
//	cout << p.m_a << endl;
//	Person p2;
//	p2.m_a = 30;
//	cout << p.m_a << endl;*/
//}
//
//void test2()
//{
//	//1.ͨ���������ʾ�̬��Ա����
//	Person p;
//	cout << p.m_a << endl;
//	//2.ͨ���������ʾ�̬��Ա����
//	cout << Person::m_a << endl;
//}
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}


//��̬��Ա������
//���ж�����һ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����

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
//		//m_b = 10;    //�Ǿ�̬��Ա���ñ������ض��������
//		cout << "func()��������" << endl;
//	}
//};
//
//int Person::m_a = 0;
//
//int main()
//{
//	//1.ͨ���������ʾ�̬��Ա����
//	Person p;
//	p.func();
//	//2.ͨ���������ʾ�̬��Ա����
//	Person::func();
//	return 0;
//}



//3.c++����ģ�ͺ�thisָ�룺
//1>��Ա�����ͳ�Ա�����ֿ��洢��
//�ն�����ռ�ڴ��СΪ1�ֽ�
//ֻ�зǾ�̬��Ա�������������

//#include<iostream>
//using namespace std;
//class Person
//{
//};
//
//class Student
//{
//public:
//	int m_a;  //�Ǿ�̬��Ա�������������
//	static int m_b;   //��̬��Ա���������������
//
//	void func1()    //�Ǿ�̬��Ա���������������
//	{ }
//	static void func2()   //��̬��Ա���������������
//	{ }
//};
//void test1()
//{
//	Person p;
//	cout << sizeof(p) << endl;  //1�ֽ�
//	//���ֿն���ռ�ڴ��λ�ã�ÿ���ն�����һ����һ�޶����ڴ��ַ
//}
//
//void test2()
//{
//	Student s;
//	cout << sizeof(s) << endl;    //4�ֽ�
//}
//
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}


//2>thisָ�룺ָ��ĳ����������ָ��

//ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ������ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ�����
//��һ�����ͨ��thisָ���ж�����һ��������ú���
//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���

//thisָ����������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
//thisָ�벻��Ҫ���壬ֱ��ʹ�þ���


//*1.������ֳ�ͻ����
//#include<iostream>
//class Person
//{
//public:
//	int age;
//	Person(int age)/*:age(age)*/
//	{
//		//age = age;    //������ͬ����������Ϊ�����βΣ�û�и���Ա���Ը�ֵ
//		this->age = age;   //��Ա��ʼ���б�Ҳ���Խ��
//	}
//};
//using namespace std;
//int main()
//{
//	Person p(19);
//	cout << p.age << endl;
//	return 0;
//}


//*2.�ڳ�Ա�����з��ض�����return *this�� --����ʽ���
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
//	//ע�⣺����ʱһ��Ҫ�������ã���Ȼ���ص��Ǹö���Ŀ�������
//	//���Ǹö����޷�ʵ����ʽ���
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
//	//��ʽ���
//	p1.Add(p2).Add(p2).Add(p2);  
//	//����Person& -->40
//	//����Person -->20
//	cout << p1.age << endl;
//	return 0;
//}



//3>��ָ����ʳ�Ա����:
//C++�п�ָ���ǿ��Ե��ó�Ա������,��Ҫע�⵽����thisָ������

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int age;
//	//�ú�����������
//	void PrintClassName()  
//	{
//		cout << "Person" << endl;
//	}
//	//�ú�������
//	//��Ϊʹ�ó�Ա����ʱ:age  -->ʵ����:  this->age  
//	//ʹ����thisָ��,����thisΪ��ָ��,�ʱ���
//	void PrintAge()
//	{
//		//���Ӵ��뽡׳��
//		if (this == NULL)
//			return;
//
//		cout << age << endl;   //����:this�ǿ�ָ��
//	}
//};
//int main()
//{
//	Person* p = NULL;
//	//p->PrintClassName();
//	p->PrintAge();
//	return 0;
//}



//4>const���γ�Ա����:
//������:��Ա�������const
//�������ڲ����޸ĳ�Ա����
//��Ա���Լ���mutable�ؼ������κ�,��������Ҳ�����޸�

//������:����ǰ��const
//������ֻ�ܵ��ó�����

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_a;
//	mutable int m_b;
//	//thisָ��ʵ������ָ�볣��,������Ϊ Person* const this
//	//this��ָ�����޸�
//	//��Ա��������const���κ�:ָ���Ϊ const Person* const this
//	//��ָ��ָ���ֵҲ�����޸�,�� m_a == this->m_a,�ʲ����޸�
//	void func1() const
//	{
//		//m_a = 10;   //�������޸�
//		m_b = 10;   //�����޸�
//	}
//	void func2()
//	{
//		m_a = 10;
//	}
//};
//int main()
//{
//	//������ֻ�ܵ��ó���Ա����
//	//��Ϊ��ͨ��Ա�������޸ĳ�Ա����,��������þ����޸ĳ�Ա����
//	//�����������޸ĳ�Ա����
//	const Person p;
//	//p.m_a = 10;   //����:���ʽ�����ǿ��޸ĵ���ֵ
//	p.m_b = 10;
//	p.func1();
//	//p.func2();   //����
//	return 0;
//}



//4.��Ԫ:
// Ŀ��:��һ���������������һ�����е�˽������
// �ؼ���:friend

//1>ȫ�ֺ�������Ԫ:
//��������friend����Ҫ����˽�����Ե�ȫ�ֺ���������

//#include<iostream>
//using namespace std;
//class Building
//{
//	//��Ԫ
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
//	cout << "�û���ȫ�ֺ������ڷ���: " << building.m_settingroom << endl;
//	cout << "�û���ȫ�ֺ������ڷ���: " << building.m_bedroom << endl;   //����
//}
//int main()
//{
//	Building building("����", "����");
//	GoodGay(building);
//	return 0;
//}


//2>������Ԫ:

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
////��Ա�������������ⶨ��
//GoodGay::GoodGay()
//{
//	//******* new�����ڴ棬ͬʱ���ö���Ĺ��캯������ʼ������ڴ�
//	building = new Building;
//}
//
//Building::Building()
//{
//	m_settingroom = "����";
//	m_bedroom = "����";
//}
//
//void GoodGay::visit()
//{
//	cout << "�û��������ڷ���: " << building->m_settingroom << endl;
//	cout << "�û��������ڷ���: " << building->m_bedroom << endl;
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


//3>��Ա��������Ԫ:

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
//	//���߱�������GoodGay�µ�visit()�������ҵĺ����ѣ����Է����ҵ�˽�г�Ա����
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
//	m_settingroom = "����";
//	m_bedroom = "����";
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
//	cout << "visit �������ڷ��ʣ� " << building->m_settingroom << endl;
//	cout << "visit �������ڷ��ʣ� " << building->m_bedroom << endl;
//	
//}
//
//void GoodGay::visit2()
//{
//	cout << "visit2 �������ڷ��ʣ� " << building->m_settingroom << endl;
//	//cout << "visit �������ڷ��ʣ� " << building->m_bedroom << endl;
//}
//int main()
//{
//	GoodGay gg;
//	gg.visit();
//	gg.visit2();
//	return 0;
//}



//5.���������:
//��������������½��ж��壬��������һ�ֹ��ܣ�ʹ��ʹ�ò�ͬ����������

//1>�Ӻţ�+����������أ�

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_a;
//	int m_b;
//	//ͨ����Ա��������+�ţ�
//	/*Person operator+(Person& p)
//	{
//		Person tmp;
//		tmp.m_a = this->m_a + p.m_a;
//		tmp.m_b = this->m_b + p.m_b;
//		return tmp;
//	}*/
//};
//
////ͨ��ȫ�ֺ�������+�ţ�
//Person operator+(Person& p1, Person& p2)
//{
//	Person tmp;
//	tmp.m_a = p1.m_a + p2.m_a;
//	tmp.m_b = p1.m_b + p2.m_b;
//	return tmp;
//}
//
////�������أ�
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
//	//�򻯰棺
//	//Person p3 = p1 + p2;
//	
//	//ͨ����Ա��������+�ŵı��ʣ�
//	//Person p3 = p1.operator+(p2);
//
//    //ͨ��ȫ�ֺ�������+�ŵı��ʣ�
//	//Person p3 = operator+(p1, p2);
//	
//
//	//��������� Ҳ�ܷ�����������
//	Person p3 = p1 + 100;
//	//Person p3 = 100 + p1;    //û������Щ������ƥ��� "+" �����
//	//*********ע�⣺������������Ҳ����������ϸ��뺯������һһ��Ӧ��������
//
//	cout << p3.m_a << " " << p3.m_b << endl;
//	return 0;
//}



//2>���ƣ�<<����������أ�����Զ�������
//std::cout �� std::ostream ���һ��ʵ��

//����<<���������ͨ����Ա������
//<< ������ĵ�һ������������ std::ostream& ����
//����ĳ�Ա�����ĵ�һ������������ʽ�� this ָ��
//cout<<p -->���ʣ�cout.operator<<(class& p) �� operator<<(ostream& cout,class& p)

//Ҫʵ����ʽ���ã����뷵��ostream&

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
//	//ʹ�ó�Ա������
//	//p << cout << endl;
//	return 0;
//}


//3>������++����������أ�

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
//	//ǰ��++
//	//���뷵��ClassName& ����ʵ����ʽ��� ++��++m��
//	MyInteger operator++()
//	{
//		m_int++;
//		return *this;
//	}
//
//	//����++
//	//intΪռλ�������Ǳ�����������������ǰ�úͺ��õ�
//	//���÷���ֵ��������ʽ���
//	MyInteger operator++(int)
//	{
//		MyInteger tmp = *this;
//		m_int++;
//		return tmp;
//	}
//
//	//�ݼ���������
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



//4>��ֵ��=����������أ�
//c++���������ٸ�һ�������4��������
//Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
//Ĭ�������������޲Σ�������Ϊ�գ�
//Ĭ�Ͽ������캯����Ϊֵ������ǳ������
//��ֵ��������أ�operator=����Ϊֵ������ǳ������
//����Ա���԰������д����ı���ʱ����ֵ�����ᵼ�¶���ͬһ��ռ䱻�ͷ�����

//һ����Ա�����а������д����ı���ʱ��
//�������캯���͸�ֵ��������غ�����Ҫ�Լ����塪��>��Ϊ���

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
//	//���������=
//	Person& operator= (Person& p)
//	{
//		//*******�ͷ�֮ǰ����Ŀռ�
//		delete m_age;
//		m_age = NULL; 
//
//		//���·���ռ䲢����ֵ
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
//	//�������캯����operator=������
//	//Person p4(p1); -->���õ��ǿ������캯��
//	//Person p4(40);  p4=p1;  -->���õ��Ǹ�ֵ�����
//
//	p3 = p2 = p1;
//	cout << *p1.m_age << " " << *p2.m_age << " " << *p3.m_age << endl;
//	return 0;
//}



//5>��ϵ�����(>, <, ==, !=)���أ�

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
//		cout << "p1��p2�����" << endl;
//	else
//		cout << "p1��p2���" << endl;
//	
//	return 0;
//}


//6>�������������()���أ�
//��Ϊ���غ�ʹ�õķ�ʽ���������ã����Ա���Ϊ�º���
//�º���û�й̶�д���������

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
//	//������������
//	//����������ִ�н�����ͱ�����
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


//6.�̳�:�����ظ�����

//1>�̳еĻ����﷨��class ���ࣨ�����ࣩ���̳з�ʽ ���ࣨ���ࣩ
//#include<iostream>
//using namespace std;
//class BasePage
//{
//public:
//	void Header()
//	{
//		cout << "��ҳ��ע�ᣬ��¼�������� ...(����ͷ��)" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ģ�����������վ�ڵ���...(�����ײ�)" << endl;
//	}
//	void left()
//	{
//		cout << "Java,Python,C++...�����������б�" << endl;
//	}
//};
//
////�̳У�
//class Java:public BasePage
//{
//public:
////	void Header()
////	{
////		cout << "��ҳ��ע�ᣬ��¼�������� ...(����ͷ��)" << endl;
////	}
////	void footer()
////	{
////		cout << "�������ģ�����������վ�ڵ���...(�����ײ�)" << endl;
////	}
////	void left()
////	{
////		cout << "Java,Python,C++...�����������б�" << endl;
////	}
//	void java()
//	{
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//};
//
//class Python : public BasePage
//{
//public:
////	void Header()
////	{
////		cout << "��ҳ��ע�ᣬ��¼�������� ...(����ͷ��)" << endl;
////	}
////	void footer()
////	{
////		cout << "�������ģ�����������վ�ڵ���...(�����ײ�)" << endl;
////	}
////	void left()
////	{
////		cout << "Java,Python,C++...�����������б�" << endl;
////	}
//	void python()
//	{
//		cout << "pythonѧ����Ƶ" << endl;
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


//2>�̳з�ʽ��
//�����̳У�public���������̳У�protected����˽�м̳У�private��
//���ּ̳з�ʽ�£����඼���ܷ��ʸ����private��Ա
//public�̳��£��̳еĳ�ԱȨ�޲���
//protected�̳��£��̳еĳ�ԱȨ�޶���Ϊprotected
//private�̳��£��̳еĳ�ԱȨ�޶���Ϊprivate

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
////�����̳У�
//class Son1 :public Father
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;   //�������಻�ܷ��ʸ����е�private��Ա
//	}
//};
//
//void test01()
//{
//	Son1 son;
//	son.m_a = 10;     //public�̳��£������е�public��Ա��������Ҳ��public
//	//son.m_b = 10;     //����public�̳��£������е�protected��Ա��������Ҳ��protected
//}
//
////�����̳У�
//class Son2 :protected Father
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;    //�������಻�ܷ��ʸ����е�private��Ա
//	}
//};
//
//void test02()
//{
//	Son2 son;
//	//����protected�̳��£������е�public,protected��Ա�������ж���protected
//	//son.m_a = 10;    
//	//son.m_b = 10;
//}
//
////˽�м̳У�
//class Son3 :private Father
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;      //�������಻�ܷ��ʸ����е�private��Ա
//	}
//};
//
//class GrandSon :public Son3
//{
//public:
//	void func()
//	{
//		//����private�̳��£������е�public,protected��Ա�������ж���private
//		//m_a = 10;
//		//m_b = 10;
//	}
//};
//
//int main()
//{
//	return 0;
//}


//3>�̳��еĶ���ģ�ͣ�
//���������зǾ�̬��Ա���Զ��ᱻ����̳�
//�����е�˽�г�ԱҲ������̳��ˣ�ֻ�Ǳ��������������޷�����

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
//	cout << sizeof(Son) << endl;   //sizeΪ16�ֽڣ�˵�������е�˽�г�ԱҲ���̳���
//	return 0;
//}

//����ʹ��vs 2022 ������Ա������ʾ�� 
//ͨ������ cl /d1 reportSingleClassLayout���� �����ļ���  �鿴����ĳ�Ա���



//4>�̳��й��������˳��
//�̳��У��ȵ��ø���Ĺ��캯�����ٵ�������Ĺ��캯���������ĵ���˳���෴��ջ�����Ƚ������

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base�Ĺ��캯��" << endl;
//	}
//	~Base()
//	{
//		cout << "Base����������" << endl;
//	}
//};
//
//class Son :public Base
//{
//public:
//	Son()
//	{
//		cout << "Son�Ĺ��캯��" << endl;
//	}
//	~Son()
//	{
//		cout << "Son����������" << endl;
//	}
//};
//int main()
//{
//	//Base b;
//	Son s;
//	return 0;
//}



//5>�̳�ͬ����Ա����ʽ��
//�������͸�������ͬ����Ա��
//��������ͬ����Ա��ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա����Ҫ��������
//ԭ�򣺵�����ӵ���븸��ͬ���ĳ�Ա����ʱ����������ظ����е�ͬ����Ա�������������غ����������Ҫ��������

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
//		cout << "Base��func��������" << endl;
//	}
//	//���غ�����
//	void func(int n)
//	{
//		cout << "Base��func(int n)��������" << endl;
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
//		cout << "Son��func��������" << endl;
//	}
//};
//
////ͬ����Ա���ԣ�
//void test01()
//{
//	Son s;
//	cout << "Son��m_a: " << s.m_a << endl;
//	cout << "Base��m_a: " << s.Base::m_a << endl;
//}
//
////ͬ����Ա������
//void test02()
//{
//	Son s;
//	s.func();
//	s.Base::func();
//	//s.func(3);  //�������������еĲ���̫�� -->����������ͬ�������������أ��������غ�����
//	s.Base::func(3);
//}
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}


//6>�̳�ͬ����̬��Ա����ʽ��
//��̳���ͨ��Ա����ʽһ��������Ҫע�⾲̬��Ա�����ַ��ʷ�ʽ

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	static int m_a;
//	static void func()
//	{
//		cout << "Base��func()��������" << endl;
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
//		cout << "Son��func()��������" << endl;
//	}
//};
//
//int Son::m_a = 200;
//
//void test01()
//{
//	//1.ͨ��������ʣ�
//	Son s;
//	cout << "Son: " << s.m_a << endl;
//	cout << "Base: " << s.Base::m_a << endl;
//
//	//2.ͨ���������ʣ�
//	cout << "Son: " << Son::m_a  << endl;
//	cout << "Base: " << Son::Base::m_a  << endl;
//	//ע�⣺��һ��::����ͨ���������ʣ��ڶ���::�����ڸ���Base��������
//}
//
//void test02()
//{
//	//1.ͨ��������ʣ�
//	Son s;
//	s.func();
//	s.Base::func();
//
//	//2.ͨ���������ʣ�
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


//7>��̳��﷨��
//C++����һ����̳ж����
//��ʽ��class ���ࣺ�̳з�ʽ ����1���̳з�ʽ ����2 ...

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
//	//��������ͬ����Աʱ��ʹ��Ҫ��������
//	//��ʵ�ʿ����в�����ʹ��
//	return 0;
//}



//8>���μ̳У�
//B�࣬C��ֱ�̳���A�࣬D����ͬʱ�̳���B���C�࣬��Ϊ���μ̳У���ʯ�̳У�
//���μ̳е������ࣨD�ࣩ�̳���������ͬ�����ݣ�������Դ�˷�
//����ͨ������̳С��ķ�ʽ������μ̳е�����

//#include<iostream>
//using namespace std;
//class Animals
//{
//public:
//	int m_age;
//};
//
////�̳�֮ǰ���Ϲؼ���virtual��Ϊ��̳�
////Animals���Ϊ�����
//
////ԭ��
////��̳��£������̳������ָ�루vbptr��,ָ��һ��������vbtable��
////�������м�¼��ƫ������ָ�����ƫ������ָ��m_age(ֻ��һ������)
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
//	//cout << st.m_age << endl;    //�������ֶ����ԣ���֪����Sheep�໹��Tuo���m_age
//	//����ͨ����������ķ����ֱ����Sheep���Tuo���m_age������û�������˷ѿռ�
//
//	st.m_age = 20;
//	st.Sheep::m_age = 19;   //��ͬһ�����ݽ��и���
//	cout << st.m_age << endl;  //19
//	return 0;
//}


//ûʹ����̳У�
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


//ʹ����̳У�
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




//7.��̬:
//��̬��Ϊ���ࣺ
//��̬��̬���������غ�������������ھ�̬��̬�����ú����� -->������ַ��󶨣�����׶�ȷ��������ַ��
//��̬��̬��������͡��麯����ʵ������ʱ��̬ -->������ַ��󶨣����н׶�ȷ��������ַ��

//1>��̬�Ļ����﷨��
//��̬����������*1.�м̳й�ϵ  *2.������д�����е��麯��
//��̬ʹ������������ָ�������ָ���������

//��д����������ֵ���ͣ��������������б���ȫһ��

//#include<iostream>
//using namespace std;
//class Animals
//{
//public:
//	//�����У��麯��
//	virtual void Speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//
//class Cat : public Animals
//{
//public:
//	void Speak()
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
//
//class Dog : public Animals
//{
//public:
//	void Speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//};
//
//void DoSpeak(Animals& animal)   //������������Ϊ��������ԭ������Ϊ����ĺ���
//{
//	animal.Speak();
//}
//
//int main()
//{
//	//ûʹ���麯������̬����
//	//��ӡ��������˵������Ϊ��̬��̬��������ַ���
//	
//	//ʹ���麯������̬����
//	//��ӡСè��˵����С����˵����Ϊ��̬��̬
//
//	Cat cat;
//	Dog dog;
//	DoSpeak(cat);  
//	DoSpeak(dog);
//
//	return 0;
//}


//2>��̬��ԭ��������

//#include<iostream>
//using namespace std;
//class Animals
//{
//public:
//	virtual void Speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//
//class Cat : public Animals
//{
//public:
//	void Speak()
//	{
//		cout << "Сè��˵��" << endl;
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
//	//Animals���е�speak()������
//	//û��vitual�ؼ��֣���СΪ1�ֽ�
//	//��vitual�ؼ��֣���СΪ4/8�ֽڣ�x64/x86��-->������һ��ָ��
//	cout << sizeof(Animals) << endl;  
//
//	return 0;
//}


//û��vitual:
//class Animals   size(1) :
//	+-- -
//	+-- -

//��vitual:
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

//���� F ��Ϊ�麯���󣬻�����һ���麯������ָ�� vfptr,ָ����� A ���麯���� vftable
//�麯���� vftable �д���˸��� A �������µĺ��� F ��ַ
//������ A ������ B û����д���� F ʱ������ B �̳� A ��� vfptr ָ��
//��ָ������ B �Լ����麯���� vftable �������ŵ����� A �������µĺ��� F ��ַ
//�� B ����д���� F ʱ���̳е� vfptr ָ��ָ������ B �Լ����麯���� vftable 
//���������ŵ��� B ���������µĺ��� F ��ַ



//3>��̬����һ��������

//#include<iostream>
//#include<string>
//using namespace std;
//
////��ͨд����
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
//		//�������չ�¹��ܣ���Ҫ�޸�Դ����
//		//��ʵ�ʿ����У��ᳫ����ԭ��
//		//����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�
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
////��̬д����
////�ô���������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ�ά��
//
////������
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
////�ӷ���
//class AddCalculator :public AbstractCalculator
//{
//public:
//    int GetResult()
//	{
//		return m_num1 + m_num2;
//	}
//};
//
////������
//class SubCalculator :public AbstractCalculator
//{
//public:
//	int GetResult()
//	{
//		return m_num1 - m_num2;
//	}
//};
//
////�˷���
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



//4>���麯���ͳ����ࣺ-->�淶ʹ�ö�̬

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	//���麯��
//	virtual void Func() = 0;
//	//���д��麯���������������
//	//��������ص㣺
//	//1.�����಻��ʵ��������
//	//2.����������������д���麯��������Ҳ����ʵ��������
//};
//
//class Son :public Base
//{
//public:
//	void Func()
//	{
//		cout << "Func()��������" << endl;
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



//5>��̬��������������Ʒ

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
//		cout << "��ũ��ɽȪ" << endl;
//	}
//	void Brew()
//	{
//		cout << "���ݿ���" << endl;
//	}
//	void PourInCap()
//	{
//		cout << "���벣������" << endl;
//	}
//	void AddSomething()
//	{
//		cout << "��ţ��" << endl;
//	}
//};
//
//class Tea :public AbstractDrinking
//{
//public:
//	void Boil()
//	{
//		cout << "�����ɽ" << endl;
//	}
//	void Brew()
//	{
//		cout << "���ݲ�Ҷ" << endl;
//	}
//	void PourInCap()
//	{
//		cout << "�����Ʊ���" << endl;
//	}
//	void AddSomething()
//	{
//		cout << "�����" << endl;
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



//6>�������ʹ�������(?)��
//��̬ʹ��ʱ��������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ�������������룬����ڴ�й¶
//���������ʹ����������������
//���ԣ����Խ������ָ���ͷ����ࣻ��Ҫ�о���ĺ���ʵ��
//���죺����Ǵ��������������������ڳ����࣬�޷�ʵ��������

//�ܽ᣺ֻ���������ж������ݴ���ʱ������Ҫд�������ʹ�������

//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//	virtual void speak() = 0;
//	Animal()
//	{
//		cout << "Animal���캯������ " << endl;
//	}
//
//	//������������
//	/*virtual*/ ~Animal()
//	{
//		cout << "Animal�������������� " << endl;
//	}
//
//	//��������������
//	//virtual ~Animal() = 0;   //����
//};
//
////ʵ��
////Animal::~Animal()
////{
////	cout << "Animal����������������" << endl;
////}
//
//class Cat :public Animal
//{
//public:
//	string* m_name;
//	void speak()
//	{
//		cout << *m_name << "Сè��˵��" << endl;
//	}
//	Cat(string name)
//	{
//		cout << "Cat���캯������" << endl;
//		m_name = new string(name);
//	}
//	~Cat()
//	{
//		cout << "Cat������������" << endl;
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



//7>��̬��������������װ

//#include<iostream>
//using namespace std;
////������
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
//		cout << "Computer������������" << endl;
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
//		cout << "Inter��CPU��ʼ������" << endl;
//	}
//};
//
//class InterVedioCard :public VedioCard
//{
//public:
//	void display()
//	{
//		cout << "Inter���Կ���ʼ��ʾ��" << endl;
//	}
//};
//
//class InterMemory:public Memory
//{
//public:
//	void Storage()
//	{
//		cout << "Inter���ڴ�����ʼ�洢��" << endl;
//	}
//};
//
////Lenovo
//class LenovoCpu :public Cpu
//{
//public:
//	void Calculate()
//	{
//		cout << "Lenovo��CPU��ʼ������" << endl;
//	}
//};
//
//class LenovoVedioCard :public VedioCard
//{
//public:
//	void display()
//	{
//		cout << "Lenovo���Կ���ʼ��ʾ��" << endl;
//	}
//};
//
//class LenovoMemory :public Memory
//{
//public:
//	void Storage()
//	{
//		cout << "Lenovo���ڴ�����ʼ�洢��" << endl;
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




//��.�ļ�����:
//*1.����ͷ�ļ�fstream   *2.����������   *3.���ļ�   *4.��д�ļ�   *5.�ر��ļ�

//1.�ı��ļ���
//1>д�ļ�

//#include<iostream>
////����ͷ�ļ�
//#include<fstream>
//using namespace std;
//int main()
//{
//	//�ļ����������
//	ofstream f;
//	//���ļ���open("�ļ�·��"���򿪷�ʽ)
//	//ios::in(���ļ�),ios::out��д�ļ���,ios::ate(��ʼλ�ã��ļ�β)��ios::app(׷�ӷ�ʽд�ļ�)
//	//ios::binary(�������ļ�)��ios::trunc(����ļ�������ɾ�����ٴ���)
//	f.open("text.txt", ios::out);
//	//д�ļ�
//	f << "��ϲ����" << endl;
//	f << "��������" << endl;
//	//�ر��ļ�
//	f.close();
//	return 0;
//}

//2>���ļ�

//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//int main()
//{
//	ifstream i;
//	i.open("text.txt", ios::in);
//	//�ж��ļ��Ƿ�򿪳ɹ�
//	if (!i.is_open())
//	{
//		cout << "�ļ���ʧ��" << endl;
//		return 0;
//	}
//
//	//д�ļ���
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
//	//while (getline(i, buf))   //getline������stringͷ�ļ���
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//*4.ǰ�涼��һ��һ�ж�ȡ��������һ���ַ�һ���ַ���ȡ
//	char c;
//	while ((c = i.get()) != EOF)
//	{
//		cout << c;
//	}
//
//	i.close();
//	return 0;
//}



//2.�������ļ���
//1>д�ļ�
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
//	//ofstream �й��캯��������ֱ�Ӵ���·���ʹ򿪷�ʽ
//	ofstream ofs("person.txt", ios::out | ios::binary);   //ͨ�� | ���Խ���ͬ�Ĵ򿪷�ʽ����
//	Person p = { "����",20 };
//	ofs.write((const char*)&p, sizeof(Person));
//	ofs.close();
//	return 0;
//}


//2>���ļ�
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
//		cout << "�ļ���ʧ��" << endl;
//		return 0;
//	}
//	Person p;
//	ifs.read((char*)&p, sizeof(Person));
//	cout << p.m_name << " " << p.m_age << endl;
//	ifs.close();
//	return 0;
//}



