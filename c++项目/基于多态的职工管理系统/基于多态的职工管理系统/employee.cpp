#include<iostream>
#include"employee.h"
using namespace std;
Employee::Employee(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}

void Employee::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t���ű�ţ�" << this->GetDep()
		<< "\t��Ҫְ����ɾ�����������" << endl;
}

string Employee::GetDep()
{
	return string("Ա��");
}
