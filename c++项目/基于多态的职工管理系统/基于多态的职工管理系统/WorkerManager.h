#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class WorkerManager
{
public:
	int EmpNum;
	Worker** EmpArray;


	//构造函数
	WorkerManager();
	//展示菜单
	void ShowMenu();
	//添加职工
	void AddEmp();
	//退出系统
	void ExitSystem();
	//析构函数
	~WorkerManager();
};