//5 Ǯ������
//����1Ԫ��2Ԫ��5Ԫ��10Ԫ��20Ԫ��50Ԫ��100Ԫ��ֽ�ҷֱ���c0, c1, c2, c3, c4, c5, c6�š�����Ҫ����ЩǮ��֧��K
//Ԫ������Ҫ�ö�����ֽ�ң�

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//������ֵ��������
struct cmp
{
	bool operator()(vector<int>& v1, vector<int>& v2)
	{
		return v1[0] > v2[0];
	}
};


int minMum(int money, vector<vector<int>>& moneyMat)
{
	//����
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