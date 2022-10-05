#include<iostream>
using namespace std;

class A
{
public:
	~A()
	{
		cout << "~A" << endl;
	}
};

class B
{
public:
	virtual~B()
	{
		cout << "~B" << endl;
	}
};

class C :public A, public B
{
public:
	~C()
	{
		cout << "~C" << endl;
	}
};

int main()
{
	C* c = new C;
	B* b1 = dynamic_cast<B*>(c);
	A* a2 = dynamic_cast<A*> (b1);

	delete a2;
	return 0;
}