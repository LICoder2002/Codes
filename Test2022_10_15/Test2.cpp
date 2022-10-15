#include<iostream>
#include<vector>
using namespace std;

int m = 0, n = 0;
vector<pair<int, int> > now_path;
void findPath(vector<vector<int>>& arr, int x, int y, vector<pair<int, int>>& res)
{
    arr[x][y] = 1;
    now_path.push_back(make_pair(x, y));
    if (x == m - 1 && y == n - 1)
    {
        if (res.empty() || res.size() > now_path.size())
        {
            res = now_path;
        }
    }
    else
    {
        if (x < m - 1 && arr[x + 1][y] == 0)
            findPath(arr, x + 1, y, res);

        if (x >= 1 && arr[x - 1][y] == 0)
            findPath(arr, x - 1, y, res);

        if (y < n - 1 && arr[x][y + 1] == 0)
            findPath(arr, x, y + 1, res);

        if (y >= 1 && arr[x][y - 1] == 0)
            findPath(arr, x, y - 1, res);
    }
    arr[x][y] = 0;
    now_path.pop_back();

}

int main()
{
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    }

    vector<pair<int, int> > res;
    now_path.clear();
    findPath(arr, 0, 0, res);

    for (auto& e : res)
    {
        cout << "(" << e.first << "," << e.second << ")" << endl;
    }

    return 0;
}