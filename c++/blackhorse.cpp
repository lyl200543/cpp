//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}

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

#include<iostream>
using namespace std;
int main()
{
	return 0;
}



//5.���������:



//6.�̳�:



//7.��̬:



//��.�ļ�����:

