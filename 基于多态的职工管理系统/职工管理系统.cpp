#include<iostream>
using namespace std;
#include"workerManager.h"

#include"employee.h"
#include"worker.h"
#include"manager.h"
#include"boss.h"

int main()
{

	////���Դ��룺
	//Woker* woker = NULL;
	//woker = new Employee(1, "����", 1);
	//woker->showInfo();
	//delete woker;

	//woker = new Manager(2, "����",2);
	//woker->showInfo();
	//delete woker;

	//woker = new Boss(3, "����", 3);
	//woker->showInfo();
	//delete woker;



	//ʵ���������߶���
	WorkerManager wm;
	int choice = 0; //�洢�û���ѡ��
	while (true)
	{
			
		//չʾ�˵���Ա����
		wm.Show_Menu();
		cout << "����������ѡ��: " << endl;
		cin >> choice; //�����û���ѡ��
		switch (choice)
		{
		case 0://�˳��������
			wm.ExitSystem();
			break;
		case 1://����Ա����Ϣ
			wm.ADD_Emp();
			break;
		case 2://��ʾְ����Ϣ
			wm.Show_Emp();
			break;
		case 3://ɾ����ְԱ��
			//����
		/*{
			int ret = wm.IsExist(4);
			if (ret != -1)
			{
				cout << "����" << endl;
			}
			else
			{
				cout << "������" << endl;
			}
		}*/
			wm.Del_Emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.mod_Emp();
			break;
		case 5://����ְ����Ϣ
			wm.Find_Emp();
			break;
		case 6://���ձ������
			wm.Sort_Emp();
			break;
		case 7://��������ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}