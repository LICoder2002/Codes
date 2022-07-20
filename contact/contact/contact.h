#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>

#define MAX 1000

#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12

#define DEFAULT_SZ 3

typedef struct PeoInfo
{
	char _name[NAME_MAX]; //姓名
	int _age;			  //年龄
	char _sex[SEX_MAX];   //性别
	char _addr[ADDR_MAX]; //地址
	char _tele[TELE_MAX]; //电话
}PeoInfo;//联系人信息

//通讯录结构体
typedef struct Contact
{
	//PeoInfo _data[MAX];
	PeoInfo* _data;//存放数据
	int _size;     //通讯录中有效数据个数
	int _capacity; //通讯录容量
}Contact;

//初始化
void InitContact(Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);

//添加联系人
void AddContact(Contact* pc);

//显示联系人信息
void ShowContact(const Contact* pc);

//按照姓名删除联系人
void DeleteContact(Contact* pc);

//保存信息到文件
void SaveContact(Contact* pc);

//加载信息到通讯录
void LoadContact(Contact* pc);