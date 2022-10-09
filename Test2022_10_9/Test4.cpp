//找两个字符串的公共字串
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;


    if (s1.size() > s2.size())
    {
        swap(s1, s2);
    }

    int row = s1.size();
    int col = s2.size();
    int pos = 0;
    int count = 0;
    vector<vector<int>> arr(row, vector<int>(col, 0));

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
            if (arr[i][j] > count)
            {
                count = arr[i][j];
                pos = i - count + 1;
            }
        }
    }

    cout << s1.substr(pos, count) << endl;
    return 0;

}