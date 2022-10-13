//牛客网--小易的升级之路
#include<iostream>
#include<vector>
using namespace std;

int getGcd(int x, int y)
{
	int tmp = 0;
	while (tmp = x % y)
	{
		x = y;
		y = tmp;
	}

	return y;
}

int main()
{
	int n = 0, a = 0;

	while (cin >> n >> a)
	{
		vector<int> arr(n);

		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		for (int i = 0; i < n; ++i)
		{
			if (a >= arr[i])
				a += arr[i];
			else
				a += getGcd(a, arr[i]);
		}

		cout << a << endl;
	}
}