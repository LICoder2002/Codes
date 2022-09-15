#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;

namespace lhf
{
	// N个比特位图
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			// +1 保证有足够多的比特位，最多浪费8个
			_bits.resize(N / 8 + 1, 0);
		}

		//x映射的位置标记为1
		void set(size_t x)
		{
			// x映射的比特位在第几个char对象
			size_t i = x / 8;

			// x在char第几个比特位
			size_t j = x % 8;

			_bits[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			// x映射的比特位在第几个char对象
			size_t i = x / 8;

			// x在char第几个比特位
			size_t j = x % 8;

			_bits[i] &= (~(1 << j));
		}

		bool test(size_t x)
		{
			// x映射的比特位在第几个char对象
			size_t i = x / 8;

			// x在char第几个比特位
			size_t j = x % 8;

			return _bits[i] & 1 << j;

		}

	private:
		std::vector<char> _bits;
	};

	void test_bit_set1()
	{
		bitset<100> bs;
		bs.set(18);
		bs.set(19);

		cout << bs.test(18) << endl;
		cout << bs.test(19) << endl;
		cout << bs.test(20) << endl;


		bs.reset(18);
		bs.reset(18);

		cout << bs.test(18) << endl;
		cout << bs.test(19) << endl;
		cout << bs.test(20) << endl;

		//bitset<INT_MAX> bigBS;
		bitset<0xFFFFFFFF> bigBS;
		//bitset<-1> bigBS;

		//bit_set<2^32-1> bigBS; // pow
	}


	//给定100亿个整数，设计算法找到只出现一次的整数？
	// 0次 00
	// 1次 01
	// 2次及以上 10
	template<size_t N>
	class two_bitset
	{
	public:
		void set(size_t x)
		{
			int in1 = _bs1.test(x);
			int in2 = _bs2.test(x);

			if (in1 == 0 && in2 == 0)
			{
				_bs2.set(x);
			}
			else if (in1 == 0 && in2 == 1)
			{
				_bs1.set(x);
				_bs2.reset(x);
			}
		}

		bool is_once(size_t x)
		{
			return _bs1.test(x) == 0 && _bs2.test(x) == 1;
		}

	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};

	void test_two_bitset()
	{
		int a[] = { 4, 3, 2, 4, 5, 2, 2, 4, 7, 8, 9, 2, 1,3,7 };
		two_bitset<10> tbs;
		for (auto e : a)
		{
			tbs.set(e);
		}

		for (size_t i = 0; i < 10; ++i)
		{
			if (tbs.is_once(i))
			{
				cout << i << endl;
			}
		}
	}
}