//计算字串之间的编辑距离

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string str1, str2;
	
	cin >> str1 >> str2;

	

	int row = str1.size();
	int col = str2.size();

	if (row == 0 || col == 0)
	{
		cout << max(row, col) << endl;
		return 0;
	}

	vector<vector<int>> dis(row + 1, vector<int>(col + 1, 0));

	//初始化
	for (int i = 0; i <= col; ++i)
		dis[0][i] = i;

	for (int i = 1; i <= row; ++i)
		dis[i][0] = i;

	for (int i = 1; i <= row; ++i)
	{
		for (int j = 1; j <= col; ++j)
		{
			////插入、删除
			dis[i][j] = min(dis[i][j - 1], dis[i - 1][j]) + 1;

			//替换
			if (str1[i - 1] == str2[j - 1])
				dis[i][j] = min(dis[i][j], dis[i - 1][j - 1]);
			else
				dis[i][j] = min(dis[i][j], dis[i - 1][j - 1] + 1);
		}
	}

	cout << dis[row][col] <<endl;
	return 0;

}