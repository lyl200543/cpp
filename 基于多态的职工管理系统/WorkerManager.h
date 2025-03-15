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

	//���캯��
	WorkerManager();
	//չʾ�˵�
	void ShowMenu();
	//���ְ��
	void AddEmp();
	//������Ϣ
	void Save();
	//��ȡ����
	int Get_EmpNum();
	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ����
	int is_exist(int n);
	//�޸�ְ����Ϣ
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//ְ������
	void Sort_Emp();
	//����ĵ�
	void Clean_Emp();
	//��ʼ����Ϣ
	void Init();
	//��ʾְ����Ϣ
	void Show_Emp();
	//�˳�ϵͳ
	void ExitSystem();
	//��������
	~WorkerManager();
};