#include"workerManager.h"


//构造函数
WorkerManager::WorkerManager()
{
	//1、文件不存在
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;//测试输出

		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2、文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//cout << "文件为空！" << endl;//测试输出

		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3、文件存在，并且记录了数据
	int num = this->get_EmpNum();

	//cout << "职工人数为：" << num << endl;//测试代码

	this->m_EmpNum = num;
	//开辟空间，将文件中的数据存到数组中
	this->m_EmpArray = new Worker* [this->m_EmpNum];
	this->init_Emp();


	//测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_ID
	//		<< "\t职工姓名：" << this->m_EmpArray[i]->m_Name
	//		<< "\t岗位：" << this->m_EmpArray[i]->m_DeptID
	//		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
	//}
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else//老板
		{
			worker = new Boss(id, name, dId);

		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//统计人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	return num;
}

//展示菜单
void WorkerManager::Show_Menu()
{
	cout << "****************************************************" << endl;
	cout << "*************** 欢迎使用职工管理系统 ***************" << endl;
	cout << "****************** 0.退出管理程序 ******************" << endl;
	cout << "****************** 1.增加员工信息 ******************" << endl;
	cout << "****************** 2.显示职工信息 ******************" << endl;
	cout << "****************** 3.删除离职员工 ******************" << endl;
	cout << "****************** 4.修改职工信息 ******************" << endl;
	cout << "****************** 5.查找职工信息 ******************" << endl;
	cout << "****************** 6.按照编号排序 ******************" << endl;
	cout << "****************** 7.清空所有文档 ******************" << endl;
	cout << "****************************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

//添加员工
void WorkerManager::ADD_Emp()
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker* [newSize];

		//将原来空间里的数据，拷贝到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;//部门选择

			cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
			cin >> name;

			cout <<"请选择该职工岗位： " << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;

			}
			//将创建的职工，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}

		//释放原有的空间
		delete[]this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//保存数据到文件中
		this->save();

		//更新数据不为空的标志
		this->m_FileIsEmpty = false;
		
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件  —— 写文件

	//将每个人数据写入文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	//关闭文件
	ofs.close();
}

//展示员工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按编号删除职工
		cout << "输入想要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//职工存在，并且要删除掉index位置上的数据
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新数组中记录的人员个数
			this->m_EmpNum--;
			//数据同步更新到文件中
			this->save();

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//按照员工编号判断职工是否存在，如果存在返回职工在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}

//修改职工
void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入职工编号：" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到编号的职工

			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = "";
			int dSelect = 0;

			cout << "查到： " << id << "号的职工，请输入新职工号：" << endl;
			cin >> newid;

			cout << "请输入新姓名" << endl;
			cin >> newname;

			cout << "请输入新的岗位" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newid, newname, 1);
				break;
			case 2:
				worker = new Manager(newid, newname, 2);
				break;
			case 3:
				worker = new Boss(newid, newname, 1);
				break;
			default:
				break;
			}
			//更新数据到数组
			this->m_EmpArray[ret] = worker;
			//更新数据到磁盘
			this->save();
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}


//查找职工 
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照职工编号查找
			int id = 0;
			cout << "请输入查找员工的编号：" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			//按照职工姓名查找
			string name;
			cout << "请输入查找职工的姓名：" << endl;
			cin >> name;
			//加入判断是否插找成功的标志  默认为false
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_ID << "号的职工信息如下：" << endl;
					//显示信息
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人!" << endl;
			}

		}
		else
		{
			cout << "输入错误！！！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//按照编号排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、按照职工号升序排列" << endl;
		cout << "2、按照职工号降序排列" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrmax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrmax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minOrmax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrmax = j;
					}
				}
			}

			//判断一开始认定的 最大值或者最小值 是否与计算出的 最大值或者最小值 相等，不相等则交换
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = this->m_EmpArray[i];
				this->m_EmpArray[i] = temp;
			}
		}
	}
	this->save();
	cout << "排序成功！结果为：" << endl;
	this->Show_Emp();
}

//清空数据
void WorkerManager::Clean_File()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "确认是否清空：" << endl;
		cout << "1、确认" << endl;
		cout << "2、返回" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//打开模式  ios::trunc 如果存在 删除文件并重新创建
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();

			if (this->m_EmpArray != NULL)
			{
				//删除堆区的每个职工对象
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i] != NULL)
					{
						delete this->m_EmpArray[i];
					}
				}
				//删除堆区数组指针
				delete[] this->m_EmpArray;

				this->m_EmpNum = 0;
				this->m_EmpArray = NULL;
				this->m_FileIsEmpty = true;
			}
			cout << "清除成功！" << endl;
		}
	}
	system("pause");
	system("cls");

}

//析构函数
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		this->m_EmpNum = 0;
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}