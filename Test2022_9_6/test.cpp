#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void test_set()
{
	unordered_set<int> s;

	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(2);
	s.insert(4);


	auto it = s.begin();

	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}



int cnt = 0;

int fib(int n)
{
	cnt++;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else
		return fib(n - 1) + fib(n - 2);
}

//int func(int x)
//{
//	int count = 0;
//	while (x) {
//		count++;
//		x = x & (x - 1);
//	}
//	return count;
//}

void func(const char** m) {
	++m;
	cout << *m << endl;
}

int main()
{

	//static const char* a[] = { "morning", "af", "eve" };

	//const char** p = a;

	//func(p);



	//fib(8);
	//cout << cnt << endl;

	//int m = 0123, n = 123;
	//printf("%o %o", m, n);

	//cout << func(9999) << endl;

	////test_set();

	//char* ptr;
	//char myp[] = "abcdefg";

	//ptr = myp;

	//ptr += 5;
	//cout << ptr << endl;

	//int ta[2][3] = { {0, 1, 2}, {3, 4}, {5} };

	//long long a = 1, b = 2, c = 3;
	//printf("%d %d %d\n", a, b, c);
	

	//char dog[] = "wang\0miao";
	//cout << sizeof(dog) << " " << strlen(dog) << endl;

	//cout << ('1' < '2') << endl;

	int x = 1;
	do {
		printf("%2d\n", x++);
	} while (x--);

	return 0;
}

