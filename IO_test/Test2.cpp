#include<sstream>
#include<iostream>
using namespace std;


//int main()
//{
//	int a = 12345678;
//	string sa;
//
//	// ��һ�����α���ת��Ϊ�ַ������洢��string�������
//	stringstream s;
//	s << a;
//	s >> sa;
//	
//	cout << "sa = " << sa << endl;
//	cout << s.str() << endl; // str()����������stringsteam�й����string����
//
//	 /*
//	 ע����ת��ʱ������ʹ��clear���ϴ�ת��״̬��յ���
//	 stringstreams��ת����βʱ(�����һ��ת����),�Ὣ���ڲ�״̬����Ϊbadbit��
//	 �����һ��ת���Ǳ������clear()��״̬����Ϊgoodbit�ſ���ת��������clear()���Ὣstringstreams�ײ��ַ�����յ���
//	 ���ʹ��s.str("")����stringstream�ײ����string�������ó�""��������ת��ʱ���Ὣ���ȫ���ۻ��ڵײ�string�����С�
//     */
//
//	s.str(""); // ��stringstream�ײ����string�������ó�""
//	s.clear(); // ���s, ����ջ�ת��ʧ��
//
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	cout << "sa = " << sa << endl;
//
//	string sValue;
//	sValue = s.str(); // str()����������stringsteam�й����string����
//	cout << sValue << endl;
//	return 0;
//}

//
//int main()
//{
//	stringstream sstream;
//
//	// ������ַ������� sstream ��
//	sstream << "first" << " " << "string,";
//	sstream << " second string";
//
//	cout << "strResult is: " << sstream.str() << endl;
//
//	// ��� sstream
//	sstream.str("");
//	sstream.clear();
//	sstream << "third string";
//	cout << "After clear, strResult is: " << sstream.str() << endl;
//	return 0;
//}
