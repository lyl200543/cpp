#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class WorkerManager
{
public:
	int EmpNum;
	Worker** EmpArray;


	//���캯��
	WorkerManager();
	//չʾ�˵�
	void ShowMenu();
	//���ְ��
	void AddEmp();
	//�˳�ϵͳ
	void ExitSystem();
	//��������
	~WorkerManager();
};