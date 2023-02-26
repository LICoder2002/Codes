#include<iostream>
#include"auto_ptr.h"
#include"unique_ptr.h"
#include"shared_ptr.h"
#include"weak_ptr.h"

#include <thread>
#include <vector>


using namespace std;

//int main()
//{
//	std::auto_ptr<int> sp1(new int);
//	std::auto_ptr<int> sp2(sp1); // 管理权转移
//
//	// sp1悬空
//	*sp2 = 10;
//	cout << *sp2 << endl;
//	cout << *sp1 << endl;
//	return 0;
//}

//
//int main()
//{
//	lhf::unique_ptr<int> sp1(new int);
//	//lhf::unique_ptr<int> sp2(sp1);
//
//	std::unique_ptr<int> sp1(new int);
//	//std::unique_ptr<int> sp2(sp1);
//
// return 0;
//}

//int main()
//{
//	 lhf::shared_ptr<int> sp1(new int);
//	 lhf::shared_ptr<int> sp2(sp1);
//	 lhf::shared_ptr<int> sp3(sp1);
//
//	 lhf::shared_ptr<int> sp4(new int);
//	 lhf::shared_ptr<int> sp5(sp4);
//
//	 //sp1 = sp1;
//	 //sp1 = sp2;
//
//	 sp1 = sp4;
//	 sp2 = sp4;
//	 sp3 = sp4;
//
//	 *sp1 = 2;
//	 *sp2 = 3;
//
// return 0;
//}

//struct ListNode
//{
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//	~ListNode() 
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}

//
//struct ListNode
//{
//	/*ListNode* _next = nullptr;
//	ListNode* _prev = nullptr;*/
//
//
//
//	std::weak_ptr<ListNode> _next;
//	std::weak_ptr<ListNode> _prev;
//
//	int _val = 0;
//
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//
//int main()
//{
//	std::shared_ptr<ListNode> node1(new ListNode);
//	std::shared_ptr<ListNode> node2(new ListNode);
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//
//	node1->_next = node2;
//	node2->_prev = node1;
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}
//
//template<class T>
//struct FreeFunc
//{
//	void operator()(T* ptr)
//	{
//		cout << "free:" << ptr << endl;
//		free(ptr);
//	}
//};
//template<class T>
//struct DeleteArrayFunc
//{
//	void operator()(T* ptr)
//	{
//		cout << "delete[]" << ptr << endl;
//		delete[] ptr;
//	}
//};
//int main()
//{
//	FreeFunc<int> freeFunc;
//	std::shared_ptr<int> sp1((int*)malloc(4), freeFunc);
//	DeleteArrayFunc<int> deleteArrayFunc;
//
//	std::shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);
//	//std::shared_ptr<FILE> sp5(fopen("test.txt", "w"), [](FILE* p) {fclose(p); });
//	return 0;
//}

#include <memory>

//int main()
//{
//	std::shared_ptr<double> sp1(new double(1.1));
//	std::shared_ptr<double> sp2(sp1);
//
//	vector<thread> v(2);
//	int n = 100;
//	
//	for (auto& t : v)
//	{
//		t = thread([&]() {
//			for (int i = 0; i < n; ++i)
//			{
//				std::shared_ptr<double> sp(sp1);
//
//				(*sp)++;
//			}
//
//
//		});
//	}
//
//	for (auto& t : v)
//	{
//		t.join();
//	}
//
//	cout << sp1.use_count() << endl;
//	cout << (*sp1) << endl;
//
//
//	return 0;
//}



int main()
{
	lhf::shared_ptr<double> sp1(new double(1.1));
	lhf::shared_ptr<double> sp2(sp1);

	mutex mtx;

	vector<thread> v(2);
	int n = 100;

	for (auto& t : v)
	{
		t = thread([&]() {
			for (int i = 0; i < n; ++i)
			{
				//拷贝构造是线程安全的
				//lhf::shared_ptr<double> sp(sp1);
				lhf::shared_ptr<double> sp(new double(0.1));

				//访问资源不是线程安全的
				mtx.lock();
				(*sp)++;
				mtx.unlock();
				//cout << "count: " << sp.use_count() << endl;
			}


			});
	}

	for (auto& t : v)
	{
		t.join();
	}

	cout << sp1.use_count() << endl;
	cout << (*sp1) << endl;


	return 0;
}