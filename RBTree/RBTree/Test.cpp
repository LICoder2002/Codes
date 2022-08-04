#include"RBTree.h"

void TestRBTree1()
{
	cout << "TestRBTree1:" << endl;
	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int a[] = { 30, 29, 28, 27, 26, 25, 24, 11, 8, 7, 6, 5, 4, 3, 2, 1 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.levelOrder();
	t.InOrder();
	t.Height();
	cout << endl << endl;
}

void TestRBTree2()
{
	cout << "TestRBTree2:" << endl;
	const size_t N = 1024 * 1024*10;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		//v.push_back(rand());
		v.push_back(i);
	}

	RBTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
	}

	//t.levelOrder();
	//cout << endl;
	cout << "ÊÇ·ñÆ½ºâ?" << t.IsBalanceRBTree() << endl;
	t.Height();

	//t.InOrder();
}

int main()
{
	TestRBTree1();
	TestRBTree2();

	return 0;
}