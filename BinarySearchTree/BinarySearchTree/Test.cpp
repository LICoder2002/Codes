#include"BinarySearchTree.h"

void Test1()
{
	cout << "Test1(): ·ÇµÝ¹é" << endl;
	key::BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.InsertR(e);
	}
	t.InOrder();

	t.Insert(9);
	t.Insert(16);

	t.Erase(16);
	t.Erase(8);
	//t.Erase(9);
	t.InOrder();
	for (auto e : a)
	{
		t.Erase(e);
	}
	t.InOrder();
}

void Test2()
{
	cout << "Test2(): µÝ¹é" << endl;
	key::BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.InsertR(e);
	}
	t.InOrder();

	t.InsertR(9);
	t.InsertR(16);

	t.EraseR(16);
	t.EraseR(8);
	//t.Erase(9);
	t.InOrder();
	for (auto e : a)
	{
		t.EraseR(e);
	}
	t.InOrder();
}

int main()
{
	//Test1();
	Test2();

	key_value::TestBSTree1();
	key_value::TestBSTree2();

	system("pause");
	return 0;
}