#pragma once

namespace lhf
{
	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		Iterator _it;
		typedef Reverse_iterator<Iterator, Ref, Ptr> self;


		Reverse_iterator(Iterator it)
			:_it(it)
		{}

		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		self& operator++()
		{
			--_it;
			return *this;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

		bool operator!=(const self& s)
		{
			return _it != s._it;
		}
	};
}
