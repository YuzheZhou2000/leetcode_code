#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size();    // 行数
        int n = grid[0].size(); // 列数
        // step 1: 确定一个记录状态的数组
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // step 2: 确定边界状态
        // 具体来说，针对第一行和第一列分别给出对应的初始状态
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        // step 3: 开始进行转移
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] + grid[i][j] : dp[i - 1][j] + grid[i][j];
            }
        }

        // 输出最后的结果
        return dp[m - 1][n - 1];
    }
};

int main()
{
    return 0;
}