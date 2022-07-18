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
//	string _name; // 姓名
//	string _sex;  // 性别
//	int _age;     // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//void Test()
//{
//	Student s;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person p = s;
//	Person* ptrp = &s;
//	Person& rp = s;
//
//	//2.基类对象不能赋值给派生类对象
//	//s = p; //error
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	ptrp = &s;
//	Student * ps1 = (Student*)ptrp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//
//	ptrp = &p;
//	Student* ps2 = (Student*)ptrp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
////class Person
////{
////protected:
////	string _name = "小李子"; // 姓名
////	int _num = 111;  // 身份证号
////};
////class Student : public Person
////{
////public:
////	void Print()
////	{
////		cout << " 姓名:" << _name << endl;
////		cout << " 身份证号:" << Person::_num << endl;
////		cout << " 学号:" << _num << endl;
////	}
////protected:
////	int _num = 999; // 学号
////};
////void Test()
////{
////	Student s1;
////	s1.Print();
////};

// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
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