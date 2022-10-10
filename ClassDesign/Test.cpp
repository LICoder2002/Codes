#include"ClassDesign.h"
using namespace std;

void Test1()
{
	CopyBan1 cb;
	//CopyBan1 cb2(cb);//无法访问 private 成员(在“CopyBan1”类中声明)
	//CopyBan1 c = cb;

	CopyBan2 cb2;
	//CopyBan2 c = cb2;
}

//void Test2()
//{
//	//HeapOnly h1;
//	//static HeapOnly h2;
//	//HeapOnly* ph3 = new HeapOnly;
//	HeapOnly* ph4 = HeapOnly::CreateObj();
//	HeapOnly* ph5 = HeapOnly::CreateObj();
//
//	//HeapOnly copy(*ph4);
//
//	delete ph4;
//	delete ph5;
//}

void Test3()
{
	//HeapOnly h1;
	//static HeapOnly h2;
	HeapOnly* ph3 = new HeapOnly;

	//delete ph3;
	HeapOnly::DelObj(ph3);
	//ph3->DelObj();

}

void Test4()
{
	//StackOnly s1;
	StackOnly s2 = StackOnly::CreateObj();

	//StackOnly* s3 = new StackOnly;
}

void Test5()
{
	//InfoMgr info1;
	//static InfoMgr info2;
	//InfoMgr info3;

	// 全局只有一个InfoMgr对象
	InfoMgr::GetInstance()->SetAddress("XXXX");

	cout << InfoMgr::GetInstance()->GetAddress() << endl;
}

int main()
{
	Test5();

	return 0;
}