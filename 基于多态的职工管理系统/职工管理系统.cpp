#include<iostream>
using namespace std;
#include"workerManager.h"

#include"employee.h"
#include"worker.h"
#include"manager.h"
#include"boss.h"

int main()
{

	////测试代码：
	//Woker* woker = NULL;
	//woker = new Employee(1, "张三", 1);
	//woker->showInfo();
	//delete woker;

	//woker = new Manager(2, "李四",2);
	//woker->showInfo();
	//delete woker;

	//woker = new Boss(3, "王五", 3);
	//woker->showInfo();
	//delete woker;



	//实例化管理者对象
	WorkerManager wm;
	int choice = 0; //存储用户的选项
	while (true)
	{
			
		//展示菜单成员函数
		wm.Show_Menu();
		cout << "请输入您的选择: " << endl;
		cin >> choice; //接受用户的选项
		switch (choice)
		{
		case 0://退出管理程序
			wm.ExitSystem();
			break;
		case 1://增加员工信息
			wm.ADD_Emp();
			break;
		case 2://显示职工信息
			wm.Show_Emp();
			break;
		case 3://删除离职员工
			//测试
		/*{
			int ret = wm.IsExist(4);
			if (ret != -1)
			{
				cout << "存在" << endl;
			}
			else
			{
				cout << "不存在" << endl;
			}
		}*/
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.mod_Emp();
			break;
		case 5://查找职工信息
			wm.Find_Emp();
			break;
		case 6://按照编号排序
			wm.Sort_Emp();
			break;
		case 7://清空所有文档
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