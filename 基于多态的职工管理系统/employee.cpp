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
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t部门编号：" << this->GetDep()
		<< "\t主要职务：完成经理发布的任务" << endl;
}

string Employee::GetDep()
{
	return string("员工");
}
