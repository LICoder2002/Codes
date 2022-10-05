#include<iostream>
using namespace std;

void test()
{
	int i = 1;
	if (i <= 0)
		printf("****\n");
	else
		printf("%%%%\n");
}


template<class T>
class BN
{
	long n;
public:
	BN(T i = 10)
		:n(i)
	{}

	BN operator+(BN b)
	{
		return BN(n + b.n);
	}
};

class cla {
	static int n;

public:
	cla()
	{
		n++;
	}

	~cla()
	{
		n--;
	}

	static int get()
	{
		return n;
	}
};

int main()
{
	//BN<long> b1, b2;

	//b1 + 3;

	//3 + b1;


	//test();

	//int arr[10] = { 1, 2 ,3 ,4 ,5, 6 };
	//for (auto e : arr)
	//{
	//	cout << e << endl;
	//}


	cla* p = new cla;

	delete p;

	cout << cla::get() << endl;

	return 0;
}