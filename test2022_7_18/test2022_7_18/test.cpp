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
//
//// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
//// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//};
//
//int main()
//{
//	Test();
//	return 0;
//}
//
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//}
//
//int main()
//{
//	TestPerson();
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a._name = "peter";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}






class A
{
public:
	int _a;
};
 //class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}