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
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t���ű�ţ�" << this->GetDep()
		<< "\t��Ҫְ�񣺹���˾����������" << endl;

}
string Boss::GetDep()
{
	return string("�ϰ�");
}