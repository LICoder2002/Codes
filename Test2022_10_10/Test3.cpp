//求最大公共字串长度

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int getNum(string& s1, string& s2)
{
    int row = s1.size();
    int col = s2.size();

    vector<vector<int>> arr(row, vector<int>(col, 0));

    int count = 0;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (s1[i] == s2[j])
            {
                if (i == 0 || j == 0)
                {
                    arr[i][j] = 1;
                }
                else
                {
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                }
            }
            count = max(count, arr[i][j]);
        }
    }
    return count;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int res = getNum(s1, s2);

    cout << res << endl;

    return 0;
}