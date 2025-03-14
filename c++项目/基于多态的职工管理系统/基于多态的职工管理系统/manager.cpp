#include<iostream>
#include<string>
#include"manager.h"
using namespace std;

Manager::Manager(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}
void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t部门编号：" << this->GetDep()
		<< "\t主要职务：完成老板发布的任务，并下发任务给员工" << endl;

}
string Manager::GetDep()
{
	return string("经理");
}