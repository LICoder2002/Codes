#pragma once
#include<iostream>
#include"Reverse_iterator.h"
#include<assert.h>
using std::cout;
using std::endl;

namespace lhf
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;



		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstoage, v._endofstoage);
		}

		// 休息11：37继续
		//vector(const vector& v);
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		//vector& operator=(vector v)
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		// 资源管理
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstoage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin()const
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rend()const
		{
			return reverse_iterator(begin());
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstoage - _start;
		}

		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, size()*sizeof(T));
					for (size_t i = 0; i < size(); ++i)
					{
						tmp[i] = _start[i];
					}

					delete[] _start;
				}

				_start = tmp;
			}

			_finish = _start + sz;
			_endofstoage = _start + n;
		}

		//void resize(size_t n, const T& val = T())
		void resize(size_t n, T val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}

			if (n > size())
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		void push_back(const T& x)
		{
			/*if (_finish == _endofstoage)
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}

			*_finish = x;
			++_finish;*/

			insert(end(), x);
		}

		void pop_back()
		{
			/*if (_finish > _start)
			{
				--_finish;
			}*/
			erase(end() - 1);
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		iterator insert(iterator pos, const T& x)
		{
			// 检查参数
			assert(pos >= _start && pos <= _finish);

			// 扩容
			// 扩容以后pos就失效了,需要更新一下
			if (_finish == _endofstoage)
			{
				size_t n = pos - _start;

				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);

				pos = _start + n;
			}

			// 挪动数据
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;

			return pos;
		}

		void clear()
		{
			_finish = _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstoage;
	};
}