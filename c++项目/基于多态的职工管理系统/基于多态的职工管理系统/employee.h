#pragma once
#include"Worker.h"

class Employee :public Worker
{
public:
	Employee(int id, string name, int Did);
	void ShowInfo();
	string GetDep();
};