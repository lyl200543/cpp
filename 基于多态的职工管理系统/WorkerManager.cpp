#include"WorkerManager.h"
#include"Worker.h"
#include<iostream>
#include<string>
#include<fstream>
#include"employee.h"
#include"manager.h"
#include"boss.h"

#define FileName "Example.txt"

using namespace std;
WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FileName, ios::in);

	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;  //���Դ���
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->is_fileEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�Ϊ�գ���������ĵ���
	char ch;
	ifs >> ch;  //����һ���ַ�
	if (ifs.eof())
	{
		//cout << "�ļ����ڵ�Ϊ��" << endl;
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->Init();
		this->is_fileEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ�����Ϣ
	int num = this->Get_EmpNum();
	this->EmpNum = num;
	this->EmpArray = new Worker * [this->EmpNum];
	this->Init();
	this->is_fileEmpty = false;
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
		this->Save();
		cout << "���ְ���ɹ���" << endl;
		this->is_fileEmpty = false;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������" << endl;
		return;
	}
}

void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FileName, ios::out);
	for (int i = 0; i < this->EmpNum; i++)
	{
		ofs << this->EmpArray[i]->m_id << " "
			<< this->EmpArray[i]->m_name << " "
			<< this->EmpArray[i]->m_Did << endl;
	}
	ofs.close();
}

int WorkerManager::Get_EmpNum()
{
	ifstream ifs;
	ifs.open(FileName, ios::in);
	int id;
	string name;
	int Did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> Did)
		num++;
	ifs.close();
	return num;
}

void WorkerManager::Init()
{
	ifstream ifs;
	ifs.open(FileName, ios::in);
	int id;
	string name;
	int Did;
	Worker* worker = NULL;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> Did)
	{
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
		}
		this->EmpArray[index++] = worker;
	}
	ifs.close();
}

void WorkerManager::Show_Emp()
{
	if (this->is_fileEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->EmpNum; i++)
		{
			this->EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::is_exist(int n)
{
	int index = -1;
	for (int i = 0; i < this->EmpNum; i++)
	{
		if (this->EmpArray[i]->m_id == n)
			index = i;
	}
	return index;
}

void WorkerManager::Del_Emp()
{
	if (this->is_fileEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		int id;
		cout << "������Ҫɾ����ְ���ı�ţ�" << endl;
		cin >> id;
		int index = this->is_exist(id);
		if (index != -1)
		{
			for (int i = index; i < this->EmpNum - 1; i++)
			{
				this->EmpArray[i] = this->EmpArray[i + 1];
			}
			free(this->EmpArray[this->EmpNum - 1]);
			this->EmpNum--;
			this->Save();
			cout << "ɾ��ְ���ɹ�" << endl;
			if (this->EmpNum == 0)
				this->is_fileEmpty = true;
		}
		else
			cout << "��ְ��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp()
{
	if (this->is_fileEmpty)
	{
		cout << "���ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		int id;
		string name;
		int Did;
		cout << "������Ҫ�޸ĵ�ְ���ı�ţ�" << endl;
		cin >> id;
		int index = this->is_exist(id);
		if (index != -1)
		{
			delete this->EmpArray[index];
			cout << "�鵽�˱��Ϊ" << id << "��ְ��,������ְ�����±�ţ�" << endl;
			cin >> id;
			cout << "������ְ������������" << endl;
			cin >> name;
			cout << "������ְ�����²��ű�ţ�" << endl;
			cin >> Did;
			Worker* worker = NULL;
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
				cout << "��������" << endl;
				break;
			}
			this->EmpArray[index] = worker;
			this->Save();
			cout << "ְԱ��Ϣ�޸ĳɹ���" << endl;
		}
		else
			cout << "��ְ��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->is_fileEmpty)
		cout << "�ļ������ڻ�Ϊ��" << endl;
	else
	{
		int way;
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.����Ų���" << endl;
		cout << "2.����������" << endl;  //�������Ŀ���
		cin >> way;
		if (way == 1)
		{
			int id;
			cout << "������Ҫ���ҵ�ְ���ı�ţ�" << endl;
			cin >> id;
			int index = this->is_exist(id);
			if (index != -1)
			{
				cout << "��ְ������Ϣ���£�" << endl;
				this->EmpArray[index]->ShowInfo();
			}
			else
				cout << "��ְ��������" << endl;
		}
		else if (way == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�ְ����������" << endl;
			cin >> name;
			int flag = 0;
			for (int i = 0; i < this->EmpNum; i++)
			{
				if (this->EmpArray[i]->m_name == name)
				{
					cout << "�������ı��Ϊ" << this->EmpArray[i]->m_id
						<< "��ְ������Ϣ���£�" << endl;
					this->EmpArray[i]->ShowInfo();
					flag = 1;
				}
			}
			if (flag == 0)
				cout << "��ְ��������" << endl;
		}
		else
			cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if(this->is_fileEmpty )
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int way;
		cout << "����������ķ�ʽ��" << endl;
		cout << "1.���������б��" << endl;
		cout << "2.���������б��" << endl;
		cin >> way;
		int i, j;
		for (i = 0; i < this->EmpNum; i++)
		{
			int MinOrMax = i;
			for (j = i + 1; j < this->EmpNum; j++)
			{
				if (way == 1)
				{
					if (this->EmpArray[MinOrMax]->m_id  > this->EmpArray[j]->m_id )
						MinOrMax = j;
				}
				else
				{
					if (this->EmpArray[MinOrMax]->m_id  < this->EmpArray[j]->m_id )
						MinOrMax = j;
				}
			}
			if (i != MinOrMax)
			{
				Worker* tmp = this->EmpArray[i];
				this->EmpArray[i] = this->EmpArray[MinOrMax];
				this->EmpArray[MinOrMax] = tmp;
			}
		}
		cout << "����ɹ���" << endl;
		this->Save();
		cout << "�����Ľ��Ϊ��" << endl;
		this->Show_Emp();
	}
}

void WorkerManager::Clean_Emp()
{
	int choice;
	cout << "ȷ��Ҫ����ĵ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	cin >> choice;
	if (choice == 1)
	{
		if (!this->is_fileEmpty)
		{
			//����ĵ�
			ofstream ofs;
			ofs.open(FileName, ios::trunc);  //����ļ�������ɾ���ٴ������ļ����յģ�
			ofs.close();

			//�������
			if (this->EmpArray != NULL)
			{
				for (int i = 0; i < this->EmpNum; i++)
				{
					if (this->EmpArray[i] != NULL)
					{
						delete this->EmpArray[i];
						this->EmpArray[i] = NULL;
					}
				}
				delete[] this->EmpArray;
				this->EmpArray = NULL;
			}
			this->EmpNum = 0;
			this->is_fileEmpty = true;
			cout << "��ճɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}


void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}

WorkerManager::~WorkerManager()
{
	if (this->EmpArray != NULL)
	{
		for (int i = 0; i < this->EmpNum; i++)
		{
			if (this->EmpArray[i] != NULL)
			{
				delete this->EmpArray[i];
				this->EmpArray[i] = NULL;
			}
		}
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}