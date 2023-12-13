#include <bits/stdc++.h>
using namespace std;
/**
 * 最长公共子串问题
 * 使用动态规划，这个需要知道的是动态方程到底是一个什么样子的
 * dp[i][j] = dp[i-1][j-1] +1
 * 动态方程是这个题的核心思想
 */
string longestString(string &s1, string &s2)
{
    string ans;
    if (s1.size() == 0 || s2.size() == 0)
        return ans;
    int n = s1.size();
    int m = s2.size();
    cout << "s1.size: " << n << " s2.size: " << m << endl;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int longest = -1;
    int star = 0, end = 0;
    // 在这个最长公共子序列中，后一个的状态和前一个的i-1，j-1是有关系的
    for (int i = 0; i < m; i++)
    {
        if (s2[i] == s1[0])
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[0])
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (s1[j] == s2[i])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] >= longest)
                {
                    longest = dp[i][j];
                    end = j;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << "longest: " << longest << endl;
    star = end - longest + 1;
    ans = s1.substr(star, longest);
    return ans;
}
int main()
{
    string s1 = "asf1111dwezhouyuzhe2132r321r";
    string s2 = "222zhouyuzhe11qewqe111";
    string ans = longestString(s1, s2);
    cout << "ans string: " << ans << endl;
}