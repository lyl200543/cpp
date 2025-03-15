#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class WorkerManager
{
public:
	int EmpNum;
	Worker** EmpArray;
	bool is_fileEmpty;

	//构造函数
	WorkerManager();
	//展示菜单
	void ShowMenu();
	//添加职工
	void AddEmp();
	//保存信息
	void Save();
	//获取人数
	int Get_EmpNum();
	//删除职工
	void Del_Emp();
	//判断职工是否存在
	int is_exist(int n);
	//修改职工信息
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//职工排序
	void Sort_Emp();
	//清空文档
	void Clean_Emp();
	//初始化信息
	void Init();
	//显示职工信息
	void Show_Emp();
	//退出系统
	void ExitSystem();
	//析构函数
	~WorkerManager();
};