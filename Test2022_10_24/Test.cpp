#include<iostream>
using namespace std;

//int main()
//{
//	double d = 10.24;
//	int a = static_cast<int>(d);
//
//	cout << a << endl;
//	return 0;
//}

//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//	// 这里使用static_cast会报错，应该使用reinterpret_cast
//	//int *p = static_cast<int*>(a);
//	int* p = reinterpret_cast<int*>(a);
//	cout << p << endl;
//	return 0;
//}

//int main()
//{
//	const int a = 2;
//	int* p = const_cast<int*>(&a);
//	*p = 3;
//	cout << a << endl;
//	return 0;
//}

class A
{
public:
	virtual void f() {}
};
class B : public A
{};
void fun(A* pa)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main()
{
	A a; // 不能使用dynamic_cast转换成B类
	B b;
	fun(&a);
	fun(&b);
	return 0;
}