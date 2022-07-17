#pragma once //��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"

#include<fstream>
#define FILENAME "empFile.txt"

//������
//�������ݣ�
//1�����û���ͨ�Ĳ˵�����
//2����ְ����ɾ�Ĳ�Ĳ���
//3�����ļ��Ķ�д����

class WorkerManager
{
public:

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmpty;

	//���캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//���Ա��
	void ADD_Emp();

	//�����ļ�
	void save();

	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//չʾԱ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//����Ա������ж�ְ���Ƿ���ڣ�������ڷ���ְ���������е�λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void mod_Emp();

	//����ְ�� 
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//�������
	void Clean_File();

	//��������
	~WorkerManager();

};
