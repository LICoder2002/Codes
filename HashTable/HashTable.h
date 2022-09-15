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




namespace Hash
{
	//定义节点
	//T既可以接收key，也能接收pair类型
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	//声明HashTable 
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;



	//定义迭代器
	template<class K, class T, class KeyOfT, class HashFunc>
	class _Iterator
	{
		typedef HashNode<T> Node;
		typedef _Iterator<K, T, KeyOfT, HashFunc> Self;


	public:
		Node* _node;
		HashTable<K, T, KeyOfT, HashFunc>* _pht;

		_Iterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot{};
				HashFunc hf{};

				size_t hashi = hf(kot(_node->_data));
				hashi%=_pht->_tables.size();
				++hashi;
				//寻找下一个不为空的桶
				for (; hashi < _pht->_tables.size(); ++hashi)
				{
					if (_pht->_tables[hashi])
					{
						_node = _pht->_tables[hashi];
						break;
					}
				}

				//没有找到
				if (hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
				
			}

			return *this;
		}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s)const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s)const
		{
			return _node == s._node;
		}
	};

	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable
	{
		template<class K, class T, class KeyOfT, class HashFunc>
		friend class _Iterator;

		typedef HashNode<T> Node;

	public:

		typedef _Iterator<K, T, KeyOfT, HashFunc> iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return iterator(cur, this);
				}
			}

			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

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

		size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			static const size_t primeList[PRIMECOUNT] =
			{
				53ul, 97ul, 193ul, 389ul, 769ul,
				1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
				49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
				1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
				50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
				1610612741ul, 3221225473ul, 4294967291ul
			};

			// 获取比prime大那一个素数
			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > prime)
					return primeList[i];
			}

			return primeList[i];
		}

		pair<iterator, bool> Insert(const T& data)
		{
			HashFunc hf{};
			KeyOfT kot{};

			iterator pos = Find(kot(data));

			//kv已经存在
			if (pos != end())
			{
				return make_pair(pos, false);
			}


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
				//size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;

				size_t newSize = GetNextPrime(_tables.size());
				if (newSize != _tables.size())
				{
					vector<Node*> newTables;
					newTables.resize(newSize, nullptr);

					for (size_t i = 0; i < _tables.size(); ++i)
					{
						Node* cur = _tables[i];

						while (cur)
						{
							Node* next = cur->_next;

							size_t hashi = hf(kot(cur->_data)) % newSize;
							cur->_next = newTables[hashi];
							newTables[hashi] = cur;

							cur = next;
						}
						_tables[i] = nullptr;
					}
					newTables.swap(_tables);
				}
			}

			size_t hashi = hf(kot(data));
			hashi %= _tables.size();

			//头插到对于的桶
			Node* newnode = new Node(kot(data));
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return make_pair(iterator(newnode, this), true);
		}

		iterator Find(const K& key)
		{
			//表为空
			if (_tables.size() == 0)
			{
				return iterator(nullptr, this);
			}

			HashFunc hf{};
			KeyOfT kot{};
			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}
				cur = cur->_next;
			}
				return iterator(nullptr, this);
		}

		bool Erase(const K& key)
		{
			if (_tables.size() == 0)
			{
				return false;
			}

			KeyOfT kot{};
			HashFunc hf{};
			size_t hashi = hf(key);
			hashi %= _tables.size();

			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
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
}