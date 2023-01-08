#pragma once
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//BFS�Թ�����
struct node
{
	int x;
	int y;
};

//queueʵ��
bool BFS(vector<vector<int>>& graph, int startX, int startY, int destX, int destY)
{
	int nextPosition[4][2] = { {-1, 0}, {1, 0}, {0,-1}, {0, 1} };//��������ƫ����
	int row = graph.size();
	int col = graph[0].size();
	vector<vector<int>> book(row, vector<int>(col, 0));//��Ǿ���
	queue<node> q;
	q.push({ startX, startY });
	//����Ѿ��߹���λ��
	book[startX][startY] = 1;

	while (!q.empty())
	{

		node curPos = q.front();
		q.pop();
		if (curPos.x == destX && curPos.y == destY)
			return true;

		//Ѱ����λ��
		for (int i = 0; i < 4; ++i)//��������Ѱ��δ�߹���λ��
		{
			int newX = curPos.x + nextPosition[i][0];
			int newY = curPos.y + nextPosition[i][1];

			//�ж��Ƿ�Խ��
			if (newX >= row || newX < 0 || 
				newY >= col || newY < 0)
				continue;


			//�ж���λ��
			if (graph[newX][newY] == 0 && book[newX][newY] == 0)
			{
				//δ�����򱣴�
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
		cout << "�������: start position." << endl;
		cout << "startX: " ;
		cin >> x;
		cout << endl << "startY: ";
		cin >> y;
		node startPos({ x, y });

		cout << "�����յ�: end position." << endl;
		cout << "endX: ";
		cin >> x;
		cout << endl << "endY: ";
		cin >> y;
		node endPos({ x, y });

		cout << BFS(graph, startPos.x, startPos.y, endPos.x, endPos.y) << endl;
	}

}