#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;

namespace lhf
{
	// N������λͼ
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			// +1 ��֤���㹻��ı���λ������˷�8��
			_bits.resize(N / 8 + 1, 0);
		}

		//xӳ���λ�ñ��Ϊ1
		void set(size_t x)
		{
			// xӳ��ı���λ�ڵڼ���char����
			size_t i = x / 8;

			// x��char�ڼ�������λ
			size_t j = x % 8;

			_bits[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			// xӳ��ı���λ�ڵڼ���char����
			size_t i = x / 8;

			// x��char�ڼ�������λ
			size_t j = x % 8;

			_bits[i] &= (~(1 << j));
		}

		bool test(size_t x)
		{
			// xӳ��ı���λ�ڵڼ���char����
			size_t i = x / 8;

			// x��char�ڼ�������λ
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


	//����100�ڸ�����������㷨�ҵ�ֻ����һ�ε�������
	// 0�� 00
	// 1�� 01
	// 2�μ����� 10
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