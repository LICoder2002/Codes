#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���ࣺ��ͨԱ���������ϰ�

//������ְ������һ���ࣨwoker���У����ö�̬����ͬ��ְ������

//ְ��������
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;
	
	int m_ID;//ְ�����
	string m_Name;//ְ������
	int m_DeptID;//���ű��

};