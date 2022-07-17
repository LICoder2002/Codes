#include"workerManager.h"


//���캯��
WorkerManager::WorkerManager()
{
	//1���ļ�������
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;//�������

		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ�գ�" << endl;//�������

		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3���ļ����ڣ����Ҽ�¼������
	int num = this->get_EmpNum();

	//cout << "ְ������Ϊ��" << num << endl;//���Դ���

	this->m_EmpNum = num;
	//���ٿռ䣬���ļ��е����ݴ浽������
	this->m_EmpArray = new Worker* [this->m_EmpNum];
	this->init_Emp();


	//���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_ID
	//		<< "\tְ��������" << this->m_EmpArray[i]->m_Name
	//		<< "\t��λ��" << this->m_EmpArray[i]->m_DeptID
	//		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
	//}
}

//��ʼ��Ա��
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
		if (dId == 1)//��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, dId);

		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//ͳ������
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

//չʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "****************************************************" << endl;
	cout << "*************** ��ӭʹ��ְ������ϵͳ ***************" << endl;
	cout << "****************** 0.�˳�������� ******************" << endl;
	cout << "****************** 1.����Ա����Ϣ ******************" << endl;
	cout << "****************** 2.��ʾְ����Ϣ ******************" << endl;
	cout << "****************** 3.ɾ����ְԱ�� ******************" << endl;
	cout << "****************** 4.�޸�ְ����Ϣ ******************" << endl;
	cout << "****************** 5.����ְ����Ϣ ******************" << endl;
	cout << "****************** 6.���ձ������ ******************" << endl;
	cout << "****************** 7.��������ĵ� ******************" << endl;
	cout << "****************************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

//���Ա��
void WorkerManager::ADD_Emp()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker* [newSize];

		//��ԭ���ռ�������ݣ��������¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;//����ѡ��

			cout << "������� " << i + 1 << " ����ְ����ţ� " << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ�������� " << endl;
			cin >> name;

			cout <<"��ѡ���ְ����λ�� " << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//��������ְ�������浽������
			newSpace[this->m_EmpNum + i] = worker;

		}

		//�ͷ�ԭ�еĿռ�
		delete[]this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//�������ݵ��ļ���
		this->save();

		//�������ݲ�Ϊ�յı�־
		this->m_FileIsEmpty = false;
		
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
	}
	else
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�  ���� д�ļ�

	//��ÿ��������д���ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//չʾԱ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//�����ɾ��ְ��
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//ְ�����ڣ�����Ҫɾ����indexλ���ϵ�����
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//���������м�¼����Ա����
			this->m_EmpNum--;
			//����ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����Ա������ж�ְ���Ƿ���ڣ�������ڷ���ְ���������е�λ�ã������ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}

//�޸�ְ��
void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "������ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��

			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "�ŵ�ְ������������ְ���ţ�" << endl;
			cin >> newid;

			cout << "������������" << endl;
			cin >> newname;

			cout << "�������µĸ�λ" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//�������ݵ�����
			this->m_EmpArray[ret] = worker;
			//�������ݵ�����
			this->save();
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}


//����ְ�� 
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//����ְ����Ų���
			int id = 0;
			cout << "���������Ա���ı�ţ�" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			//����ְ����������
			string name;
			cout << "���������ְ����������" << endl;
			cin >> name;
			//�����ж��Ƿ���ҳɹ��ı�־  Ĭ��Ϊfalse
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_ID << "�ŵ�ְ����Ϣ���£�" << endl;
					//��ʾ��Ϣ
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���!" << endl;
			}

		}
		else
		{
			cout << "������󣡣���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//���ձ������
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1������ְ������������" << endl;
		cout << "2������ְ���Ž�������" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
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

			//�ж�һ��ʼ�϶��� ���ֵ������Сֵ �Ƿ��������� ���ֵ������Сֵ ��ȣ�������򽻻�
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = this->m_EmpArray[i];
				this->m_EmpArray[i] = temp;
			}
		}
	}
	this->save();
	cout << "����ɹ������Ϊ��" << endl;
	this->Show_Emp();
}

//�������
void WorkerManager::Clean_File()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "ȷ���Ƿ���գ�" << endl;
		cout << "1��ȷ��" << endl;
		cout << "2������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//��ģʽ  ios::trunc ������� ɾ���ļ������´���
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();

			if (this->m_EmpArray != NULL)
			{
				//ɾ��������ÿ��ְ������
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i] != NULL)
					{
						delete this->m_EmpArray[i];
					}
				}
				//ɾ����������ָ��
				delete[] this->m_EmpArray;

				this->m_EmpNum = 0;
				this->m_EmpArray = NULL;
				this->m_FileIsEmpty = true;
			}
			cout << "����ɹ���" << endl;
		}
	}
	system("pause");
	system("cls");

}

//��������
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