#include"Date.hpp"

//�ж�����
bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ��ȡĳ��ĳ�µ�����
int GetMonthDay(int year, int month)
{
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = days[month];
	if (month == 2 && isLeapYear(year))
	{
		return day + 1;
	}
	else
	{
		return day;
	}
}

std::ostream& operator<<(std::ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}
std::istream& operator>>(std::istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	if (d._year >= 1 && d._month <= 12 && d._month >= 1 && d._day >= 1 && d._day <= GetMonthDay(d._year, d._month))
	{
		return in;
	}
	cout << "�������ڴ���" << endl;
	exit(-1);
}