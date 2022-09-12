#pragma once
#include"HashTable.h"
#include <iostream>

namespace lhf
{
	template<class K, class HashFunc = DefaultHash<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:

		typedef typename Hash::HashTable < K, K, SetKeyOfT, HashFunc>::iterator iterator;


		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

	private:
		Hash::HashTable<K, K, SetKeyOfT, HashFunc> _ht;
	};

	struct Date
	{
		Date(int year = 1, int month = 1, int day = 1)
			:_year(year)
			, _month(month)
			, _day(day)
		{}

		bool operator==(const Date& d) const
		{
			return _year == d._year
				&& _month == d._month
				&& _day == d._day;
		}

		int _year;
		int _month;
		int _day;
	};

	struct DateHash
	{
		size_t operator()(const Date& d)
		{
			//return d._year + d._month + d._day;
			size_t hash = 0;
			hash += d._year;
			hash *= 131;
			hash += d._month;
			hash *= 1313;
			hash += d._day;

			//cout << hash << endl;

			return hash;
		}
	};

	void test_set()
	{
		unordered_set<int> s;
		//set<int> s;
		s.insert(2);
		s.insert(3);
		s.insert(1);
		s.insert(2);
		s.insert(5);
		s.insert(12);

		unordered_set<int>::iterator it = s.begin();
		//auto it = s.begin();
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

		unordered_set<Date, DateHash> sd;
		sd.insert(Date(2022, 3, 4));
		sd.insert(Date(2022, 4, 3));
	}
}