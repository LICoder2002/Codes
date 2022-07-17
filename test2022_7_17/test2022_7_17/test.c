#include<stdio.h>
//#define Mul(x,y) ++x*++y
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	printf(" % d", Mul(a + b, b + c));
//	return 0;
//}

#include <stdio.h>
#define a 10
void foo();
int main()
{
	printf("%d..", a);
	foo();
	printf("%d", a);
	return 0;
} 
void foo() {
#undef a
#define a 50
}