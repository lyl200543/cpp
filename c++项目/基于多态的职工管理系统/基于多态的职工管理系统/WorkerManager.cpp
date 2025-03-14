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
		cout << "添加职工成功！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入有误" << endl;
		return;
	}
}


void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}

WorkerManager::~WorkerManager()
{

}