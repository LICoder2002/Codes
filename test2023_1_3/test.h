#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

//book:标志位。当前盒子是否占用
//bok:盒子
//盒子下标
//n:牌数
void DFS(vector<int>& book, vector<int>& box, int idx, int n)
{
	//边界判断
	if (idx == n + 1)
	{
		for (int i = 1; i <= n; ++i)
			cout << box[i] << " ";
		cout << endl;
		return;
	}
	//尝试每一种可能
	for (int i = 1; i <= n; ++i)
	{
		if (book[i] == 0)
		{
			box[idx] = i;
			book[i] = 1;
			//处理下一个
			DFS(book, box, idx + 1, n);
			//回溯
			book[i] = 0;
		}
	}
}

void test1()
{
	int n;
	cin >> n;

	vector<int> book(n + 1, 0);
	vector<int> box(n + 1, 0);
	DFS(book, box, 1, n);
}

//https://leetcode.cn/problems/employee-importance/submissions/
// Definition for Employee.
class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
};


class Solution {
public:

	int DFS(unordered_map<int, Employee*>& info, int id)
	{
		int sumImpor = info[id]->importance;
		for (const auto& sid : info[id]->subordinates)
		{
			sumImpor += DFS(info, sid);
		}
		return sumImpor;
	}
	int getImportance(vector<Employee*> employees, int id) {
		if (employees.empty())
			return 0;

		unordered_map<int, Employee*> info;
		for (const auto& e : employees)
		{
			info[e->id] = e;
		}

		return DFS(info, id);

	}
};



//https://leetcode.cn/problems/flood-fill/submissions/
class Solution {
public:

	int nextP[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //上下左右偏移量

	void DFS(vector<vector<int>>& image, int row, int col, vector<vector<int>>& book,
		int curX, int curY, int oldColor, int newColor)
	{
		//当前位置修改颜色
		image[curX][curY] = newColor;
		book[curX][curY] = 1; // 标记当前位置

		//搜索上下左右
		for (int i = 0; i < 4; ++i)
		{
			int newX = curX + nextP[i][0];
			int newY = curY + nextP[i][1];
			//判断是否越界
			if (newX >= row || newY >= col || newX < 0 || newY < 0)
				continue;
			if (image[newX][newY] == oldColor && book[newX][newY] == 0)
			{
				//处理新位置
				DFS(image, row, col, book, newX, newY, oldColor, newColor);
			}
		}


	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		if (image.empty())
			return image;

		int row = image.size();
		int col = image[0].size();

		vector<vector<int>> book(row, vector<int>(col, 0));
		DFS(image, row, col, book, sr, sc, image[sr][sc], color);
		return image;

	}
};