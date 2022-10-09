//5 钱币找零
//假设1元、2元、5元、10元、20元、50元、100元的纸币分别有c0, c1, c2, c3, c4, c5, c6张。现在要用这些钱来支付K
//元，至少要用多少张纸币？

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//按照面值降序排序
struct cmp
{
	bool operator()(vector<int>& v1, vector<int>& v2)
	{
		return v1[0] > v2[0];
	}
};


int minMum(int money, vector<vector<int>>& moneyMat)
{
	//排序
	sort(moneyMat.begin(), moneyMat.end(), cmp());

	int cnt = 0;
	for (auto arr : moneyMat)
	{
		int c = money / arr[0];
		c = min(c, arr[1]);

		money = money - c * arr[0];
		cnt += c;
	}
	if (money != 0)
	{
		return -1;
	}

	return cnt;
}
//
//int main()
//{
//	vector<vector<int>> moneyMat = { {1, 5}, { 5, 5 }, { 10, 5 }, { 20, 5 }, { 50, 5 }, { 100, 5} };
//
//	int money = 0;
//	cin >> money;
//
//	cout << minMum(money, moneyMat) << endl;
//	return 0;
//
//}