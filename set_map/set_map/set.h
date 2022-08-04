#pragma once
#include"RBTree.h"

namespace lhf
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin()const
		{
			return _t.Begin();
		}

		iterator end()const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			auto ret = _t.Insert(key);
			return pair<iterator, bool>(iterator(ret.first._node), ret.second);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}


	private:
		RBTree<K, K, SetKeyOfT> _t;
	};

	void test_set1()
	{
		set<int> s;
		s.insert(8);
		s.insert(6);
		s.insert(11);
		s.insert(5);
		s.insert(6);
		s.insert(7);
		s.insert(10);
		s.insert(13);
		s.insert(12);
		s.insert(15);

		set<int>::iterator it = s.begin();
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
	}
}