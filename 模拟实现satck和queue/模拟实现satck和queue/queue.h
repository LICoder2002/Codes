#pragma once
#include<deque>
#include <vector>
#include<assert.h>
#include<iostream>

namespace lhf
{
	template<class T,  class Container = std::deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front()
		{
			return _con.front();
		}

		const T& back()
		{
			return _con, back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};




	//优先级队列

	//小于
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	//大于
	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class Container = std::vector<int>, class Compare = less<T>>
	class priority_queue
	{
	private:

		//大堆 <  小堆 >

		void AdjustUp(int child)
		{
			Compare comFunc;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[patent] < _con[child])
				if (comFunc(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}

			}
		}

		void AdjustDown(int parent)
		{
			Compare comFunc;
			int child = parent * 2 + 1;//默认左孩子
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && comFunc(_con[child], _con[child + 1]))
				{
					++child;
				}

				if (comFunc(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	public:
		priority_queue(const Compare& comFunc = Compare())
			:_comFunc(comFunc)
		{}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last, const Compare& comFunc = Compare())
			: _comFunc(comFunc)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			//建堆
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				AdjustDown(i);
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			assert(!_con.empty());

			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			AdjustDown(0);
		}

		const T& top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;
		Compare _comFunc;
	};
}