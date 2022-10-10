#pragma once
#include<iostream>
#include<string>
using namespace std;

//1.�����һ���࣬���ܱ�����
/*����ֻ����������������У��������캯���Լ���ֵ��������أ������Ҫ��һ�����ֹ������ֻ���ø��಻�ܵ��ÿ������캯���Լ���ֵ��������ؼ��ɡ�*/
class CopyBan1
{
public:
	CopyBan1()
	{}
	//C++ 98 ���������캯���븳ֵ���������ֻ���������壬���ҽ������Ȩ������Ϊ˽�м��ɡ�
private:
	CopyBan1(const CopyBan1&);
	CopyBan1& operator=(const CopyBan1&);

};

class CopyBan2
{

	/*C++11
		C++11��չdelete���÷���delete�����ͷ�new�������Դ�⣬�����Ĭ�ϳ�Ա���������
		= delete����ʾ�ñ�����ɾ������Ĭ�ϳ�Ա������*/
public:

	CopyBan2(){}

	CopyBan2(const CopyBan2&) = delete;
	CopyBan2& operator=(const CopyBan2&) = delete;

};

//2. �����һ���ֻ࣬���ڶ��ϴ�������

//��һ


//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObj()
//	{
//		return new HeapOnly;
//	}
//
//private:
//	//���캯��˽��
//	HeapOnly(){}
//	HeapOnly(const HeapOnly&);
//	HeapOnly& operator=(const HeapOnly&) = delete;
//};

//����

class HeapOnly
{
public:
	static void DelObj(HeapOnly* ptr)
	{
		delete ptr;
	}

	/*void DelObj()
	{
		delete this;
	}*/

private:
	 //��������˽��
	~HeapOnly()
	{}
};


//3. �����һ���ֻ࣬����ջ�ϴ�������

class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();
	}

	//StackOnly(const StackOnly&) = delete;

	//StackOnly& operator=(const StackOnly&) = delete;
	
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;

private:
	StackOnly(){}
};

//�����һ���࣬���ܱ��̳�

// C++98�й��캯��˽�л����������е���������Ĺ��캯�������޷��̳�
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};

//C++11����
//final�ؼ��֣�final�����࣬��ʾ���಻�ܱ��̳С�
class A final
{
	//...
};

//5. �����һ���ֻ࣬�ܴ���һ������(����ģʽ)

//����ģʽ

// �ŵ㣺��
// ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ����

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return _spInst;
	}

	void Print();
private:
	Singleton()
	{}

	Singleton(const Singleton&) = delete;


	//static Singleton _sInst; // ����
	static Singleton* _spInst; // ����

	int _a = 0;
};

//Singleton Singleton::_sInst; // ����
Singleton* Singleton::_spInst = new Singleton; // ����

void Singleton::Print()
{
	cout << _a << endl;
}

// InfoMgr -- ����
class InfoMgr
{
public:
	static InfoMgr* GetInstance()
	{
		return _spInst;
	}

	void SetAddress(const string& s)
	{
		_address = s;
	}

	string& GetAddress()
	{
		return _address;
	}

private:
	InfoMgr()
	{}

	InfoMgr(const InfoMgr&) = delete;

	string _address;
	int _secretKey;

	static InfoMgr* _spInst; // ����
};

InfoMgr* InfoMgr::_spInst = new InfoMgr; // ����



//����ģʽ
// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
// ȱ�㣺����

class InfoMg 
{
public:
	static InfoMg* getInstance()
	{
		if (_pInfoMa == nullptr)
		{
			_pInfoMa = new InfoMg;
		}
		return _pInfoMa;
	}

	void SetAddress(const string& s)
	{
		_address = s;
	}

	string& GetAddress()
	{
		return _address;
	}

	// ʵ��һ����Ƕ����������    
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (_pInfoMa)
			{
				delete _pInfoMa;
			}
		}
	};

	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:



	InfoMg(){}

	~InfoMg(){}


	string _address;
	int _secretKey;
	
	static InfoMg* _pInfoMa; //����

};

InfoMg* InfoMg::_pInfoMa = nullptr;
InfoMg::CGarbo Garbo;
