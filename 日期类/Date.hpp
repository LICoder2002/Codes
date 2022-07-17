#include<iostream>
using std::cout;
using std::cin;
using std::endl;


bool isLeapYear(int year);
int GetMonthDay(int year, int month);


class Date
{
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	friend std::istream& operator>>(std::istream& in, Date& d);

public:
	//��ӡ
	void print()const
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}
	



	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1, int month = 1, int day = 1)
	{
		if (year >= 1 && month <= 12 && month >= 1 && day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "�������ڴ���" << endl;
		}
	}

	// �������캯��
    // d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��ֵ���������
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	
	//// ��������
	//~Date()
	//{
	//	_year = 0;
	//	_month = 0;
	//	_day = 0;
	//}

	// ����+=����
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}

		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}

		return *this;
	}

	// ����+����
	Date operator+(int day)const
	{
		Date ret(*this);
		ret += day;
		return ret;
	}

	// ����-����
	Date operator-(int day)const
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}

	// ����-=����
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += day;
		}

		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	// ǰ��++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}

	// ����--
	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}

	// ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >���������
	bool operator>(const Date& d)const
	{
		return !(*this <= d);
	}

	// ==���������
	bool operator==(const Date& d)const
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// >=���������
	bool operator >= (const Date& d)const
	{
		return !(*this < d);
	}

	// <���������
	bool operator < (const Date& d)const
	{
		if ((_year < d._year)
			|| (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// <=���������
	bool operator <= (const Date& d)const
	{
		return *this < d || *this == d;
	}

	// !=���������
	bool operator != (const Date& d)const
	{
		return !(*this == d);
	}

	// ����-���� ��������
	int operator-(const Date& d)const
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			flag = -1;
			min = *this;
			max = d;
		}

		int count = 0;
		while (min != max)
		{
			++count;
			++min;
		}

		return count * flag;
	}

private:

	int _year;  //��
	int _month; //��
	int _day;	//��

};
