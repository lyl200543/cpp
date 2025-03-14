#include<iostream>
#include<string>
#include"boss.h"
using namespace std;

Boss::Boss (int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}
void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t部门编号：" << this->GetDep()
		<< "\t主要职务：管理公司的所有事务" << endl;

}
string Boss::GetDep()
{
	return string("老板");
}