#include<iostream>

#include"AVLTree.h"
using namespace std;

void TestAVLTree1()
{
	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int a[] = { 30,29,28,27,26,25,24,11,8,7,6,5,4,3,2,1 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.levelOrder();
}

void TestAVLTree2()
{
	const size_t N = 1024 * 1024 * 10;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		//v.push_back(rand());
		v.push_back(i);
	}

	AVLTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
	}

	//t.levelOrder();
	//cout << endl;
	cout << "是否平衡?" << t.IsBalanceTree() << endl;
	cout << "高度:" << t.Height() << endl;


	//t.InOrder();
}


int main()
{
	TestAVLTree1();

	return 0;
}