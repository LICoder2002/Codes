#include <algorithm>
#include <functional>
#include<string>
#include<vector>
#include <iostream>
using namespace std;

//
//int main()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//
//	// 默认按照小于比较，排出来结果是升序
//	std::sort(array, array + sizeof(array) / sizeof(array[0]));
//
//	// 如果需要降序，需要改变元素的比较规则
//	std::sort(array, array + sizeof(array) / sizeof(array[0]), std::greater<int>());
//	return 0;
//}
//
////如果待排序元素为自定义类型，需要用户定义排序时的比较规则：

//struct Goods
//{
//	string _name;  // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{}
//};
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,
//	3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//}
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate > g2._evaluate; });
//}


//int main()
//{
//	// 最简单的lambda表达式, 该lambda表达式没有任何意义
//	[] {};
//
//	// 省略参数列表和返回值类型，返回值类型由编译器推导为int
//	int a = 3, b = 4;
//	[=] {return a + 3; };
//
//
//	// 省略了返回值类型，无返回值类型
//	auto fun1 = [&](int c) {b = a + c; };
//	fun1(10);
//		cout << a << " " << b << endl;
//
//	// 各部分都很完善的lambda函数
//	auto fun2 = [=, &b](int c)->int {return b += a + c; };
//	cout << fun2(10) << endl;
//
//	// 复制捕捉x
//	int x = 10;
//	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
//	cout << add_x(10) << endl;
//	return 0;
//}

//void (*PF)(); //函数指针
//int main()
//{
//	auto f1 = [] {cout << "hello world" << endl; };
//	auto f2 = [] {cout << "hello world" << endl; };
//
//	// 此处先不解释原因，等lambda表达式底层实现原理看完后，便会知晓其缘由
//    //f1 = f2;  // 编译失败--->提示找不到operator=()
//
//
//	// 允许使用一个lambda表达式拷贝构造一个新的副本
//	auto f3(f2);
//	f3();
//
//
//	// 可以将lambda表达式赋值给相同类型的函数指针
//	PF = f2;
//	PF();
//
//	return 0;
//}

//class Rate
//{
//public:
//	Rate(double rate)
//		:_rate(rate)
//	{}
//
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//
//private:
//	double _rate;
//};
//int main()
//{
//	// 函数对象
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//
//	// lamber
//	auto r2 = [=](double monty, int year)->double {return monty * rate * year;};
//	r2(10000, 2);
//	return 0;
//}

//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//
//int main()
//{
//	// 函数名
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//	return 0;
//}

//// 使用方法如下：
//#include <functional>
//int f(int a, int b)
//{
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	// 函数名(函数指针)
//	std::function<int(int, int)> func1 = f;
//	cout << func1(1, 2) << endl;
//
//	// 函数对象
//	std::function<int(int, int)> func2 = Functor();
//	cout << func2(1, 2) << endl;
//
//	// lamber表达式
//	std::function<int(int, int)> func3 = [](const int a, const int b)
//	{return a + b; };
//	cout << func3(1, 2) << endl;
//
//	// 类的成员函数
//	std::function<int(int, int)> func4 = &Plus::plusi;
//	//静态成员函数可以不加&符号
//	std::function<int(int, int)> func4 = Plus::plusi;
//	cout << func4(1, 2) << endl;
//
//	std::function<double(Plus, double, double)> func5 = &Plus::plusd;
//	cout << func5(Plus(), 1.1, 2.2) << endl;
//	return 0;
//}
//
//#include <functional>
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	// 函数名
//	std::function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//	
//	// 函数对象
//	std::function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//	
//	// lamber表达式
//	std::function<double(double)> func3 = [](double d)->double { return d /4; };
//	cout << useF(func3, 11.11) << endl;
//
//	return 0;
//}

//// 使用举例
//#include <functional>
//int Plus(int a, int b)
//{
//	return a + b;
//}
//class Sub
//{
//public:
//	int sub(int a, int b)
//	{
//		return a - b;
//	}
//};
//int main()
//{
//	//表示绑定函数plus 参数分别由调用 func1 的第一，二个参数指定
//	std::function<int(int, int)> func1 = std::bind(Plus, placeholders::_1, placeholders::_2);
//	//auto func1 = std::bind(Plus, placeholders::_1, placeholders::_2);
//	//func2的类型为 function<void(int, int, int)> 与func1类型一样
//
//	//表示绑定函数 plus 的第一，二为： 1， 2
//	auto func2 = std::bind(Plus, 1, 2);
//	cout << func1(1, 2) << endl;
//	cout << func2() << endl;
//
//	Sub s;
//	// 绑定成员函数
//	std::function<int(int, int)> func3 = std::bind(&Sub::sub, s, placeholders::_1, placeholders::_2);
//	// 参数调换顺序
//
//	std::function<int(int, int)> func4 = std::bind(&Sub::sub, s, placeholders::_2, placeholders::_1);
//	cout << func3(1, 2) << endl; // -1
//	cout << func4(1, 2) << endl; // 1
//	return 0;
//}


//
//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//
//	return a / b;
//}
//
//void func()
//{
//	int* p1 = new int[10]; // 这里可能会抛异常，此时抛异常内存会分配失败，程序结束后不会造成内存泄漏。
//	int* p2 = new int[10]; // 这里可能会抛异常，此时抛异常会导致p2以及后面的内存分配失败，退出程序后，
//	                       //由于p1已经成功申请内存，但是C++没有内存回收机制，因此会造成内存泄漏。
//	int* p3 = new int[10]; // 这里可能会抛异常
//
//	try
//	{
//		div();
//	}
//	catch (...)
//	{
//		delete[] p1;
//		delete[] p2;
//		delete[] p3;
//
//		throw;
//	}
//
//	delete[] p1;
//	delete[] p2;
//	delete[] p3;
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//		// ...
//	}
//
//	return 0;
//}
//template<class T>
//class SmartPtr {
//public:
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//void Func()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//	cout << div() << endl;
//}
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

template <class T>
class SmartPtr
{
public:
	// RAII思想
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		//delete[] _ptr;
		delete _ptr;
		_ptr = nullptr;
	}

	// 像指针一样
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T* Get()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
struct Date
{
	int _year;
	int _month;
	int _day;

	Date(int year = 1, int month = 1, int day = 1)
	{

	}
};

int main()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 10;
	cout << *sp1 << endl;

	SmartPtr<Date> sparray(new Date);
	// 需要注意的是这里应该是sparray.operator->()->_year = 2018;
	// 本来应该是sparray->->_year这里语法上为了可读性，省略了一个->
	sparray->_year = 2018;
	sparray->_month = 1;
	sparray->_day = 1;
}

