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
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t���ű�ţ�" << this->GetDep()
		<< "\t��Ҫְ������ϰ巢�������񣬲��·������Ա��" << endl;

}
string Manager::GetDep()
{
	return string("����");
}