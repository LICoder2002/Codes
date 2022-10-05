#pragma warning(disable : 4996)
#include<iostream>
using namespace std;

// decltype��һЩʹ��ʹ�ó���
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret;
	cout << typeid(ret).name() << endl;
}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret��������double
//	decltype(&x) p;  // p��������int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//
//	int z = 0;
//	decltype(z) tmp;
//
//	cout << typeid(tmp).name() << endl;
//	F(1.1, 1.1);
//	return 0;
//}


#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cassert>
#include <list>
//int main()
//{
//    std::string str = "Hello";
//    std::vector<std::string> v;
//    //���ó���Ŀ������캯�����½��ַ����飬��������
//    v.push_back(str);
//    std::cout << "After copy, str is \"" << str << "\"\n";
//    //�����ƶ����캯�����Ϳ�str���Ϳպ���ò�Ҫʹ��str
//    v.push_back(std::move(str));
//    std::cout << "After move, str is \"" << str << "\"\n";
//    std::cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1] << "\"\n";
//}
//


namespace lhf
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}
		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ�����" << endl;
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};
}
//
//void func1(lhf::string s)
//{}
//void func2(const lhf::string& s)
//{}
//int main()
//{
//	lhf::string s1("hello world");
//
//	// func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿��������Ч�ʵ�ʹ�ó����ͼ�ֵ
//	func1(s1);
//	func2(s1);
//	// string operator+=(char ch) ��ֵ���ش������
//	// string& operator+=(char ch) ����ֵ����û�п��������Ч��
//
//	s1 += '!';
//	return 0;
//}

namespace lhf
{
	lhf::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}
		lhf::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;
			str += ('0' + x);
		}
		if (flag == false)
		{
			str += '-';
		}
		std::reverse(str.begin(), str.end());
		return str;
	}
}
//int main()
//{
//	// ��lhf::string to_string(int value)�����п��Կ���������ֻ��ʹ�ô�ֵ���أ���ֵ���ػᵼ������1�ο�������(�����һЩ��һ��ı��������������ο�������)��
//	lhf::string ret1 = lhf::to_string(1234);
//	lhf::string ret2 = lhf::to_string(-1234);
//	return 0;
//}

//int main()
//{
//	lhf::string ret1;
//	ret1 = lhf::to_string(1234);
//	return 0;
//}

//void push_back(value_type&& val);
//int main()
//{
//	std::list<lhf::string> lt;
//	lhf::string s1("1111");
//
//	// ������õ��ǿ�������
//	lt.push_back(s1);
//
//	// ������ö����ƶ�����
//	lt.push_back("2222");
//	lt.push_back(std::move(s1));
//	return 0;
//}
//
//void Fun(int& x) { cout << "��ֵ����" << endl; }
//void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
//
//void Fun(int&& x) { cout << "��ֵ����" << endl; }
//
//void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }
//
///*
//ģ���е�&& ��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
//ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
//�����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
//����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����������ѧϰ������ת��
//*/
//
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(t);
//}
//int main()
//{
//	PerfectForward(10); // ��ֵ
//	int a;
//	PerfectForward(a);  // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//	const int b = 8;
//	PerfectForward(b);  // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//	return 0;
//}
//
//void Fun(int& x) { cout << "��ֵ����" << endl; }
//void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
//void Fun(int&& x) { cout << "��ֵ����" << endl; }
//void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }
//// std::forward<T>(t)�ڴ��εĹ����б�����t��ԭ���������ԡ�
//
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(std::forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10); // ��ֵ
//	int a;
//	PerfectForward(a); // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//	const int b = 8;
//	PerfectForward(b);  // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//	return 0;
//}

//struct A
//{
//	void foo()
//	{
//		printf("foo");
//	}
//
//	virtual void bar()
//	{
//		printf("bar");
//	}
//	A()
//	{
//		bar();
//	}
//};
//
//struct B : A
//{
//	void foo()
//	{
//		printf("b_foo");
//	}
//
//	virtual void bar()
//	{
//		printf("b_bar");
//	}
//};
//int main()
//{
//	A* p = new B;
//	p->foo();
//	p->bar();
//}
//
//class A
//{
//public:
//	A()
//	{
//		printf("A ");
//	}
//	virtual ~A()
//	{
//		printf("deA ");
//	}
//};
//
//class B
//{
//public:
//	B()
//	{
//		printf("B ");
//	}
//	~B()
//	{
//		printf("deB ");
//	}
//};
//
//
//
//class C: public A, public B
//{
//public:
//	C()
//	{
//		printf("C ");
//	}
//	~C()
//	{
//		printf("deC ");
//	}
//};
//
//int main()
//{
//	A* a = new C;
//
//	delete a;
//	return 0;
//}

class Test
{
public:
	int a;
	int b;

	virtual void fun(){}

	Test(int t1 = 0, int t2 = 0)
	{
		a = t1;
		b = t2;
	}

	int getA()
	{
		return a;
	}

	int getB()
	{
		return b;
	}
};

//class A
//{
//public:
//	void print()
//	{
//		cout << "A::print()" << endl;
//	}
//};
//
//class B : private A
//{
//public:
//	void print()
//	{
//		cout << "B::print()" << endl;
//	}
//};
//
//
//class C : public B
//{
//public:
//	void print()
//	{
//		A::print();
//	}
//};

//
//int main()
//{
//	Test test(5, 10);
//
//	int* p = (int*)&test;
//
//	*(p + 0) = 100;
//	*(p + 1) = 200;
//	cout << test.getA() << test.getB() << endl;
//}

class A
{
public:
	A() { p(); }

	virtual void p()
	{
		cout << "A" << endl;
	}

	virtual ~A()
	{
		p();
	}
};

class B : public A
{
public:
	B()
	{
		p();
	}

	void p()
	{
		cout << "B" << endl;
	}

	~B()
	{
		p();
	}
};

int main()
{
	A* a = new B();

	delete a;
}