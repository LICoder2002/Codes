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

		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv.first);
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
		Hash::HashTable<K, V, MapKeyOfT, HashFunc> _ht;
	};
}