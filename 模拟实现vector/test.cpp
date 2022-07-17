#include"vector.h"
using namespace lhf;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (size_t i = 0; i < vv.size(); ++i)
		{
			// 杨辉三角，每行个数依次递增
			vv[i].resize(i + 1, 0);

			// 第一个和最后一个初始化成1
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					// 中间位置等于上一行j-1 和 j个相加
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return vv;
	}
};


void test1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.reserve(10);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
}

void test2()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.pop_back();
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.pop_back();
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

}

void test3()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	v.resize(10);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;


	v.resize(5);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
}

void test4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.insert(v.begin(), 0);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	auto it = v.begin();
	while (it!=v.end())
	{
		if (*it % 2 == 1)
		{
			it = v.insert(it, 99);
			++it;
		}
		++it;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void test5()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(1);

	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 1)
		{
			it = v.erase(it);
			
		}
		else
		{
			++it;
		}
		//++it;
	}


	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}


void test6()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2(v1.begin(), v1.end());
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout  << endl;

	std::string s("hello");
	vector<char> v3(s.begin(), s.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v4(v1);
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	v1 = v2;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}






void test()
{
	vector<vector<int>> ret = Solution().generate(5);

	for (size_t i = 0; i < ret.size(); ++i)
	{
		for (size_t j = 0; j < ret[i].size(); ++j)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void test_reverse_iterator()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	
	auto rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}




int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test();
	test_reverse_iterator();

	return 0;
}

