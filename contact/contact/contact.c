#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//����Ƿ�����
void check_capacity(Contact* pc)
{
	assert(pc);
	if (pc->_size == pc->_capacity)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pc->_data, (pc->_capacity + 2) * sizeof(PeoInfo));
		if (tmp != NULL)
		{
			pc->_data = tmp;
			pc->_capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("check_capacity::%s\n", strerror(errno));
		}
	}
}

//������Ϣ��ͨѶ¼
void LoadContact(Contact* pc)
{
	//���ļ��м�������
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		printf("InitContact::open for reading : %s\n", strerror(errno));
		return;
	}

	//��ȡ�ļ�
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		check_capacity(pc);
		pc->_data[pc->_size] = tmp;
		pc->_size++;
	}

	fclose(pf);
	pf = NULL;
}

//��ʼ��
void InitContact(Contact* pc) 
{
	assert(pc);
	pc->_size = 0;
	PeoInfo* tmp = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (tmp != NULL)
	{
		pc->_data = tmp;
	}
	else
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	pc->_capacity = DEFAULT_SZ;

	LoadContact(pc);
}

//����ͨѶ¼
void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->_data);
	pc->_data = NULL;
	pc->_size = pc->_capacity = 0;
}

//�����ϵ��
void AddContact(Contact* pc)
{
	assert(pc);
	check_capacity(pc);

	printf("������������");
	scanf("%s", pc->_data[pc->_size]._name);

	printf("���������䣺");
	scanf("%d", &pc->_data[pc->_size]._age);

	printf("�������Ա�");
	scanf("%s", pc->_data[pc->_size]._sex);

	printf("������绰��");
	scanf("%s", pc->_data[pc->_size]._tele);

	printf("�������ַ��");
	scanf("%s", pc->_data[pc->_size]._addr);

	pc->_size++;
	printf("�����ϵ�˳ɹ�\n");
}

//��ʾ��ϵ����Ϣ
void ShowContact(const Contact* pc)
{
	assert(pc);
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < pc->_size; ++i)
	{
		printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n",
			pc->_data[i]._name, pc->_data[i]._age, 
			pc->_data[i]._sex, pc->_data[i]._tele, 
			pc->_data[i]._addr);
	}
}

int FindByName(const Contact* pc, char name[])
{
	for (int i = 0; i < pc->_size; ++i)
	{
		if (strcmp(pc->_data[i]._name, name) == 0)
			return i;
	}
	return -1;//û�ҵ�
}

//��������ɾ����ϵ��
void DeleteContact(Contact* pc) 
{
	char name[NAME_MAX] = { 0 };
	if (pc->_size == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����\n");
		return;
	}
	else
	{
		for (int i = pos; i < pc->_size + 1; ++i)
		{
			pc->_data[i] = pc->_data[i + 1];
		}
		pc->_size--;
		printf("ɾ����ϵ�˳ɹ�\n");
	}
}

//������Ϣ���ļ�
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}

	for (int i = 0; i < pc->_size; ++i)
	{
		fwrite(pc->_data + i, sizeof(PeoInfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

