#include<iostream>
using namespace std;
#include<string>
#define MAX 1000


//������ϵ�˽ṹ�����
struct Person
{
	//����
	string m_Name;
	//1���� 2��Ů
	int m_Sex;
	//����
	int m_Age ;
	//����
	string  m_Num ;
	//��ַ
	string m_Address;
};
//����ͨѶ¼�ṹ�����
struct AddressBooks
{
	//��ϵ������
	struct Person presonArray[MAX];
	//����
	int m_Size=0;

};
//�˵�
void showMenu()
{
	cout << "******************************" << endl;
	cout << "******	1�������ϵ��	******" << endl;
	cout << "******	2����ʾ��ϵ��	******" << endl;
	cout << "******	3��ɾ����ϵ��	******" << endl;
	cout << "******	4��������ϵ��	******" << endl;
	cout << "******	5���޸���ϵ��	******" << endl;
	cout << "******	6�������ϵ��	******" << endl;
	cout << "******	0���˳�ͨѶ¼	******" << endl;
	cout << "******************************" << endl;

}
//1�������ϵ��
void AddPerson(AddressBooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else
	{
		//���

		//����
		cout << "����������" << endl;
		string name;
		cin >> name;
		abs->presonArray[abs->m_Size].m_Name = name;

		//����
		cout << "����������" << endl;
		int age;
		cin >> age;
		abs->presonArray[abs->m_Size].m_Age = age;
		//�Ա�
		cout << "�������Ա�" << endl;
		int sex;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->presonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "����������������룡����" << endl;
		}
		//����
		cout << "���������" << endl;
		string num;
		cin >> num;
		abs->presonArray[abs->m_Size].m_Num = num;

		//��ַ
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->presonArray[abs->m_Size].m_Address = address;

		//��������
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");//����

	}
}
//2����ʾ��ϵ��
void ShowPerson(AddressBooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
		system("pause");
		system("cls");//����
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->presonArray[i].m_Name << "\t";
			cout << "���䣺" << abs->presonArray[i].m_Age << "\t";
			cout << "�Ա�" << (abs->presonArray[i].m_Sex==1?"��":"Ů" )<< "\t";
			cout << "���룺" << abs->presonArray[i].m_Num << "\t";
			cout << "��ַ��" << abs->presonArray[i].m_Address << endl;
		}
		system("pause");
		system("cls");//����
	}
}
//�����ϵ���Ƿ����
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ����
		if (abs->presonArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;//û�ҵ�
}
//3��ɾ����ϵ��
void deletePerson(AddressBooks* abs)
{
	cout << "������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->presonArray[i] = abs->presonArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");//����
}
//4��������ϵ��
void findPerson(AddressBooks* abs)
{
	cout << "��������ҵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->presonArray[ret].m_Name << "\t";
		cout << "���䣺" << abs->presonArray[ret].m_Age << "\t";
		cout << "�Ա�" << (abs->presonArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���룺" << abs->presonArray[ret].m_Num << "\t";
		cout << "��ַ��" << abs->presonArray[ret].m_Address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//5���޸���ϵ����Ϣ
void modifyPerson(AddressBooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		cout << "����������" << endl;
		string name;
		cin >> name;
		abs->presonArray[ret].m_Name = name;

		//����
		cout << "����������" << endl;
		int age;
		cin >> age;
		abs->presonArray[ret].m_Age = age;
		//�Ա�
		cout << "�������Ա�" << endl;
		int sex;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->presonArray[ret].m_Sex = sex;
				break;
			}
			cout << "����������������룡����" << endl;
		}
		//����
		cout << "���������" << endl;
		string num;
		cin >> num;
		abs->presonArray[ret].m_Num = num;

		//��ַ
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->presonArray[ret].m_Address = address;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanPerson(AddressBooks* abs)
{
	cout << "�Ƿ����" << endl;
	cout << "1---ȷ�����" << endl;
	cout << "2---�������" << endl;
	int i;
	cin >> i;
	if (i == 1)
	{
		abs->m_Size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	if (i == 2)
	{
		cout << "�������" << endl;
	}
	system("pause");

	system("cls");
}
int main()
{
	//����ͨѶ¼�ṹ�����
	AddressBooks abs;
	//��ʼ����Ա����
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
			case 1:		//1�������ϵ��
				AddPerson(&abs);
				break;
			case 2:		//2����ʾ��ϵ��
				ShowPerson(&abs);
				break;
			case 3:		//3��ɾ����ϵ��
				deletePerson(&abs);
				break;
			case 4:		//4��������ϵ��
				findPerson(&abs);
				break;
			case 5:		//5���޸���ϵ��
				modifyPerson(&abs);
				break;
			case 6:		//6�������ϵ��
				cleanPerson(&abs);
				break;
			case 0:		//0���˳�ͨѶ¼
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
				break;
			}
		}
		else
		{
			cout << "�������" << endl;
			cout << "����������" << endl;
			system("pause");
			system("cls");

		}
	}

	system("pause");
	return  0;
}
