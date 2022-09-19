#pragma once
#include<string>
#include<bitset>
#include<vector>
#include <time.h>
using namespace std;


namespace lhf
{
	struct BKDRHash
	{
		size_t operator()(const string& s)
		{
			// BKDR
			size_t value = 0;
			for (auto ch : s)
			{
				value *= 31;
				value += ch;
			}
			return value;
		}
	};

	struct APHash
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (long i = 0; i < s.size(); i++)
			{
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};

	struct DJBHash
	{
		size_t operator()(const string& s)
		{
			size_t hash = 5381;
			for (auto ch : s)
			{
				hash += (hash << 5) + ch;
			}
			return hash;
		}
	};

	struct JSHash
	{
		size_t operator()(const string& s)
		{
			size_t hash = 1315423911;
			for (auto ch : s)
			{
				hash ^= ((hash << 5) + ch + (hash >> 2));
			}
			return hash;
		}
	};

	template<size_t M,
		class K = string,
		class HashFunc1 = BKDRHash,
		class HashFunc2 = APHash,
		class HashFunc3 = DJBHash,
		class HashFunc4 = JSHash>
	class BloomFilter
	{
	public:

		void Set(const K& key)
		{
			size_t hash1 = HashFunc1()(key) % M;
			size_t hash2 = HashFunc2()(key) % M;
			size_t hash3 = HashFunc3()(key) % M;
			size_t hash4 = HashFunc4()(key) % M;

			_bs.set(hash1);
			_bs.set(hash2);
			_bs.set(hash3);
			_bs.set(hash4);
		}

		bool Test(const K& key)
		{
			size_t hash1 = HashFunc1()(key) % M;
			if (_bs.test(hash1 == false))
			{
				return false;
			}

			size_t hash2 = HashFunc2()(key) % M;
			if (_bs.test(hash2 == false))
			{
				return false;
			}

			size_t hash3 = HashFunc3()(key) % M;
			if (_bs.test(hash3 == false))
			{
				return false;
			}

			size_t hash4 = HashFunc4()(key) % M;
			if (_bs.test(hash4 == false))
			{
				return false;
			}

			return true;
		}


	private:
		bitset<M> _bs;
	};

	void TestBloomFilter1()
	{
		// 休息到10：20继续

		// 插入10个值
		//BloomFilter<43, string, BKDRHash, APHash, DJBHash> bf;
		BloomFilter<43> bf;

		string a[] = { "苹果", "香蕉", "西瓜", "111111111", "eeeeeffff", "草莓", "休息", "继续", "查找", "set" };

		for (auto& e : a)
		{
			bf.Set(e);
		}

		for (auto& e : a)
		{
			cout << bf.Test(e) << endl;
		}
		cout << endl;

		cout << bf.Test("芒果") << endl;
		cout << bf.Test("string") << endl;
		cout << bf.Test("ffffeeeee") << endl;
		cout << bf.Test("31341231") << endl;
		cout << bf.Test("ddddd") << endl;
		cout << bf.Test("3333343") << endl;

	}

	void TestBloomFilter2()
	{
		srand(time(0));
		const size_t N = 100000;
		BloomFilter<8 * N> bf;

		std::vector<std::string> v1;
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

		for (size_t i = 0; i < N; ++i)
		{
			v1.push_back(url + std::to_string(1234 + i));
		}

		for (auto& str : v1)
		{
			bf.Set(str);
		}

		/*for (auto& str : v1)
		{
		cout << bf.Test(str) << endl;
		}
		cout << endl << endl;*/

		std::vector<std::string> v2;
		for (size_t i = 0; i < N; ++i)
		{
			std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
			url += std::to_string(999999 + i);
			v2.push_back(url);
		}

		size_t n2 = 0;
		for (auto& str : v2)
		{
			if (bf.Test(str))
			{
				++n2;
			}
		}
		cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

		std::vector<std::string> v3;
		for (size_t i = 0; i < N; ++i)
		{
			string url = "zhihu.com";
			url += std::to_string(rand());
			v3.push_back(url);
		}

		size_t n3 = 0;
		for (auto& str : v3)
		{
			if (bf.Test(str))
			{
				++n3;
			}
		}
		cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
	}
	
}