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
	//	cout << "����������ѡ�� " << endl;
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	case 0: //�˳�ϵͳ
	//		wm.ExitSystem();
	//		break;
	//	case 1: //����ְ��
	//		break;
	//	case 2: //��ʾְ��
	//		break;
	//	case 3: //ɾ��ְ��
	//		break;
	//	case 4: //�޸�ְ��
	//		break;
	//	case 5: //����ְ��
	//		break;
	//	case 6: //ְ������
	//		break;
	//	case 7: //����ĵ�
	//		break;
	//	default:
	//		system("cls");  //��������
	//	}
	//}
	return 0;
}