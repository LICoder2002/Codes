#pragma once
namespace lhf
{
	template<class T>
	class shared_ptr
	{
	private:
		void release()
		{
			if (--(*_pCount) == 0 && _ptr)
			{
				delete _ptr;
				_ptr = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
		}
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			,_pCount(new int(1))
		{}

		shared_ptr(const shared_ptr<T>& p)
			:_ptr(p._ptr)
			, _pCount(p._pCount)
		{
			++(* _pCount);
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& p)
		{
			if (_ptr != p._ptr)
			{
				this->release();
				_ptr = p._ptr;
				_pCount = p._pCount;
				++(*_pCount);
			}
			return *this;
		}

		~shared_ptr()
		{
			this->release();
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}


	private:
		T* _ptr;
		int* _pCount;
	};
}