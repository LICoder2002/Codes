#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

//判断闰年
bool isLeapYear(int year);
// 获取某年某月的天数
int GetMonthDay(int year, int month);

class Date
{
	friend ostream& operator << (ostream& out, const Date& date);
	friend istream& operator >> (istream& cin, Date& date);

public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

	operator bool()
	{
		//判断日期是否合法
		if (_year >= 1 && _month >= 1 && _month <= 12 && _day >= 1 && _day <= GetMonthDay(_year, _month))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator << (ostream& out, const Date& date)
{
	out << date._year << " " << date._month << " " << date._day;
	return out;
}

istream& operator >> (istream& in, Date& date)
{
	in >> date._year >> date._month >> date._day;
	return in;
}

// 获取某年某月的天数
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
//判断闰年
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



//void test()
//{
//		Date d1 = -1;
//		Date d2 = { 2022, 10, 11 };
//	
//		bool ret1 = d1;
//		bool ret2 = d2;
//	
//		cout << ret1 << endl;
//		cout << ret2 << endl;
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}

struct ServerInfo
{
	char _address[32];//地址
	int _port;//端口号
	Date _date;//日期
};

class ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{}

	//以二进制写文件
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ios_base::out | ios_base::binary);
		ofs.write((const char*)&info, sizeof(info));

	}

	/*
	C++文件流的优势就是可以对内置类型和自定义类型，都使用一样的方式，去流插入和流提取数据当然这里自定义类型Date需要重载 >> 和 << :
	istream& operator >> (istream& in, Date& date)
	ostream& operator << (ostream& out, const Date& date)
   */
   
	//以二进制读文件
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ios_base::in | ios_base::binary);
		ifs.read((char*)&info, sizeof(info));
	}

	//以文本文件写文件
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs << info._address << " " << info._port << " " << info._date;
	}

	//以文本文件读文件
	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address >> info._port >> info._date;
	}

private:
	string _filename; //文件名
};

//int main()
//{
//	ServerInfo wInfo{ "192.0.0.1", 80, { 2022, 4, 10 } };
//
//	//二进制读写
//	ConfigManager cf_bin("Test.bin");
//	cf_bin.WriteBin(wInfo);
//
//	ServerInfo rInfo1;
//	cf_bin.ReadBin(rInfo1);
//
//
//	//文本文件读写
//	ConfigManager cf_txt("Test.txt");
//	cf_txt.WriteText(wInfo);
//
//	ServerInfo rInfo2;
//	cf_txt.ReadText(rInfo2);
//
//
//	return 0;
//
//}

struct ChatInfo
{
	string _name; // 名字
	int _id;  // id
	Date _date;  // 时间
	string _msg;  // 聊天信息
};

int main()
{
	// 结构信息序列化为字符串
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };

	ostringstream oss;
	oss << winfo._name << " " << winfo._id << " " << winfo._date << " " << winfo._msg;

	string str = oss.str();
	cout << str << endl;

	// 我们通过网络这个字符串发送给对象，实际开发中，信息相对更复杂，一般会选用Json、xml等方式进行更好的支持字符串解析成结构信息。


	ChatInfo rInfo;
	istringstream iss(str);
	iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;

	cout << "-------------------------------------------------------" << endl;

	cout << "姓名：" << rInfo._name << "(" << rInfo._id << ") ";
	cout << rInfo._date << endl;
	cout << rInfo._name << ":>" << rInfo._msg << endl;

	cout << "-------------------------------------------------------" << endl;
	return 0;
}