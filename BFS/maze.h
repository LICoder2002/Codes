#pragma once
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//BFS迷宫问题
struct node
{
	int x;
	int y;
};

//queue实现
bool BFS(vector<vector<int>>& graph, int startX, int startY, int destX, int destY)
{
	int nextPosition[4][2] = { {-1, 0}, {1, 0}, {0,-1}, {0, 1} };//上下左右偏移量
	int row = graph.size();
	int col = graph[0].size();
	vector<vector<int>> book(row, vector<int>(col, 0));//标记矩阵
	queue<node> q;
	q.push({ startX, startY });
	//标记已经走过的位置
	book[startX][startY] = 1;

	while (!q.empty())
	{

		node curPos = q.front();
		q.pop();
		if (curPos.x == destX && curPos.y == destY)
			return true;

		//寻找新位置
		for (int i = 0; i < 4; ++i)//上下左右寻找未走过的位置
		{
			int newX = curPos.x + nextPosition[i][0];
			int newY = curPos.y + nextPosition[i][1];

			//判断是否越界
			if (newX >= row || newX < 0 || 
				newY >= col || newY < 0)
				continue;


			//判断新位置
			if (graph[newX][newY] == 0 && book[newX][newY] == 0)
			{
				//未经过则保存
				q.push({ newX, newY });
				book[newX][newY] = 1;
			}
		}
	}
	return false;
}

void test()
{
	vector<vector<int>> graph { {0, 0, 1, 0}, 
								{1, 0, 0, 1},
								{0, 0, 0, 0},
								{1, 1, 0, 0} };

	for (auto arr : graph)
	{
		for (auto num : arr)
		{
			cout << num << " ";
		}
		cout << endl;
	}

	int x, y;
	while (true)
	{
		cout << "输入起点: start position." << endl;
		cout << "startX: " ;
		cin >> x;
		cout << endl << "startY: ";
		cin >> y;
		node startPos({ x, y });

		cout << "输入终点: end position." << endl;
		cout << "endX: ";
		cin >> x;
		cout << endl << "endY: ";
		cin >> y;
		node endPos({ x, y });

		cout << BFS(graph, startPos.x, startPos.y, endPos.x, endPos.y) << endl;
	}

}