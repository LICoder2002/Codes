#pragma once

namespace lhf
{

	template<class T>
	struct default_delete
	{
		void operator()(T* ptr)
		{
			delete ptr;
		}
	};

	template<class T, class D = default_delete<T>>
	class unique_ptr
	{
	public:
		// RAII˼��
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				//cout << "delete" << _ptr << endl;
				//delete _ptr;
				D del;
				del(_ptr);

				_ptr = nullptr;
			}
		}

		// ��ָ��һ��
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}


		//private:
		//	// sp2(sp1)
		//	// C++98
		//	// 1��ֻ��������ʵ��
		//	// 2��������˽��
		//	unique_ptr(const unique_ptr<T>& sp);

		unique_ptr(const unique_ptr<T>& sp) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;

	private:
		T* _ptr;
	};
}
