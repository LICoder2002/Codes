#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

//�ж�����
bool isLeapYear(int year);
// ��ȡĳ��ĳ�µ�����
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
		//�ж������Ƿ�Ϸ�
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
	char _address[32];//��ַ
	int _port;//�˿ں�
	Date _date;//����
};

class ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{}

	//�Զ�����д�ļ�
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ios_base::out | ios_base::binary);
		ofs.write((const char*)&info, sizeof(info));

	}

	/*
	C++�ļ��������ƾ��ǿ��Զ��������ͺ��Զ������ͣ���ʹ��һ���ķ�ʽ��ȥ�����������ȡ���ݵ�Ȼ�����Զ�������Date��Ҫ���� >> �� << :
	istream& operator >> (istream& in, Date& date)
	ostream& operator << (ostream& out, const Date& date)
   */
   
	//�Զ����ƶ��ļ�
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ios_base::in | ios_base::binary);
		ifs.read((char*)&info, sizeof(info));
	}

	//���ı��ļ�д�ļ�
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs << info._address << " " << info._port << " " << info._date;
	}

	//���ı��ļ����ļ�
	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address >> info._port >> info._date;
	}

private:
	string _filename; //�ļ���
};

//int main()
//{
//	ServerInfo wInfo{ "192.0.0.1", 80, { 2022, 4, 10 } };
//
//	//�����ƶ�д
//	ConfigManager cf_bin("Test.bin");
//	cf_bin.WriteBin(wInfo);
//
//	ServerInfo rInfo1;
//	cf_bin.ReadBin(rInfo1);
//
//
//	//�ı��ļ���д
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
	string _name; // ����
	int _id;  // id
	Date _date;  // ʱ��
	string _msg;  // ������Ϣ
};

int main()
{
	// �ṹ��Ϣ���л�Ϊ�ַ���
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��" };

	ostringstream oss;
	oss << winfo._name << " " << winfo._id << " " << winfo._date << " " << winfo._msg;

	string str = oss.str();
	cout << str << endl;

	// ����ͨ����������ַ������͸�����ʵ�ʿ����У���Ϣ��Ը����ӣ�һ���ѡ��Json��xml�ȷ�ʽ���и��õ�֧���ַ��������ɽṹ��Ϣ��


	ChatInfo rInfo;
	istringstream iss(str);
	iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;

	cout << "-------------------------------------------------------" << endl;

	cout << "������" << rInfo._name << "(" << rInfo._id << ") ";
	cout << rInfo._date << endl;
	cout << rInfo._name << ":>" << rInfo._msg << endl;

	cout << "-------------------------------------------------------" << endl;
	return 0;
}