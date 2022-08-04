#pragma once

#include"RBTree.h"
#include <string>

namespace lhf
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::const_iterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};

	void test_map1()
	{
		map<string, int> m;
		m.insert(make_pair("111", 1));
		m.insert(make_pair("555", 5));
		m.insert(make_pair("333", 3));
		m.insert(make_pair("222", 2));

		map<string, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		for (auto& kv : m)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}

	void test_map2()
	{
		string arr[] = { "苹果", "苹果", "香蕉", "苹果", "苹果", "梨子", "苹果", "苹果", "香蕉", "梨子", "苹果" };

		map<string, int> countMap;
		for (auto& str : arr)
		{
			countMap[str]++;
		}

		for (const auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}

	void test_map3()
	{
		map<string, string> dict;
		dict["insert"];
		dict["insert"] = "";
		dict["left"] = "";
	}
}