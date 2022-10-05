#include<iostream>
using namespace std;
//class cla {
////	static int n;
////
////public:
////	cla()
////	{
////		n++;
////	}
////
////	~cla()
////	{
////		n--;
////	}
////
////	static int get()
////	{
////		return n;
////	}
////};
//// 
////int cla::n = 0;
////
////
////class cls
////{
////public:
////
////	cls() {
////		count++;
////	}
////	/*cls(int i = 0)
////	{
////		cout << 1;
////
////	}
////
////	cls(const cls& x)
////	{
////		cout << 2;
////	}*/
////
////	cls& operator=(const cls& x)
////	{
////		cout << 3;
////		return *this;
////	}
////
////	~cls()
////	{
////		cout << 4
////			;
////	}
////
////	void print()const
////	{
////
////	}
////
////public:
////
////	static int count;
////};
////
////
////int cls::count = 0;
////
////
////
////
////
////int main()
////{
////	//BN<long> b1, b2;
////
////	//b1 + 3;
////
////	//3 + b1;
////
////
////	//test();
////
////	//int arr[10] = { 1, 2 ,3 ,4 ,5, 6 };
////	//for (auto e : arr)
////	//{
////	//	cout << e << endl;
////	//}
////
////
////	//cla* p = new cla;
////
////	//delete p;
////
////	//cout << cla::get() << endl;
////
////	//cls obj1(1), obj2(2), obj3(obj1);
////
////	//cls c1[5], *b[6];
////
////	//cout << cls::count << endl;
////
////	return 0;
////}
//
//
//#include<string>
//
//class A;
//long fun(A s);
//
//class A
//{
//	friend long fun(A s)
//	{
//		if (s.x < 3)
//		{
//			return 1;
//		}
//		return s.x + fun(s.x - 1);
//	}
//public:
//	A(long a)
//	{
//		x = a--;
//	}
//private:
//	long x;
//};
//
////int main()
////{
////	int sum = 0;
////	for (int i = 0; i < 5; ++i)
////	{
////		sum += fun(A(i));
////	}
////
////	cout << sum << endl;
////
////	return 0;
////}
//
//class B
//{
//	char ch;
//	int a;
//
//
//public:
//	static int count;
//	B()
//	{
//		//count++;
//	}
//
//	void foo()
//	{
//		delete this;
//	}
//
//	~B()
//	{
//		//count++;
//		//cout << count << endl;
//		//delete this;
//
//	}
//};
//
//int B::count = 0;
//
//template<class T>
//T fun(T x, T y)
//{
//	return x * x + y * y;
//}
////
////int main(void)
////{
////	//const int a = 10;
////
////	//int* p = (int*) & a;
////
////	//*p = 20;
////
////	//cout << &a <<endl << p << endl;
////
////	//cout << a << *p << endl;
////
////	//cout << sizeof(B) << endl;
////
////	//B* b = new B();
////	//b->foo();
////
////	//B(b)[3];
////
////	//cout << B::count << endl;
////
////	//fun(1.0, 1);
////	//fun(2.0, 2.0);
////
////	B b1, * b2;
////	B* b3 = new B;
////
////	B& b4 = b1;
////
////	//delete b3;
////	cout << B::count << endl;
////
////	return 0;
////}
//
//
//#include<iostream>
//using namespace std;
//
//bool isPrime(const int& n)
//{
//	int i = 2;
//	for (i = 2; i < n; ++i)
//	{
//		if (n % i == 0)
//		{
//			break;
//		}
//	}
//
//	return i == n;
//}
//
//class C
//{
//public:
//	C()
//	{
//		cout << " C()" << endl;
//
//	}
//
//	C(int i)
//		:data(i)
//	{
//		cout << "con... C()" << data << endl;
//
//	}
//
//	
//	~C()
//	{
//		cout << "~C()" << endl;
//	}
//private:
//	int data;
//};
//
//C play(C c)
//{
//	return c;
//}

class A {
public:
	 A(int j)
		 :i(j)
	 {}
	 void func1()
	 {
		 i *= 10;
		 func2();
	 }

	 int get()
	 {
		 return i;
	 }
protected:
	virtual void func2()
	{
		i++;
	}
	int i;
};

class B : public A
{
public:
	B(int j)
		:A(j)
	{}
	void func1()
	{
		i *= 100;
		func2();
	}

protected:
	virtual void func2()
	{
		i+=2;
	}
};

int main()
{

	//const char* p = "avhfyugugh";
	//cout << sizeof(p) << endl;

	//C t = play(5);
	////int n = 0;
	//cin >> n;

	
	//cout << isPrime(n) << endl;


	//A* a = new A;
	//B* b = new B;

	//a = b;

	//a.test(1.1);

	A* p = new B(1);
	p->func1();

	cout << p->get() << endl;

	return 0;
}