#include <bits/stdc++.h>
using namespace std;
/**
 * 本题目为岛屿的数量问题的解决
 * 可以通过搜索将相邻的陆渡全部归零，然后重新扫描即可
 */

void dfs(vector<vector<char>> &grid, int i, int j)
{
    if (grid[i][j] == '0')
        return -1;
    int n = grid.size();
    int m = grid[0].size();

    grid[i][j] = '0';

    if (i - 1 >= 0)
        dfs(grid, i - 1, j);
    if (i + 1 < n)
        dfs(grid, i + 1, j);
    if (j - 1 >= 0)
        dfs(grid, i, j - 1);
    if (j + 1 < m)
        dfs(grid, i, j + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    if (n <= 0)
        return;
    int m = grid[0].size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                dfs(grid, i, j);
            }
        }
    }

    return ans;
}
int main()
{
    int n = 10;
    int m = 10;
    vector<vector<char>> grid(n, vector<char>(m, 0));
    cout << grid.size() << "  " << grid[0].size() << endl;
    return 0;
}