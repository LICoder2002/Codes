#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//检查是否扩容
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
			printf("增容成功\n");
		}
		else
		{
			printf("check_capacity::%s\n", strerror(errno));
		}
	}
}

//加载信息到通讯录
void LoadContact(Contact* pc)
{
	//从文件中加载数据
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		printf("InitContact::open for reading : %s\n", strerror(errno));
		return;
	}

	//读取文件
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

//初始化
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

//销毁通讯录
void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->_data);
	pc->_data = NULL;
	pc->_size = pc->_capacity = 0;
}

//添加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	check_capacity(pc);

	printf("请输入姓名：");
	scanf("%s", pc->_data[pc->_size]._name);

	printf("请输入年龄：");
	scanf("%d", &pc->_data[pc->_size]._age);

	printf("请输入性别：");
	scanf("%s", pc->_data[pc->_size]._sex);

	printf("请输入电话：");
	scanf("%s", pc->_data[pc->_size]._tele);

	printf("请输入地址：");
	scanf("%s", pc->_data[pc->_size]._addr);

	pc->_size++;
	printf("添加联系人成功\n");
}

//显示联系人信息
void ShowContact(const Contact* pc)
{
	assert(pc);
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
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
	return -1;//没找到
}

//按照姓名删除联系人
void DeleteContact(Contact* pc) 
{
	char name[NAME_MAX] = { 0 };
	if (pc->_size == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	printf("请输入要删除联系人的姓名：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("该联系人不存在\n");
		return;
	}
	else
	{
		for (int i = pos; i < pc->_size + 1; ++i)
		{
			pc->_data[i] = pc->_data[i + 1];
		}
		pc->_size--;
		printf("删除联系人成功\n");
	}
}

//保存信息到文件
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

