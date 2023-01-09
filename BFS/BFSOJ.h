#pragma once

#include <unordered_set>
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
    
    //单词接龙
    //https://leetcode.cn/problems/word-ladder/submissions/
    class Solution3 {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            int step = 1;
            queue<string> q;
            unordered_set<string> dict;//转化成哈希表，提高查询效率
            unordered_set<string> book;

            q.push(beginWord);
            book.insert(beginWord);

            //词典转化
            for (auto& wd : wordList)
                dict.insert(wd);

            while (!q.empty())
            {
                int size = q.size();
                while (size--)
                {
                    string curStr = q.front();
                    q.pop();

                    if (curStr == endWord)
                        return step;

                    //修改单词的某一个位置
                    for (int i = 0; i < curStr.size(); ++i)
                    {
                        string strTmp = curStr;
                        for (char ch = 'a'; ch <= 'z'; ++ch)
                        {
                            strTmp[i] = ch;
                            //判断新单词是否在词典中，且没有搜索过
                            if (dict.find(strTmp) != dict.end() && book.find(strTmp) == book.end())
                            {
                                book.insert(strTmp);
                                q.push(strTmp);
                            }
                        }
                    }
                }
                ++step;
            }
            return 0;
        }
    };

    //最小基因变化
    //https://leetcode.cn/problems/minimum-genetic-mutation/comments/
    class Solution4 {
    public:
        string strV = "ACGT";
        int minMutation(string startGene, string endGene, vector<string>& bank) {
            int step = 0;
            queue<string> q;
            unordered_set<string> _bank;
            unordered_set<string> book;
            q.push(startGene);
            book.insert(startGene);

            for (auto& str : bank)
                _bank.insert(str);

            while (!q.empty())
            {
                int size = q.size();
                while (size--)
                {
                    string curStr = q.front();
                    q.pop();

                    if (curStr == endGene)
                        return step;

                    for (int i = 0; i < curStr.size(); ++i)
                    {
                        string tmpStr = curStr;
                        for (int k = 0; k < 4; ++k)
                        {
                            tmpStr[i] = strV[k];
                            if (_bank.find(tmpStr) != _bank.end() && book.find(tmpStr) == book.end())
                            {
                                q.push(tmpStr);
                                book.insert(tmpStr);
                            }
                        }
                    }
                }
                ++step;
            }
            return -1;
        }
    };

    //打开转盘锁
    //https://leetcode.cn/problems/open-the-lock/submissions/
    class Solution5 {
    public:
        int openLock(vector<string>& deadends, string target) {
            unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
            if (deadendsSet.find("0000") != deadendsSet.end())
                return -1;

            queue<string> q;
            q.push("0000");
            unordered_set<string> book;
            book.insert("0000");

            int step = 0;
            while (!q.empty())
            {
                int size = q.size();
                while (size--)
                {
                    string curNum = q.front();
                    q.pop();

                    if (curNum == target)
                        return step;

                    for (int i = 0; i < 4; ++i)
                    {
                        string tmpNum1 = curNum;
                        string tmpNum2 = curNum;

                        //向上或者向下拨动
                        tmpNum1[i] = tmpNum1[i] == '9' ? '0' : tmpNum1[i] + 1;
                        tmpNum2[i] = tmpNum2[i] == '0' ? '9' : tmpNum2[i] - 1;

                        //判断tmpNum1是否在死亡数字中，并且是否使用过
                        if (deadendsSet.find(tmpNum1) == deadendsSet.end()
                            && book.find(tmpNum1) == book.end())
                        {
                            q.push(tmpNum1);
                            book.insert(tmpNum1);
                        }

                        //判断tmpNum2是否在死亡数字中，并且是否使用过
                        if (deadendsSet.find(tmpNum2) == deadendsSet.end()
                            && book.find(tmpNum2) == book.end())
                        {
                            q.push(tmpNum2);
                            book.insert(tmpNum2);
                        }
                    }
                }
                ++step;
            }
            return -1;
        }
    };


    void test()
    {
        vector<vector<int>>  grid1 = { {2, 1, 1} ,{0, 1, 1},{1, 0, 1} };
        vector<vector<int>>  grid2 = { {2, 1, 1} ,{1, 1, 0},{0, 1, 1} };
        cout << orangesRotting(grid2) << endl;
    }
};


