#pragma once
#include <string>
#include<vector>
using namespace std;
//using std::string;
//using std::vector;
//using std::pair;

template<class K>
struct DefaultHash
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct DefaultHash<string>
{
	size_t operator()(const string& key)
	{
		//BKDR
		size_t hash = 0;
		for (auto e : key)
		{
			hash = hash * 131 + e;
		}
		return hash;
	}
};

namespace CloseHash
{
	enum State
	{
		EMPTY, //��
		EXITS, //����
		DELETE //ɾ��
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY; //Ĭ��Ϊ��
	};



	template<class K, class V, class HashFunc = DefaultHash<K>>
	class HashTable
	{
		typedef HashData<K, V> Data;
	public:

		bool Insert(const pair<K, V> kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			//�������Ӵ���0.7������
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);

				//�����ɱ�����ӳ��
				for (auto& e : _tables)
				{
					if (e._state == EXITS)
					{
						newHT.Insert(e._kv);
					}
				}

				newHT._tables.swap(_tables);
			}

			HashFunc hf{};
			size_t starti = hf(kv.first);
			starti %= _tables.size();

			size_t hashi = starti;
			size_t i = 1;
			//����̽��
			while (_tables[hashi]._state == EXITS)
			{
				hashi = starti + i;
				++i;
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXITS;
			++_n;

			return true;

		}

		Data* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			HashFunc hf{};
			size_t starti = hf(key);
			starti %= _tables.size();

			size_t hashi = starti;
			size_t i = 1;
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state != DELETE && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				hashi = starti + i;
				++i;
				hashi %= _tables.size();
			}
				
			return nullptr;

		}

		bool Erase(const K& key)
		{
			Data* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<Data> _tables;
		size_t _n = 0; //�洢�ؼ��ָ���

	};

	void TestHT1()
	{
		int a[] = { 20, 5, 8, 99999, 10, 30, 50 };

		HashTable<int, int> ht;

		if (ht.Find(10))
		{
			cout << "�ҵ���10" << endl;
		}

		for (auto e : a)
		{
			ht.Insert(std::make_pair(e, e));
		}
		// ��������
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(5, 5));
		ht.Insert(make_pair(15, 15));



		if (ht.Find(10))
		{
			cout << "�ҵ���10" << endl;
		}
		ht.Erase(10);

		if (ht.Find(10))
		{
			cout << "�ҵ���10" << endl;
		}
	}

	void TestHT2()
	{
		string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

		/*string s1("ƻ��");
		string s2("��ƻ");
		string s3("����");
		string s4("Ƽ��");

		string s5("abcd");
		string s6("bcad");
		string s7("aadd");

		StringHash hf;
		cout << hf(s1) << endl;
		cout << hf(s2) << endl;
		cout << hf(s3) << endl;
		cout << hf(s4) << endl << endl;
		cout << hf(s5) << endl;
		cout << hf(s6) << endl;
		cout << hf(s7) << endl;*/


		//HashTable<string, int, StringHash> countHT;
		HashTable<string, int> countHT;



		for (auto& str : arr)
		{
			auto ret = countHT.Find(str);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				countHT.Insert(make_pair(str, 1));
			}
		}

		// ��Ӧ������һ���º������º�������ʵ�ְ�key����ת����ӳ�������
		//HashTable<Date, int, DateHash> countHT;
		//HashTable<Student, int, StudentHash> countHT;


		HashTable<string, int> copy(countHT);
	}

}
