#include<iostream>
using namespace std;

//class A
//{
//public:
//	A()
//		:a(0)
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//	void f() { cout << "A::f()" << endl; }
//	int a;
//};
//
//
//class B : public A
//{
//public:
//	B()
//		:a(1)
//	{
//		cout << "B()" << endl;
//	}
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//	void f() { cout << "B::f()" << endl; }
//	int a;
//};
//
//int main()
//{
//	B b;
//	//b.f();
//	return 0;
//}

//class B{ public: int b; };
//
//class C1 : public B { public: int c1; };
//
//class C2 : public B { public: int c2; };
//
//class D : public C1, public C2 { public: int d; };
//int main()
//{
//	D d;
//	cout << sizeof(d) << endl;
//	return 0;
//}



//class Person
//{
//protected:
//	string _name; // ����
//	string _sex;  // �Ա�
//	int _age;     // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//void Test()
//{
//	Student s;
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person p = s;
//	Person* ptrp = &s;
//	Person& rp = s;
//
//	//2.��������ܸ�ֵ�����������
//	//s = p; //error
//
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	ptrp = &s;
//	Student * ps1 = (Student*)ptrp; // �������ת��ʱ���Եġ�
//	ps1->_No = 10;
//
//	ptrp = &p;
//	Student* ps2 = (Student*)ptrp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//	ps2->_No = 10;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

//// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
////class Person
////{
////protected:
////	string _name = "С����"; // ����
////	int _num = 111;  // ���֤��
////};
////class Student : public Person
////{
////public:
////	void Print()
////	{
////		cout << " ����:" << _name << endl;
////		cout << " ���֤��:" << Person::_num << endl;
////		cout << " ѧ��:" << _num << endl;
////	}
////protected:
////	int _num = 999; // ѧ��
////};
////void Test()
////{
////	Student s1;
////	s1.Print();
////};

// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		cout << "func(int i)->" << i << endl;
	}
};
void Test()
{
	B b;
	b.fun(10);
	b.A::fun();
};

int main()
{
	Test();
	return 0;
}