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
		cout << "����������ѡ�� " << endl;
		cin >> choice;
		switch (choice)  //case�µ����̫���Ļ���Ҫʹ�ô�����
		{
		case 0: //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1: //���ְ��
			wm.AddEmp();
			break;
		case 2: //��ʾְ��
			wm.Show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_Emp();
			break;
		case 6: //ְ������
			wm.Sort_Emp();
			break;
		case 7: //����ĵ�
			wm.Clean_Emp();
			break;
		default:
			system("cls");  //��������
		}
	}
	return 0;
}