#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include<algorithm>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::endl;
using std::exception;

#include<assert.h>



class string
{
	friend ostream& operator<<(ostream& _cout, const string& s);

	friend istream& operator>>(istream& _cin, string& s);

public:
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	////错误实现 导致const对象也可以修改
	//iterator begin()const
	//{
	//	return _str;
	//}

	//iterator end()const
	//{
	//	return _str + _size;
	//}

	const_iterator begin()const
	{
		return _str;
	}

	const_iterator end()const
	{
		return _str + _size;
	}



	string(const char* str = "")
		:_size(strlen(str))
		, _capacity(_size)
	{
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}

	////传统写法
	//string(const string& s)
	//	:_size(strlen(s._str))
	//	,_capacity(_size)
	//{
	//	_str = new char[strlen(s._str) + 1];
	//	strcpy(_str, s._str);
	//}

	void swap(string&s )
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std:: swap(_capacity, s._capacity);
	}

	//现代写法
	string(const string& s)
		:_str(nullptr)
		, _size(0)
		,_capacity(0)
	{
		string tmp(s._str);
		swap(tmp);
	}

	////传统写法
	//string& operator=(const string& s)
	//{
	//	if (this != &s)
	//	{
	//		char* tmp = new char[s._capacity + 1];
	//		strcpy(tmp, _str);
	//		delete[] _str;
	//		_str = tmp;
	//		_size = s._size;
	//		_capacity = s._capacity;
	//		//if (_str != NULL)
	//		//{
	//		//	
	//		//	char* tmp = new char[strlen(s._str) + 1];
	//		//	strcpy(tmp, s._str);

	//		//	delete[] _str;
	//		//	_str = tmp;
	//		//	_size = s._size;
	//		//	_capacity = s._capacity;
	//		//}
	//	}
	//	return *this;
	//}

	////现代写法 1、
	//string& operator=(const string& s)
	//{
	//	if (this != &s)
	//	{
	//		string tmp(s._str);
	//		swap(tmp);
	//	}
	//	return *this;
	//}


	//// 2、
	string& operator=(string s)
	{

		swap(s);
		return *this;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos)const
	{
		assert(pos < _size);
		return _str[pos];
	}

	~string()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	const char* c_str() const
	{
		return _str;
	}

	size_t size() const 
	{
		return _size;
	}

	size_t capacity()const
	{
		return _capacity;
	}

	void push_back(const char ch)
	{
		//if (_size == _capacity)
		//{
		//	//if(_capacity==0?)
		//	reserve(_capacity == 0 ? 4 : 2 * _capacity);
		//}
		//_str[_size] = ch;
		//++_size;
		//_str[_size] = '\0';
		insert(_size, ch);

	}
	string& operator+=(const char ch)
	{
		push_back(ch);
		return *this;
	}

	string& operator+=(const char* str)
	{
		append(str);
		return *this;
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

	void resize(size_t n, const char ch = '\0')
	{
		if (n < _size)
		{
			_size = n;
			_str[_size] = '\0';
		}
		else
		{
			if (n > _capacity)
			{
				reserve(n);
			}

			for (size_t i = _size; i < n; ++i)
			{
				_str[i] = ch;
			}
			_size = n;
			_str[_size] = '\0';
		}

	}

	void append(const char* str)
	{
		//size_t len = _size + strlen(str);
		//if (len > _capacity)
		//{
		//	reserve(len);
		//}

		//strcpy(_str + _size, str);
		//_size = len;

		insert(_size, str);
	}

	string& insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}

		////错误代码
		//size_t end = _size;
		//while (end >= pos)
		//{
		//	_str[end + 1] = _str[end];
		//	--end;
		//}

		//int end = _size;
		//while (end >= (int)pos)
		//{
		//	_str[end + 1] = _str[end];
		//	--end;
		//}

		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}

		_str[pos] = ch;

		return *this;
	}

	string& insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (len == 0)
		{
			return *this;
		}
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		size_t end = _size + len;
		

		while (end > pos+len-1)
		{
			_str[end] = _str[end-len];
			end--;
		}
		//for (int i = 0; i < len; i++, pos++)
		//{
		//	_str[str + pos] = str[i];
		//}
		strncpy(_str + pos, str, len);
		_size = _size + len;

		return *this;
	}

	string& erase(size_t pos = 0, size_t len = npos)
	{
		assert(pos < _size);
		if (len == npos || pos + len >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			size_t begin = pos + len;
			while (begin <= _size)
			{
				_str[begin - len] = _str[begin];
				++begin;
			}
			_size -= len;

		}
		return *this;

	}

	// 返回c在string中第一次出现的位置
	size_t find(char ch, size_t pos = 0) const
	{
		for (; pos < _size; ++pos)
		{
			if (_str[pos] == ch)
			{
				return pos;
			}
		}
		return npos;
	}

	// 返回子串s在string中第一次出现的位置
	size_t find(const char* str, size_t pos = 0) const
	{
		const char* p = strstr(_str + pos, str);
		if (p == nullptr)
		{
			return npos;
		}
		else
		{
			return p - str;
		}
	}

	void clear()
	{
		_str[0] = '\0';
		_size = 0;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;

	//const static size_t npos = -1;
	const static size_t npos;
};

const size_t string::npos = -1;

bool operator<(const string& s1, const string& s2)
{
	return strcmp(s1.c_str(), s2.c_str()) < 0;
}

bool operator==(const string& s1, const string& s2)
{
	return strcmp(s1.c_str(), s2.c_str()) == 0;
}

bool operator<=(const string& s1, const string& s2)
{
	return (s1 < s2)||(s1==s2);
}

bool operator>(const string& s1, const string& s2)
{
	return !(s1 <= s2);
}
bool operator>=(const string& s1, const string& s2)
{
	return !(s1 < s2);
}

bool operator!=(const string& s1, const string& s2)
{
	return !(s1 == s2);
}

ostream& operator<<(ostream& out, const string& s)
{
	//out << s.c_str();//不打印'\0'

	for (auto ch : s)
	{
		out << ch;
	}

	return out;
}

istream& operator>>(istream& in, string& s)
{
	//char ch;
	//ch = in.get();
	//while (ch != ' ' && ch != '\n')
	//{
	//	s += ch;
	//	ch = in.get();

	//}
	////s += ch;

	//return in;

	s.clear();

	char ch;
	ch = in.get();
	char buff[128] = { '\0' };
	size_t i = 0;
	while (ch != ' ' && ch != '\n')
	{
		buff[i++] = ch;
		if (i == 127)
		{
			s += buff;
			memset(buff, '\0', 128);
			i = 0;
		}

		ch = in.get();

	}
	s += buff;

	return in;
}