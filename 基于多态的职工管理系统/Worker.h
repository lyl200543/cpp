#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	int m_id;
	string m_name;
	int m_Did;

	virtual void ShowInfo() = 0;
	virtual string GetDep() = 0;
};