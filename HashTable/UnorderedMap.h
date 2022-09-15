#pragma once
#include"HashTable.h"

namespace lhf
{
	template<class K, class V, class HashFunc = DefaultHash<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:

		typedef typename Hash::HashTable < K, V, MapKeyOfT, HashFunc>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}


		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv.first);
		}

		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		Hash::HashTable<K, V, MapKeyOfT, HashFunc> _ht;
	};
}