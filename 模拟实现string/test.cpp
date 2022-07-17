#include"string.hpp"


void test1()
{
	string s1("hello world");

	for (int i = 0; i < s1.size(); i++)
	{
		s1[i] += 1;
		cout << s1[i] << " ";
	}
	cout << endl;

	string s2(s1);
	string s3("11111111111");

	s1 = s3;

	cout << s2.c_str() << endl;
	cout << s1.c_str() << endl;

}

void test2()
{
	string s("hello world");
	s.push_back('1');
	s.push_back('1');
	s.push_back('1');
	s.push_back('1');
	s += '2';
	s += "123";
	cout << s.c_str() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

}

void test3()
{
	string s("hello world");
	s.resize(20, 'a');
	cout << s.c_str() << endl;
	s.resize(14, 'a');
	cout << s.c_str() << endl;
	s.resize(5);
	cout << s.c_str() << endl;


}

void test4()
{
	string s1("a");
	string s2(s1);
	string s3 = "b";
	cout << (s1 > s2) << endl;
	cout << (s1 < s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s3 > s2) << endl;
	cout << (s3 < s2) << endl;
}

void test5()
{
	string s("hello world");

	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		//*it += 1;
		cout << *it << " ";
	}
	cout << endl;

	for (auto ch : s)
	{
		ch += 1;
	}

	//Ìæ»»³Éµü´úÆ÷
	for (auto ch : s)
	{
		cout << ch << " ";
	}
	cout << endl;

	for (auto &ch : s)
	{
		ch += 1;
	}

	for (auto ch : s)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void func(const string s)
{
	for (auto &ch : s)
	{
		//ch += 1;
		cout << ch << " ";
	}
	cout << endl;
}

void test6()
{
	string s("hello");

	s.insert(0, "xxx");
	s.insert(0, "");

	cout << s.c_str() << endl;

	s.erase(0, 3);
	cout << s.c_str() << endl;

	s.erase(0,8);
	cout << s.c_str() << endl;

	//for (auto ch : s)
	//{
	//	cout << ch << " ";
	//}
	//cout << "#" << endl;

	//s += '\0';
	//for (auto ch : s)
	//{
	//	cout << ch << " ";
	//}
	//cout << "#" << endl;
}

void test7()
{
	string s("hello world");
	s += '\0';
	cout << s << endl;
	s += '\0';
	cout << s << endl;
	s += '#';
	cout << s << endl;
	s += '\0';
	cout << s << endl;

	//string s1;
	//cin >> s1;
	//cout << s1 << endl;

	string s2("hello world");
	cin >> s2;
	cout << s2 << endl;
}
void test8()
{
	string s1("hello world");
	string s2(s1);
	cout << s2 << endl;

	string s3("1111111111111111");
	s1 = s3;
	cout << s1 << endl;
}

int main()
{
	try
	{
		test1();
		test2();
		test3();
		test4();
		test5();
		const string s("hello world");
		func(s);

		test6();
		test8();
		test7();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

