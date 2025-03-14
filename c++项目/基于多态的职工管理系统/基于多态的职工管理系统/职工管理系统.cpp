#include<iostream>
#include"WorkerManager.h"
using namespace std;
int main()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.ShowMenu();
		cout << "请输入您的选择： " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //添加职工
			wm.AddEmp();
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //职工排序
			break;
		case 7: //清空文档
			break;
		default:
			system("cls");  //清屏操作
		}
	}
	return 0;
}