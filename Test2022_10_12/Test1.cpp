//Å£¿ÍÍø¡ª¡ªÏ´ÅÆ https://www.nowcoder.com/practice/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0?tpId=122&tqId=33670

#include<iostream>
#include<vector>
using namespace std;

vector<int> wash(vector<int>& arr)
{
	int size = arr.size();
	vector<int> tmp;

	int i = size / 2;
	int j = 1;

	while (i)
	{
		tmp.push_back(arr[size - j]);
		tmp.push_back(arr[(size / 2) - j]);
		--i;
		++j;
	}

	reverse(tmp.begin(), tmp.end());

	return tmp;
}

int main()
{
	int time = 0;
	int n = 0, k = 0;
	cin >> time;
	
	while (time--)
	{
		cin >> n >> k;
		vector<int> arr(2 * n);

		for (int i = 0; i < 2 * n; ++i)
		{
			cin >> arr[i];
		}

		while (k--)
		{
			arr = wash(arr);
		}

		for (auto e : arr)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}