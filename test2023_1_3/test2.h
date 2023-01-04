
#include "test.h"

//https://leetcode.cn/problems/surrounded-regions/submissions/

int nextP[4][2] = { {-1, 0}, {1, 0}, {0,-1}, {0,1} };


class Solution {
public:

    void DFS(vector<vector<char>>& board, int row, int col, int curX, int curY)
    {
        //��ǵ�ǰλ��Ϊ�ͱ�����ͨ��
        board[curX][curY] = '*';
        //������λ��
        for (int i = 0; i < 4; ++i)
        {
            int newX = curX + nextP[i][0];
            int newY = curY + nextP[i][1];

            //�ж��Ƿ�Խ��
            if (newX >= row || newX < 0
                || newY >= col || newY < 0)
                continue;

            //�жϵ�ǰλ���Ƿ�Ϊ'O'
            if (board[newX][newY] == 'O')
            {
                DFS(board, row, col, newX, newY);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;

        int row = board.size();
        int col = board[0].size();

        //�����ĸ����ϵĵ�
        //��һ�к����һ��
        for (int j = 0; j < col; j++)
        {
            if (board[0][j] == 'O')
                DFS(board, row, col, 0, j);

            if (board[row - 1][j] == 'O')
                DFS(board, row, col, row - 1, j);

        }

        //��һ�к����һ��
        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O')
                DFS(board, row, col, i, 0);

            if (board[i][col - 1] == 'O')
                DFS(board, row, col, i, col - 1);

        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                if (board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};

//https://leetcode.cn/problems/number-of-islands/submissions/

int nextPosition[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
class Solution {
public:

    void DFS(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& book, int curX, int curY)
    {
        book[curX][curY] = 1;
        for (int i = 0; i < 4; ++i)
        {
            int newX = curX + nextPosition[i][0];
            int newY = curY + nextPosition[i][1];

            if (newX >= row || newX < 0
                || newY >= col || newY < 0)
                continue;
            if (grid[newX][newY] == '1' && book[newX][newY] == 0)
                DFS(grid, row, col, book, newX, newY);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> book(row, vector<int>(col, 0));
        int cnt = 0;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (book[i][j] == 0 && grid[i][j] == '1')
                {
                    ++cnt;
                    DFS(grid, row, col, book, i, j);
                }
            }
        }

        return cnt;
    }
};


//https://leetcode.cn/problems/max-area-of-island/submissions/

int nextPosition[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

class Solution {
public:

    int DFS(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& book, int curX, int curY)
    {
        book[curX][curY] = 1;
        int sum = 1;
        for (int i = 0; i < 4; ++i)
        {
            int newX = curX + nextPosition[i][0];
            int newY = curY + nextPosition[i][1];

            if (newX >= row || newX < 0
                || newY >= col || newY < 0)
                continue;

            if (grid[newX][newY] == 1 && book[newX][newY] == 0)
            {
                sum += DFS(grid, row, col, book, newX, newY);
            }
        }
        return sum;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int Max = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> book(row, vector<int>(col, 0));

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1 && book[i][j] == 0)
                {
                    Max = max(Max, DFS(grid, row, col, book, i, j));
                }
            }
        }

        return Max;

    }
};

//https://leetcode.cn/problems/letter-combinations-of-a-phone-number/submissions/

map<char, string> numMap = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
{'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };

class Solution {
public:

    void DFS(string& digits, vector<string>& allRet, string curStr, int digitIdx)
    {
        if (digitIdx == digits.size())
        {
            allRet.push_back(curStr);
            return;
        }
        //��ȡ���ֶ�Ӧ���ַ�ӳ��
        string strMap = numMap[digits[digitIdx]];
        for (char ch : strMap)
        {
            DFS(digits, allRet, curStr + ch, digitIdx + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty())
            return ret;

        DFS(digits, ret, "", 0);
        return ret;
    }
};


//https://leetcode.cn/problems/letter-tile-possibilities/

class Solution {
public:
    void DFS(string& tiles, string curStr, unordered_set<string>& allRet, vector<int>& book)
    {
        if (!curStr.empty())
        {
            allRet.insert(curStr);
        }
        //��Ǳ�֤����λ������֮���ٽ���
        for (int i = 0; i < tiles.size(); ++i)
        {
            //��ǰλ���ַ��Ѿ��ù�
            if (book[i])
                continue;

            book[i] = 1;
            DFS(tiles, curStr + tiles[i], allRet, book);
            //���ݣ����������ַ�
            book[i] = 0;

        }
    }
    int numTilePossibilities(string tiles) {
        if (tiles.empty())
            return 0;

        unordered_set<string> allRet;
        vector<int> book(tiles.size(), 0);
        DFS(tiles, "", allRet, book);

        return allRet.size();
    }
};