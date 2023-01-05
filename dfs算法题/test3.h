#include "test.h"

//https://leetcode.cn/problems/n-queens/submissions/

class Solution {
public:

    void DFS(vector<vector<pair<int, int>>>& allRet, vector<pair<int, int>>& curRet, int curRow, int n)
    {
        if (curRow == n)
        {
            allRet.push_back(curRet);
            return;
        }
        //确定当前行的每一个位置是否和已经确定的位置冲突
        for (int i = 0; i < n; ++i)
        {
            if (isValidPos(curRet, curRow, i))
            {
                curRet.push_back(make_pair(curRow, i));
                //处理下一行
                DFS(allRet, curRet, curRow + 1, n);
                //回溯
                curRet.pop_back();
            }
        }
    }

    bool isValidPos(vector<pair<int, int>>& curRet, int row, int col)
    {
        for (pair<int, int> pos : curRet)
        {
            if (col == pos.second || row + col == pos.first + pos.second || row - col == pos.first - pos.second)
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> transResult(vector<vector<pair<int, int>>>& allRet, int n)
    {
        vector<vector<string>> allMat;
        //所有方案
        for (vector<pair<int, int>> curRet : allRet)
        {
            vector<string> curMat(n, string(n, '.'));
            //一种方案中的皇后位置
            for (pair<int, int> pos : curRet)
            {
                curMat[pos.first][pos.second] = 'Q';
            }
            allMat.push_back(curMat);
        }
        return allMat;
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int, int>>> allRet;
        vector<pair<int, int>> curRet;
        DFS(allRet, curRet, 0, n);

        return transResult(allRet, n);
    }
};

//https://leetcode.cn/problems/n-queens-ii/submissions/
class Solution {
public:
    bool isValidPos(vector<pair<int, int>>& curRet, int row, int col)
    {
        for (auto pos : curRet)
        {
            if (col == pos.second || row - col == pos.first - pos.second || row + col == pos.first + pos.second)
            {
                return false;
            }
        }
        return true;
    }
    void DFS(vector<vector<pair<int, int>>>& allRet, vector<pair<int, int>>& curRet, int curRow, int n)
    {
        if (curRow == n)
        {
            allRet.push_back(curRet);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (isValidPos(curRet, curRow, i))
            {
                curRet.push_back(make_pair(curRow, i));
                DFS(allRet, curRet, curRow + 1, n);
                curRet.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        if (n <= 0)
            return 0;

        vector<vector<pair<int, int>>> allRet;
        vector<pair<int, int>> curRet;
        DFS(allRet, curRet, 0, n);

        return allRet.size();
    }
};