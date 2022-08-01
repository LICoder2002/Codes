#include <iostream>
#include <set>
#include <map>
#include <string>
#include<iostream>
using namespace std;

//#include "AVLTree.h"

void test_set1()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);


	// ���� + ȥ�� 
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 10;
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

void test_set2()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	set<int>::iterator pos = s.find(20);  // O(logN)
	if (pos != s.end())
	{
		cout << "set.find�ҵ���" << endl;
	}

	pos = find(s.begin(), s.end(), 2); // O(N)
	if (pos != s.end())
	{
		cout << "find�ҵ���" << endl;
	}
}


void test_set3()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	cout << s.erase(3) << endl;
	cout << s.erase(30) << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>::iterator pos = s.find(3);
	if (pos != s.end())
		s.erase(pos);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	/*int x;
	while (cin >> x)
	{
		set<int>::iterator pos = s.find(x);
		if (pos != s.end())
		{
			s.erase(pos);
			cout << "ɾ��" << x << "�ɹ�" << endl;
		}
		else
		{
			cout << x << "����set��" << endl;
		}

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;
	}*/

	if (s.count(5))
	{
		cout << "5��" << endl;
	}

	if (s.find(5) != s.end())
	{
		cout << "5��" << endl;
	}
}

void test_set4()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(7);
	s.insert(9);

	// ����>= val��λ�õ�����  3����3λ��  6 ����7λ��
	/*set<int>::iterator lowIt = s.lower_bound(3); ����
	lowIt = s.lower_bound(6); ������*/
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// Ҫ��ɾ��>=x������ֵ
	int x;
	cin >> x;
	set<int>::iterator lowIt = s.lower_bound(x);
	s.erase(lowIt, s.end());

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set5()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(7);
	s.insert(9);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// ����>xλ�õĵ�����  -�� ���Ƿ��� 7λ�õĵ�����
	//set<int>::iterator upIt = s.upper_bound(5);  // ����
	//upIt = s.upper_bound(6); // ������

	// ɾ��x <=  <= y������ ɾ�� [x,y]
	int x, y;
	cin >> x >> y;
	auto leftIt = s.lower_bound(x);  // [
	auto rightIt = s.upper_bound(y); // )
	s.erase(leftIt, rightIt);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set6()
{
	multiset<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(3);
	s.insert(3);
	s.insert(3);
	s.insert(3);

	// ���� 
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 10;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << s.count(1) << endl;
	cout << s.erase(1) << endl;
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// ���x�Ļ���find���������һ��x
	auto pos = s.find(3);
	while (pos != s.end())
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl;
}

void test_map1()
{
	map<string, string> dict;

	// pair���캯��
	dict.insert(pair<string, string>("sort", "����"));
	pair<string, string> kv("insert", "����");
	dict.insert(kv);

	// make_pair
	auto ret1 = dict.insert(make_pair("left", "���"));
	auto ret2 = dict.insert(make_pair("left", "ʣ��"));

	dict["operator"] = "����"; // ����+�޸�
	dict["left"] = "��ߡ�ʣ��"; // �޸�
	dict["erase"];  // ����
	cout << dict["left"] << endl; // ����


	// C++11 �ٽ�
	//dict.insert({ "right", "�ұ�" });

	// ����
	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		//cout << *it << " "; // it->operator*()
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

//mapped_type& operator[] (const key_type& k)
//{
//	pair<iterator,bool> ret = insert(make_pair(k, mapped_type()));
//
//	//return (*(ret.first)).second;
//	return ret.first->second;
//}

void test_map2()
{
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

	// 17:08����
	/*map<string, int> countMap;
	for (auto& str : arr)
	{
		map<string, int>::iterator it = countMap.find(str);
		if (it != countMap.end())
		{
			it->second++;
		}
		else
		{
			countMap.insert(make_pair(str, 1));
		}
	}*/

	//map<string, int> countMap;
	//for (auto& str : arr)
	//{
	//	//pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(str, 1));
	//	auto ret = countMap.insert(make_pair(str, 1));
	//	if (ret.second == false)
	//	{
	//		ret.first->second++;
	//	}
	//}

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
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("left", "ʣ��"));
	dict.insert(make_pair("left", "���"));
}

//���
//["qkjzgws", "nftk", "qrkgmliewc", "qengse", "nsfspyox", "htpvnmozay", "zskaqzwo", "fqizrrnmif", "glarko", "hdemkfr", "qggx", "pwqvwmlgri", "zlfiwwb", "ijy"]
//
//Ԥ��
//["nftk", "qkjzgws", "qrkgmliewc", "nsfspyox", "qengse", "htpvnmozay", "fqizrrnmif", "glarko", "hdemkfr", "pwqvwmlgri", "qggx", "zskaqzwo", "ijy", "zlfiwwb"]
//
//qkjzgws:10
//nftk : 10
//qrkgmliewc : 9
//qengse : 8
//nsfspyox : 8

int main()
{
	test_set6();
	test_map3();
	//TestAVLTree();

	return 0;
}