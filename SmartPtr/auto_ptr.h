#pragma once

namespace lhf
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& p)
			:_ptr(p._ptr)
		{
			p._ptr = nullptr; //管理权转移
		}

		auto_ptr<T>& operator=(auto_ptr<T>& p)
		{
			if (this != &p)
			{
				if (_ptr)
				{
					delete _ptr;
				}

				//资源转移到当前对象
				_ptr = p._ptr;
				p._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				//cout << "delete" << endl;
				delete _ptr;
			}
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
	};
}