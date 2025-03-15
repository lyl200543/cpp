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
	//1.文件不存在
	ifstream ifs;
	ifs.open(FileName, ios::in);

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;  //测试代码
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->is_fileEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在但为空（例如清空文档后）
	char ch;
	ifs >> ch;  //读走一个字符
	if (ifs.eof())
	{
		//cout << "文件存在但为空" << endl;
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->Init();
		this->is_fileEmpty = true;
		ifs.close();
		return;
	}
	//3.文件有信息
	int num = this->Get_EmpNum();
	this->EmpNum = num;
	this->EmpArray = new Worker * [this->EmpNum];
	this->Init();
	this->is_fileEmpty = false;
}

void WorkerManager::ShowMenu()
{
	cout << "*********************************************" << endl;
	cout << "*********** 欢迎使用职工管理系统！***********" << endl;
	cout << "***************0.退出管理程序****************" << endl;
	cout << "***************1.增加职工信息****************" << endl;
	cout << "***************2.显示职工信息****************" << endl;
	cout << "***************3.删除离职职工****************" << endl;
	cout << "***************4.修改职工信息****************" << endl;
	cout << "***************5.查找职工信息****************" << endl;
	cout << "***************6.按照编号排序****************" << endl;
	cout << "***************7.清空所有文档****************" << endl;
	cout << "*********************************************" << endl;
	cout << endl;
}

void WorkerManager::AddEmp()
{
	int AddNum;
	int i;
	cout << "请输入要添加的职工的人数：" << endl;
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
			cout << "请输入第" << i + 1 << "位要添加的职工的职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "位要添加的职工的姓名：" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "位要添加的职工的部门编号：" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
				cout << "输入的部门编号无效" << endl;
				break;
			}
			this->EmpArray[this->EmpNum + i] = worker;
		}

		this->EmpNum = newsize;
		this->Save();
		cout << "添加职工成功！" << endl;
		this->is_fileEmpty = false;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入有误" << endl;
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
		cout << "文件不存在或为空" << endl;
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
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入要删除的职工的编号：" << endl;
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
			cout << "删除职工成功" << endl;
			if (this->EmpNum == 0)
				this->is_fileEmpty = true;
		}
		else
			cout << "该职工不存在" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp()
{
	if (this->is_fileEmpty)
	{
		cout << "该文件不存在或为空" << endl;
	}
	else
	{
		int id;
		string name;
		int Did;
		cout << "请输入要修改的职工的编号：" << endl;
		cin >> id;
		int index = this->is_exist(id);
		if (index != -1)
		{
			delete this->EmpArray[index];
			cout << "查到了编号为" << id << "的职工,请输入职工的新编号：" << endl;
			cin >> id;
			cout << "请输入职工的新姓名：" << endl;
			cin >> name;
			cout << "请输入职工的新部门编号：" << endl;
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
				cout << "输入有误" << endl;
				break;
			}
			this->EmpArray[index] = worker;
			this->Save();
			cout << "职员信息修改成功！" << endl;
		}
		else
			cout << "该职工不存在" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->is_fileEmpty)
		cout << "文件不存在或为空" << endl;
	else
	{
		int way;
		cout << "请输入查找的方式：" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;  //有重名的可能
		cin >> way;
		if (way == 1)
		{
			int id;
			cout << "请输入要查找的职工的编号：" << endl;
			cin >> id;
			int index = this->is_exist(id);
			if (index != -1)
			{
				cout << "该职工的信息如下：" << endl;
				this->EmpArray[index]->ShowInfo();
			}
			else
				cout << "该职工不存在" << endl;
		}
		else if (way == 2)
		{
			string name;
			cout << "请输入要查找的职工的姓名：" << endl;
			cin >> name;
			int flag = 0;
			for (int i = 0; i < this->EmpNum; i++)
			{
				if (this->EmpArray[i]->m_name == name)
				{
					cout << "该姓名的编号为" << this->EmpArray[i]->m_id
						<< "的职工的信息如下：" << endl;
					this->EmpArray[i]->ShowInfo();
					flag = 1;
				}
			}
			if (flag == 0)
				cout << "该职工不存在" << endl;
		}
		else
			cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if(this->is_fileEmpty )
	{
		cout << "文件不存在或为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int way;
		cout << "请输入排序的方式：" << endl;
		cout << "1.按升序排列编号" << endl;
		cout << "2.按降序排列编号" << endl;
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
		cout << "排序成功！" << endl;
		this->Save();
		cout << "排序后的结果为：" << endl;
		this->Show_Emp();
	}
}

void WorkerManager::Clean_Emp()
{
	int choice;
	cout << "确定要清空文档吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	cin >> choice;
	if (choice == 1)
	{
		if (!this->is_fileEmpty)
		{
			//清空文档
			ofstream ofs;
			ofs.open(FileName, ios::trunc);  //如果文件存在则删除再创建新文件（空的）
			ofs.close();

			//清空数组
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
			cout << "清空成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}


void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
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