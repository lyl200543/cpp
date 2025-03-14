#include"WorkerManager.h"
#include"Worker.h"
#include<string>
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;
WorkerManager::WorkerManager()
{
	this->EmpNum = 0;
	this->EmpArray = NULL;
}

void WorkerManager::ShowMenu()
{
	cout << "*********************************************" << endl;
	cout << "*********** ��ӭʹ��ְ������ϵͳ��***********" << endl;
	cout << "***************0.�˳��������****************" << endl;
	cout << "***************1.����ְ����Ϣ****************" << endl;
	cout << "***************2.��ʾְ����Ϣ****************" << endl;
	cout << "***************3.ɾ����ְְ��****************" << endl;
	cout << "***************4.�޸�ְ����Ϣ****************" << endl;
	cout << "***************5.����ְ����Ϣ****************" << endl;
	cout << "***************6.���ձ������****************" << endl;
	cout << "***************7.��������ĵ�****************" << endl;
	cout << "*********************************************" << endl;
	cout << endl;
}

void WorkerManager::AddEmp()
{
	int AddNum;
	int i;
	cout << "������Ҫ��ӵ�ְ����������" << endl;
	cin >> AddNum;
	if (AddNum > 0)
	{
		int newsize = AddNum + this->EmpNum;
		Worker** newspace = new Worker * [newsize];
		if (this->EmpArray != NULL)
		{
			for (i = 0; i < this->EmpNum; i++)
			{
				newspace[i] = this->EmpArray[i];
			}
			delete[] this->EmpArray;
		}
		this->EmpArray = newspace;
		for (i = 0; i < AddNum; i++)
		{
			int id;
			string name;
			int Did;
			Worker* worker = NULL;
			cout << "�������" << i + 1 << "λҪ��ӵ�ְ����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "λҪ��ӵ�ְ����������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "λҪ��ӵ�ְ���Ĳ��ű�ţ�" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> Did;
			switch (Did)
			{
			case 1:
				worker = new Employee(id, name, Did);
				break;
			case 2:
				worker = new Manager(id, name, Did);
				break;
			case 3:
				worker = new Boss(id, name, Did);
				break;
			default:
				cout << "����Ĳ��ű����Ч" << endl;
				break;
			}
			this->EmpArray[this->EmpNum + i] = worker;
		}

		this->EmpNum = newsize;
		cout << "���ְ���ɹ���" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������" << endl;
		return;
	}
}


void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}

WorkerManager::~WorkerManager()
{

}