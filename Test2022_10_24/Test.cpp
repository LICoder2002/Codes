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
//	// ����ʹ��static_cast�ᱨ��Ӧ��ʹ��reinterpret_cast
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
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main()
{
	A a; // ����ʹ��dynamic_castת����B��
	B b;
	fun(&a);
	fun(&b);
	return 0;
}