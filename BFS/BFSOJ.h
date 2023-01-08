#pragma once

#include "maze.h"

//N叉数的层序遍历
//https://leetcode.cn/problems/n-ary-tree-level-order-traversal/submissions/

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution1
{
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        queue<Node*> q;
        if (root)
            q.push(root);
        vector<vector<int>> treeMat;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> rowV;
            while (size--)
            {
                Node* curNode = q.front();
                q.pop();
                rowV.push_back(curNode->val);

                for (auto ch : curNode->children)
                {
                    q.push(ch);
                }
            }
            treeMat.push_back(rowV);
        }
        return treeMat;
    }
};

class Solution2 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;

        //首先找到腐烂的橘子
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push({ i, j });
                }
            }
        }

        int nextPos[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        int step = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;

            while (size--)
            {
                pair<int, int> curPos = q.front();
                q.pop();
                //添加标记
                //四个方向蔓延
                for (int i = 0; i < 4; ++i)
                {
                    int newX = curPos.first + nextPos[i][0];
                    int newY = curPos.second + nextPos[i][1];
                    //判断是否越界
                    if (newX >= row || newX < 0 || newY >= col || newY < 0)
                        continue;

                    if (grid[newX][newY] == 1)
                    {
                        flag = true;
                        grid[newX][newY] = 2;
                        q.push({ newX, newY });
                    }
                }
            }
            if (flag)
                step++;
        }

        //判断是否还有新鲜橘子
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return step;
    }
    
    void test()
    {
        vector<vector<int>>  grid1 = { {2, 1, 1} ,{0, 1, 1},{1, 0, 1} };
        vector<vector<int>>  grid2 = { {2, 1, 1} ,{1, 1, 0},{0, 1, 1} };
        cout << orangesRotting(grid2) << endl;
    }
};
