#include"list.h"
using namespace lhf;
#include<list>
#include<iostream>
using std::cout;
using std::endl;

void print_list(const list<int>& lt)
{
	list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		//*it = 10;
		cout << *it << " ";
		it++;
	}
	cout << endl;
}


void test1()
{
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	print_list(lt);
	
	auto it = lt.begin();

	while (it != lt.end())
	{
		*it = 20;
		cout << *it << " ";
		//++it;
		it++;
	}
	cout << endl;



}




struct AA
{
	AA(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{}

	int _a1;
	int _a2;
};

void test2()
{
	list<AA> lt;
	lt.push_back(AA(1, 1));
	lt.push_back(AA(2, 2));
	lt.push_back(AA(3, 3));
	lt.push_back(AA(4, 4));

	// 迭代器模拟的是指针行为
	// int* it  *it
	// AA*  it  *it  it->
	list<AA>::iterator it = lt.begin();
	while (it != lt.end())
	{
		//cout << (*it)._a1 << "-"<< (*it)._a2 <<" ";
		cout << it->_a1 << "-" << it->_a2 << " ";
		++it;
	}
	cout << endl;
}



void test3()
{
	list<int>lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_front(10);
	lt.push_front(20);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	lt.pop_front();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.clear();


	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_front(10);
	lt.push_front(20);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test4()
{
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int> lt1;
	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	list<int> lt2(lt1);

	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> lt3(lt2.begin(), lt2.end());

	for (auto e : lt3)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1 = lt;
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_reverse_iterator()
{
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test_reverse_iterator();

	return 0;

}