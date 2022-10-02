#pragma once

namespace lhf
{
	// ������ָ����Դ���ͷŹ���
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		weak_ptr<T>& operator=(const lhf::shared_ptr<T>& p)
		{
			_ptr = p._ptr;
			return *this;
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

	public:
		T* _ptr;
	};
}