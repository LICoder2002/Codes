#include"employee.h"


//���캯��
Employee::Employee(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dId;
}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		 << "\tְ��������" << this->m_Name
		 << "\t��λ��" << this->getDeptName()
		 << "\t��λְ����ɾ�������ְ��" << endl;
}

//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
}