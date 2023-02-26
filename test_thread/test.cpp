#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;
//
//
//void Print(int n, int& x, mutex& mtx)
//{
//    for (int i = 0; i < n; ++i)
//    {
//        mtx.lock();
//        cout << this_thread::get_id() << ":" << i << endl;
//        ++x;
//        mtx.unlock();
//    }
//}
//
//int main()
//{
//    int count = 0;
//    mutex mtx;
//    thread t1(Print, 100, ref(count), ref(mtx));
//    thread t2(Print, 100, ref(count), ref(mtx));
//
//    t1.join();
//    t2.join();
//
//    cout << count << endl;
//
//    return 0;
//}

//int main()
//{
//	std::thread t1;
//	cout << t1.get_id() << endl;
//	return 0;
//}

//void ThreadFunc(int a)
//{
//	cout << "Thread 1: " << a <<  endl;
//	std::this_thread::sleep_for(std::chrono::milliseconds(100));
//}
//
//class TF
//{
//public:
//	void operator()()
//	{
//		cout << "Thread 3" << endl;
//		std::this_thread::sleep_for(std::chrono::milliseconds(100));
//
//	}
//};
//
//int main()
//{
//	// �̺߳���Ϊ����ָ��
//	thread t1(ThreadFunc, 10);
//
//	// �̺߳���ΪLambda���ʽ
//	thread t2([]() {
//		cout << "Thread 2" << endl; 
//		std::this_thread::sleep_for(std::chrono::milliseconds(100));
//		});
//
//	// �̺߳���Ϊ��������
//	TF tf;
//	thread t3(tf);
//
//	t1.join();
//	t2.join();
//	t3.join();
//
//	return 0;
//}


//void ThreadFunc1(int& x)
//{
//	x += 10;
//}
//void ThreadFunc2(int* x)
//{
//	*x += 10;
//}
//int main()
//{
//	int a = 10;
//	
//	// ���̺߳����ж�a�޸ģ�����Ӱ���ⲿʵ�Σ���Ϊ���̺߳���������Ȼ�����÷�ʽ������ʵ�����õ����߳�ջ�еĿ���
//	thread t1(ThreadFunc1, a);
//	t1.join();
//	cout << a << endl;
//	//
//	// �����Ҫͨ���βθı��ⲿʵ��ʱ���������std::ref()����
//	thread t2(ThreadFunc1, std::ref(a));
//	t2.join();
//	cout << a << endl;
//	
//	// ��ַ�Ŀ���
//	thread t3(ThreadFunc2, &a);
//	t3.join();
//	cout << a << endl;
//	
//	return 0;
//}
//



//atomic<unsigned long> sum = 0;
//
//void fun(size_t num)
//{
//	for (size_t i = 0; i < num; ++i)
//	{
//		sum++;
//	}
//}
//
//int main()
//{
//	cout << "Before joining,sum = " << sum << std::endl;
//	thread t1(fun, 10000000);
//	thread t2(fun, 10000000);
//	
//	t1.join();
//	t2.join();
//	
//	cout << "After joining,sum = " << sum << std::endl;
//	return 0;
//}

//int number = 0;
//mutex g_lock;
//int ThreadProc1()
//{
//	for (int i = 0; i < 100; i++)
//	{
//		g_lock.lock();
//		++number;
//		cout << "thread 1 :" << number << endl;
//		g_lock.unlock();
//	}
//	return 0;
//}
//int ThreadProc2()
//{
//	for (int i = 0; i < 100; i++)
//	{
//		g_lock.lock();
//		--number;
//		cout << "thread 2 :" << number << endl;
//		g_lock.unlock();
//	}
//	return 0;
//}
//
//int main()
//{
//	thread t1(ThreadProc1);
//	thread t2(ThreadProc2);
//	t1.join();
//	t2.join();
//	cout << "number:" << number << endl;
//	system("pause");
//	return 0;
//}


//template<class _Mutex>
//class lock_guard
//{
//public:
//	// �ڹ���lock_gardʱ��_Mtx��û�б�����
//	explicit lock_guard(_Mutex& _Mtx)
//		: _MyMutex(_Mtx)
//	{
//		_MyMutex.lock();
//	}
//	// �ڹ���lock_gardʱ��_Mtx�Ѿ����������˴�����Ҫ������
//	lock_guard(_Mutex& _Mtx, adopt_lock_t)
//		: _MyMutex(_Mtx)
//	{}
//	~lock_guard() _NOEXCEPT
//	{
//		_MyMutex.unlock();
//	}
//	lock_guard(const lock_guard&) = delete;
//	lock_guard& operator=(const lock_guard&) = delete;
//private:
//	_Mutex& _MyMutex;
//};



int main()
{
	int i = 0;
	int n = 100;
	mutex mtx;
	condition_variable cv; // ������������
	bool ready = true;

	// t1��ӡ����
	thread t1([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock, [&ready](){return !ready; });

			cout << "t1--" << this_thread::get_id() << ":" << i << endl;
			i += 1;

			ready = true;

			cv.notify_one();

		}
	});

	// t2��ӡż��
	thread t2([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock, [&ready](){return ready; });

			cout <<"t2--"<<this_thread::get_id() << ":" << i << endl;
			i += 1;
			ready = false;

			cv.notify_one();
		}
	});

	this_thread::sleep_for(chrono::seconds(3));

	cout << "t1:" << t1.get_id() << endl;
	cout << "t2:" << t2.get_id() << endl;

	t1.join();
	t2.join();

	return 0;
}