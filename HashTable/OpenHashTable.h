#pragma once
#include <string>
#include<vector>
using namespace std;

//template<class K>
//struct DefaultHash
//{
//	size_t operator()(const K& key)
//	{
//		return (size_t)key;
//	}
//};
//
//template<>
//struct DefaultHash<string>
//{
//	size_t operator()(const string& key)
//	{
//		//BKDR
//		size_t hash = 0;
//		for (auto e : key)
//		{
//			hash = hash * 131 + e;
//		}
//		return hash;
//	}
//};

namespace OpenHash
{
	//定义节点
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};

	template<class K, class V, class HashFunc = DefaultHash<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;

	public:

		//HashTable(){}

		//HashTable(HashTable<K, V, DefaultHash<K>> ht)
		//{
		//	this->_tables.swap(ht._tables);
		//	_n = ht._n;
		//}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
			_n = 0;
		}
		
		bool Insert(const pair<K, V>& kv)
		{
			//kv已经存在
			if (Find(kv.first))
			{
				return false;
			}

			HashFunc hf{};

			//负载因子 == 1， 扩容
			if (_tables.size() == _n)
			{
				//法一， 存在缺陷
				/*size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize, nullptr);

				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						newHT.Insert(cur->_kv);
						cur = cur->_next;
					}
				}

				newHT._tables.swap(_tables);*/

				//法二，不销毁原节点
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				newTables.resize(newSize, nullptr);

				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];

					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = hf(cur->_kv.first);
						hashi %= newSize;
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}
				newTables.swap(_tables);
			}

			size_t hashi = hf(kv.first);
			hashi %= _tables.size();

			//头插到对于的桶
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			//表为空
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			HashFunc hf{};
			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			if (_tables.size() == 0)
			{
				return false;
			}

			HashFunc hf{};
			size_t hashi = hf(key);
			hashi %= _tables.size();

			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						cur->_next = _tables[hashi];
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;
					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}


	private:
		//定义指针数组
		vector<Node*> _tables;
		size_t _n = 0;

	};


	void TestHT1()
	{
		int a[] = { 20, 5, 8, 99999, 10, 30, 50 };
		//HashTable<int, int, DefaultHash<int>> ht;
		HashTable<int, int> ht;

		if (ht.Find(10))
		{
			cout << "找到了10" << endl;
		}

		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Erase(20);
		ht.Erase(10);
		ht.Erase(30);
		ht.Erase(50);


		// 测试扩容
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(5, 5));
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(25, 15));
		ht.Insert(make_pair(35, 15));
		ht.Insert(make_pair(45, 15));
	}

	void TestHT2()
	{
		int a[] = { 20, 5, 8, 99999, 10, 30, 50 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		// 需要自己实现拷贝构造，完成链表桶深拷贝
		HashTable<int, int> copy(ht);
	}

	void TestHT3()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };

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
	}
}
