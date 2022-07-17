#include"Date.hpp"

void test1()
{
	Date d1(2022, 6, 22);
	d1.print();
	Date d2(d1);
	d2.print();

	Date d3(2022, 6, 22);
	d3 = d2;
	d3.print();

}

void test2()
{
	Date d1(2022, 6, 22);
	Date d2(2022, 6, 23);
	Date d3(d2);
	d3.print();
	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d3 == d2) << endl;
	cout << (d3 >= d2) << endl;
	cout << (d3 >= d1) << endl;
	cout << (d3 <= d1) << endl;
	
}
void test3()
{
	Date d1(2022, 6, 22);
	Date d2 = d1 + 12;
	d2.print();
	Date d3 = d2 - 12;
	d3.print();
	d1 += 12;
	d1.print();
	d1 -= 12;
	d1.print();
}
void test4()
{
	Date d1(2022, 6, 22);
	Date d2 = d1++;
	d1.print();
	d2.print();
	cout << "------------------" << endl;
	d2 = d1--;
	d1.print();
	d2.print();
	cout << "------------------" << endl;
	d2 = ++d1;
	d1.print();
	d2.print();
	cout << "------------------" << endl;
	d2 = --d1;
	d1.print();
	d2.print();
}
void test5()
{
	Date d1, d2;
	cin >> d1 >> d2;
	//Date d1(2022, 6, 22);
	//Date d2(2023, 1, 1);
	//Date d3(2020, 1, 5);
	cout << (d2 - d1) << endl;
	//cout << (d3 - d1) << endl;
}

void test6()
{
	Date d;
	cin >> d;
	cout << d;
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	//test6();

	system("pause");
	return 0;
}