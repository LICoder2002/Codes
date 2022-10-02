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
			p._ptr = nullptr; //����Ȩת��
		}

		auto_ptr<T>& operator=(auto_ptr<T>& p)
		{
			if (this != &p)
			{
				if (_ptr)
				{
					delete _ptr;
				}

				//��Դת�Ƶ���ǰ����
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