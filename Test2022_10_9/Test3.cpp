//��ˮƿ

#include<iostream>
using namespace std;

/*
//�ݹ�
int Count(int n)
{
    int count = 0;
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
    {
        int left = 0;
        count = n / 3;
        left = n % 3 + count;
        count += Count(left);
    }
    return count;
}*/

//�ǵݹ�
int Count(int n)
{
    int count = 0;
    if (n <= 1)
        return 0;


    while (n >= 3)
    {
        count += n / 3;
        n = n % 3 + n / 3;
    }

    if (n == 2)
        ++count;

    return count;

}
//int main()
//{
//	int n = 0;
//
//	while (cin >> n)
//	{
//		if (n == 0)
//			return 0;
//
//		cout << Count(n) << endl;
//	}
//
//	return 0;
//}