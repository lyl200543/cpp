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
		switch (choice)  //case下的语句太长的话，要使用大括号
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //添加职工
			wm.AddEmp();
			break;
		case 2: //显示职工
			wm.Show_Emp();
			break;
		case 3: //删除职工
			wm.Del_Emp();
			break;
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: //职工排序
			wm.Sort_Emp();
			break;
		case 7: //清空文档
			wm.Clean_Emp();
			break;
		default:
			system("cls");  //清屏操作
		}
	}
	return 0;
}