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
	char _name[NAME_MAX]; //����
	int _age;			  //����
	char _sex[SEX_MAX];   //�Ա�
	char _addr[ADDR_MAX]; //��ַ
	char _tele[TELE_MAX]; //�绰
}PeoInfo;//��ϵ����Ϣ

//ͨѶ¼�ṹ��
typedef struct Contact
{
	//PeoInfo _data[MAX];
	PeoInfo* _data;//�������
	int _size;     //ͨѶ¼����Ч���ݸ���
	int _capacity; //ͨѶ¼����
}Contact;

//��ʼ��
void InitContact(Contact* pc);

//����ͨѶ¼
void DestoryContact(Contact* pc);

//�����ϵ��
void AddContact(Contact* pc);

//��ʾ��ϵ����Ϣ
void ShowContact(const Contact* pc);

//��������ɾ����ϵ��
void DeleteContact(Contact* pc);

//������Ϣ���ļ�
void SaveContact(Contact* pc);

//������Ϣ��ͨѶ¼
void LoadContact(Contact* pc);