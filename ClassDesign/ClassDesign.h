#pragma once
#include<iostream>
#include<string>
using namespace std;

//1.请设计一个类，不能被拷贝
/*拷贝只会放生在两个场景中：拷贝构造函数以及赋值运算符重载，因此想要让一个类禁止拷贝，只需让该类不能调用拷贝构造函数以及赋值运算符重载即可。*/
class CopyBan1
{
public:
	CopyBan1()
	{}
	//C++ 98 将拷贝构造函数与赋值运算符重载只声明不定义，并且将其访问权限设置为私有即可。
private:
	CopyBan1(const CopyBan1&);
	CopyBan1& operator=(const CopyBan1&);

};

class CopyBan2
{

	/*C++11
		C++11扩展delete的用法，delete除了释放new申请的资源外，如果在默认成员函数后跟上
		= delete，表示让编译器删除掉该默认成员函数。*/
public:

	CopyBan2(){}

	CopyBan2(const CopyBan2&) = delete;
	CopyBan2& operator=(const CopyBan2&) = delete;

};

//2. 请设计一个类，只能在堆上创建对象

//法一


//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObj()
//	{
//		return new HeapOnly;
//	}
//
//private:
//	//构造函数私有
//	HeapOnly(){}
//	HeapOnly(const HeapOnly&);
//	HeapOnly& operator=(const HeapOnly&) = delete;
//};

//法二

class HeapOnly
{
public:
	static void DelObj(HeapOnly* ptr)
	{
		delete ptr;
	}

	/*void DelObj()
	{
		delete this;
	}*/

private:
	 //析构函数私有
	~HeapOnly()
	{}
};


//3. 请设计一个类，只能在栈上创建对象

class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();
	}

	//StackOnly(const StackOnly&) = delete;

	//StackOnly& operator=(const StackOnly&) = delete;
	
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;

private:
	StackOnly(){}
};

//请设计一个类，不能被继承

// C++98中构造函数私有化，派生类中调不到基类的构造函数。则无法继承
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};

//C++11方法
//final关键字，final修饰类，表示该类不能被继承。
class A final
{
	//...
};

//5. 请设计一个类，只能创建一个对象(单例模式)

//饿汉模式

// 优点：简单
// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return _spInst;
	}

	void Print();
private:
	Singleton()
	{}

	Singleton(const Singleton&) = delete;


	//static Singleton _sInst; // 声明
	static Singleton* _spInst; // 声明

	int _a = 0;
};

//Singleton Singleton::_sInst; // 定义
Singleton* Singleton::_spInst = new Singleton; // 定义

void Singleton::Print()
{
	cout << _a << endl;
}

// InfoMgr -- 单例
class InfoMgr
{
public:
	static InfoMgr* GetInstance()
	{
		return _spInst;
	}

	void SetAddress(const string& s)
	{
		_address = s;
	}

	string& GetAddress()
	{
		return _address;
	}

private:
	InfoMgr()
	{}

	InfoMgr(const InfoMgr&) = delete;

	string _address;
	int _secretKey;

	static InfoMgr* _spInst; // 声明
};

InfoMgr* InfoMgr::_spInst = new InfoMgr; // 定义



//懒汉模式
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂

class InfoMg 
{
public:
	static InfoMg* getInstance()
	{
		if (_pInfoMa == nullptr)
		{
			_pInfoMa = new InfoMg;
		}
		return _pInfoMa;
	}

	void SetAddress(const string& s)
	{
		_address = s;
	}

	string& GetAddress()
	{
		return _address;
	}

	// 实现一个内嵌垃圾回收类    
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (_pInfoMa)
			{
				delete _pInfoMa;
			}
		}
	};

	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:



	InfoMg(){}

	~InfoMg(){}


	string _address;
	int _secretKey;
	
	static InfoMg* _pInfoMa; //声明

};

InfoMg* InfoMg::_pInfoMa = nullptr;
InfoMg::CGarbo Garbo;
