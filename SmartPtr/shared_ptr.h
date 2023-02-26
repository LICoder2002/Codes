#pragma once

#include <mutex>

namespace lhf
{
	template<class T>
	class shared_ptr
	{
	private:
		void release()
		{
			bool flag = false; //用于最后是否释放锁的标志

			_pMutex->lock();
			if (--(*_pCount) == 0 && _ptr)
			{
				std::cout << "delete" << std::endl;
				delete _ptr;
				_ptr = nullptr;

				delete _pCount;
				_pCount = nullptr;

				flag = true;
			}
			_pMutex->unlock();

			if (flag)
			{
				delete _pMutex;
				_pMutex = nullptr;
			}
		}
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			,_pCount(new int(1))
			,_pMutex(new std::mutex)
		{}

		shared_ptr(const shared_ptr<T>& p)
			:_ptr(p._ptr)
			, _pCount(p._pCount)
			,_pMutex(p._pMutex)
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& p)
		{
			if (_ptr != p._ptr)
			{
				this->release();
				_ptr = p._ptr;
				_pCount = p._pCount;
				_pMutex = p._pMutex;

				_pMutex->lock();
				++(*_pCount);
				_pMutex->unlock();
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

		int use_count()
		{
			return *_pCount;
		}


	private:
		T* _ptr;
		int* _pCount;
		std::mutex* _pMutex;
	};
}