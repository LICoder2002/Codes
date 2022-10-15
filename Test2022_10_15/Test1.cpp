//牛客网——年终奖
#include<iostream>
#include<vector>
using namespace std;

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here

        int row = board.size();
        int col = board[0].size();

        //第一行
        for (int i = 1; i < col; ++i)
            board[0][i] += board[0][i - 1];

        //第一列
        for (int i = 1; i < row; ++i)
            board[i][0] += board[i - 1][0];

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; j++)
            {
                board[i][j] += max(board[i - 1][j], board[i][j - 1]);
            }
        }

        return board[row - 1][col - 1];
    }
};