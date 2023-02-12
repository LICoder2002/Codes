#include <stdio.h>

extern int Add(int x, int y);

int main()
{
    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("sum = %d\n", sum);
    return 0;
}