#include <bits/stdc++.h>

using namespace std;

/*
地上有一个m行n列的方格,从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动,它每次可以向左、右、上、下移动一格（不能移动到方格外）,也不能进入行坐标和列坐标的数位之和大于k的格子。
例如,当k为18时,机器人能够进入方格 [35, 37] ,因为3+5+3+7=18。但它不能进入方格 [35, 38],因为3+5+3+8=19。请问该机器人能够到达多少个格子

*/

class Solution
{
public:
    int getK(int num)
    {
        // 获得每一个数位上的和
        int k = 0;
        while (num != 0)
        {
            k += num % 10;
            num = num / 10;
        }
        return k;
    }
    int movingCount(int m, int n, int k)
    {
        // 使用深度优先遍历解决问题
        // 添加visit数组表示是否之前访问过
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        check(visited, m, n, res, 0, 0, k);

        return res;
    }
    void check(vector<vector<bool>> &visited, int m, int n, int &res, int i, int j, int k)
    {
        if (visited[i][j] == true)
        {
            // 之前访问过 直接跳过
            return;
        }
        int all = getK(i) + getK(j);
        if (all > k)
        {
            visited[i][j] = true;
            return;
        }
        res++;
        visited[i][j] = true;
        // 继续遍历其他
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto &dir : directions)
        {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < m && newj >= 0 && newj < n)
            {
                check(visited, m, n, res, newi, newj, k);
            }
        }
        return;
    }
};

int main()
{
    Solution s;
    int res = s.movingCount(2, 3, 1);
    cout << res << endl;
    return 0;
}