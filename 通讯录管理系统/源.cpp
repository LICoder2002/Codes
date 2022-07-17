#include<iostream>
using namespace std;
#include<string>
#define MAX 1000


//创建联系人结构体变量
struct Person
{
	//姓名
	string m_Name;
	//1、男 2、女
	int m_Sex;
	//年龄
	int m_Age ;
	//号码
	string  m_Num ;
	//地址
	string m_Address;
};
//创建通讯录结构体变量
struct AddressBooks
{
	//联系人数组
	struct Person presonArray[MAX];
	//人数
	int m_Size=0;

};
//菜单
void showMenu()
{
	cout << "******************************" << endl;
	cout << "******	1、添加联系人	******" << endl;
	cout << "******	2、显示联系人	******" << endl;
	cout << "******	3、删除联系人	******" << endl;
	cout << "******	4、查找联系人	******" << endl;
	cout << "******	5、修改联系人	******" << endl;
	cout << "******	6、清空联系人	******" << endl;
	cout << "******	0、退出通讯录	******" << endl;
	cout << "******************************" << endl;

}
//1、添加联系人
void AddPerson(AddressBooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
	}
	else
	{
		//添加

		//姓名
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		abs->presonArray[abs->m_Size].m_Name = name;

		//年龄
		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		abs->presonArray[abs->m_Size].m_Age = age;
		//性别
		cout << "请输入性别" << endl;
		int sex;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->presonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入！！！" << endl;
		}
		//号码
		cout << "请输入号码" << endl;
		string num;
		cin >> num;
		abs->presonArray[abs->m_Size].m_Num = num;

		//地址
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->presonArray[abs->m_Size].m_Address = address;

		//更新人数
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");//清屏

	}
}
//2、显示联系人
void ShowPerson(AddressBooks* abs)
{
	//判断通讯录中人数是否为0
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
		system("pause");
		system("cls");//清屏
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->presonArray[i].m_Name << "\t";
			cout << "年龄：" << abs->presonArray[i].m_Age << "\t";
			cout << "性别：" << (abs->presonArray[i].m_Sex==1?"男":"女" )<< "\t";
			cout << "号码：" << abs->presonArray[i].m_Num << "\t";
			cout << "地址：" << abs->presonArray[i].m_Address << endl;
		}
		system("pause");
		system("cls");//清屏
	}
}
//检查联系人是否存在
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到结果
		if (abs->presonArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;//没找到
}
//3、删除联系人
void deletePerson(AddressBooks* abs)
{
	cout << "请输入要删除的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->presonArray[i] = abs->presonArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");//清屏
}
//4、查找联系人
void findPerson(AddressBooks* abs)
{
	cout << "请输入查找的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->presonArray[ret].m_Name << "\t";
		cout << "年龄：" << abs->presonArray[ret].m_Age << "\t";
		cout << "性别：" << (abs->presonArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "号码：" << abs->presonArray[ret].m_Num << "\t";
		cout << "地址：" << abs->presonArray[ret].m_Address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//5、修改联系人信息
void modifyPerson(AddressBooks* abs)
{
	cout << "请输入要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		abs->presonArray[ret].m_Name = name;

		//年龄
		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		abs->presonArray[ret].m_Age = age;
		//性别
		cout << "请输入性别" << endl;
		int sex;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->presonArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入！！！" << endl;
		}
		//号码
		cout << "请输入号码" << endl;
		string num;
		cin >> num;
		abs->presonArray[ret].m_Num = num;

		//地址
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->presonArray[ret].m_Address = address;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void cleanPerson(AddressBooks* abs)
{
	cout << "是否清空" << endl;
	cout << "1---确认清空" << endl;
	cout << "2---放弃清空" << endl;
	int i;
	cin >> i;
	if (i == 1)
	{
		abs->m_Size = 0;
		cout << "通讯录已清空" << endl;
	}
	if (i == 2)
	{
		cout << "放弃清空" << endl;
	}
	system("pause");

	system("cls");
}
int main()
{
	//创建通讯录结构体变量
	AddressBooks abs;
	//初始化人员个数
	abs.m_Size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		if (select >= 0 && select <= 6)
		{
			switch (select)
			{
			case 1:		//1、添加联系人
				AddPerson(&abs);
				break;
			case 2:		//2、显示联系人
				ShowPerson(&abs);
				break;
			case 3:		//3、删除联系人
				deletePerson(&abs);
				break;
			case 4:		//4、查找联系人
				findPerson(&abs);
				break;
			case 5:		//5、修改联系人
				modifyPerson(&abs);
				break;
			case 6:		//6、清空联系人
				cleanPerson(&abs);
				break;
			case 0:		//0、退出通讯录
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
				break;
			}
		}
		else
		{
			cout << "输入错误" << endl;
			cout << "请重新输入" << endl;
			system("pause");
			system("cls");

		}
	}

	system("pause");
	return  0;
}
