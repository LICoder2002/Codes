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

class A1
{
public:
	virtual void f1(){}

};
class A2
{
public:
	virtual void f2() {}

};

class B : public A1,A2
{
public:
	virtual void f1(){}
	virtual void f2() {}
	virtual void f3(){}
};


int main()
{
	B b;
	return 0;
}