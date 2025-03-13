#include<iostream>
#include"WorkerManager.h"
#include"Worker.h"
#include"employee.h"
using namespace std;
int main()
{
	Worker* worker = new Employee(1, "zhangsan", 1);
	worker->ShowInfo();

	//WorkerManager wm;
	//int choice = 0;
	//while (true)
	//{
	//	wm.ShowMenu();
	//	cout << "请输入您的选择： " << endl;
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	case 0: //退出系统
	//		wm.ExitSystem();
	//		break;
	//	case 1: //加入职工
	//		break;
	//	case 2: //显示职工
	//		break;
	//	case 3: //删除职工
	//		break;
	//	case 4: //修改职工
	//		break;
	//	case 5: //查找职工
	//		break;
	//	case 6: //职工排序
	//		break;
	//	case 7: //清空文档
	//		break;
	//	default:
	//		system("cls");  //清屏操作
	//	}
	//}
	return 0;
}