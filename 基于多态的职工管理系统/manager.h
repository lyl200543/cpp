#pragma once
#include"Worker.h"
#include<string>
using namespace std;

class Manager : public Worker
{
public:
	Manager(int id, string name, int Did);
	void ShowInfo();
	string GetDep();
};