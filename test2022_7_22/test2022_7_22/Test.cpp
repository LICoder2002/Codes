#include<iostream>
using namespace std;
//
//class A
//{
//public:
//  virtual void f()
//  {
//    cout << "A::f()" << endl;
//  }
//};
//
//class B : public A
//{
//    virtual void f()
//    {
//        cout << "B::f()" << endl;
//    }
//};
//
//int main()
//{
//    A* pa = (A*)new B;
//
//    pa->f();
//}

//class A
//{
//public:
//
//  A() 
//      :m_iVal(0) 
//  { 
//      test();
//  }
//
//  virtual void func() 
//  {
//      std::cout << m_iVal << " ";
//  }
//
//  void test() 
//  { 
//      func(); 
//  }
//
//public:
//  int m_iVal;
//};
//
//class B : public A
//{
//
//public:
//    B()
//    { 
//        test();
//    }
//    virtual void func()
//    {
//        ++m_iVal;
//        std::cout << m_iVal << " ";
//    }
//};
//
//int main(int argc, char* argv[])
//{
//
//   /* A* p = new B;
//    p->test();*/
//    B b;
//    A a;
//    return 0;
//}

//class A1
//{
//public:
//	virtual void f1(){}
//
//};
//class A2
//{
//public:
//	virtual void f2() {}
//
//};
//
//class B : public A1,A2
//{
//public:
//	virtual void f1(){}
//	virtual void f2() {}
//	virtual void f3(){}
//};
//
//
//int main()
//{
//	B b;
//	return 0;
//}

//class Animal
//{
//public:
//	virtual void sound()
//	{
//		cout << "叫声" << endl;
//	}
//};
//
//class Cat:public Animal
//{
//public:
//	virtual void sound()
//	{
//		cout << "喵喵喵..." << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//	virtual void sound()
//	{
//		cout << "汪汪汪..." << endl;
//	}
//};
//
//void func(Animal& animal)
//{
//	animal.sound();
//}
//
//int main()
//{
//	Animal animal;
//	func(animal);
//
//	Cat cat;
//	func(cat);
//
//	Dog dog;
//	func(dog);
//
//	return 0;
//}
//
//class Person {
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//class Student : public Person {
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}


//class Car {
//public:
//	virtual void Drive() {}
//};
//class Wuling :public Car {
//public:
//	virtual void Drive() override { cout << "五菱神车" << endl; }
//};
//
//int main()
//{
//	Car* car = new Wuling;
//	car->Drive();
//	return 0;
//}


//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};



//class Car {
//public:
//	virtual void Drive() final {}
//};
//class Wuling :public Car {
//public:
//	virtual void Drive() { cout << "五菱神车" << endl; }
//};
//
//int main()
//{
//	Car* car = new Wuling;
//	car->Drive();
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}
//
//int main()
//{
//	Car car;
//}
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//int main()
//{
//	Base b;
//}

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}

class Person 
{
public:
	virtual void BuyTicket() 
	{ 
		cout << "买票-全价" << endl;
	}
	int num = 10;
};
class Student : public Person {
public:
	int num = 20;
	virtual void BuyTicket() 
	{ 
		cout << "买票-半价" << endl; 
	}

	void func()
	{
		cout << "func" << endl;
	}
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	//Person Mike;
	//Func(Mike);
	//Student Johnson;
	//Func(Johnson);

	Person* p = new Student();
	p->BuyTicket();
	cout << p->num << endl;
	//p->func();

	return 0;
}