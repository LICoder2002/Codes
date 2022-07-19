#include<iostream>
using namespace std;

//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	virtual void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	//p->test();
//	p->func();
//	return 0;
//}
//class A {
//public: 
//	void test(float a)
//	{ 
//		cout << a;
//	} 
//};
//class B :public A 
//{ 
//public:
//	void test(int b) 
//	{ 
//		cout << b; 
//	} 
//}; 
//int main() 
//{
//	A* a = new A;
//	B* b = new B;
//	a = b; 
//	a->test(1.1); 
//	return 0;
//}


class A
{
public:
	void f1(){cout << "A::f1()" << endl;}
	virtual void f2() { cout << "A::f2()" << endl; }
	virtual void f3() { cout << "A::f3()" << endl; }
};

class B : public A
{
public:
	virtual void f1() { cout << "B::f1()" << endl; }
	virtual void f2() { cout << "B::f2()" << endl; }
	void f3() { cout << "B::f3()" << endl; }
};
//C.如果基类指针引用子类对象后，通过基类对象调用f2时，调用的是子类的f2

int main()
{
	B b;
	A& a =  b;
	a.f2();
	return 0;
}