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
	//����ڵ�
	//T�ȿ��Խ���key��Ҳ�ܽ���pair����
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

	//����HashTable 
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;



	//���������
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
				//Ѱ����һ����Ϊ�յ�Ͱ
				for (; hashi < _pht->_tables.size(); ++hashi)
				{
					if (_pht->_tables[hashi])
					{
						_node = _pht->_tables[hashi];
						break;
					}
				}

				//û���ҵ�
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

		bool Insert(const T& data)
		{
			HashFunc hf{};
			KeyOfT kot{};

			//kv�Ѿ�����
			if (Find(kot(data)))
			{
				return false;
			}


			//�������� == 1�� ����
			if (_tables.size() == _n)
			{
				//��һ�� ����ȱ��
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

				//������������ԭ�ڵ�
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
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

			size_t hashi = hf(kot(data));
			hashi %= _tables.size();

			//ͷ�嵽���ڵ�Ͱ
			Node* newnode = new Node(kot(data));
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			//��Ϊ��
			if (_tables.size() == 0)
			{
				return nullptr;
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
		//����ָ������
		vector<Node*> _tables;
		size_t _n = 0;

	};
}