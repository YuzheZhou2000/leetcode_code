#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        int res = s.size(); // 单个字符肯定是回文

        vector<vector<bool>> dp(res, vector<bool>(res)); // 初始化定义二维数组

        for (int i = 0; i < res; i++)
        {
            dp[i][i] = true;
        }

        for (int L = 2; L <= s.size(); L++)
        {
            for (int i = 0; i < s.size(); i++)
            {

                int j = i + L - 1;
                if (j >= s.size())
                {
                    // 右侧越界
                    break;
                }
                else
                {
                    if (s[i] == s[j])
                    {
                        if (L == 2)
                        {
                            dp[i][j] = true;
                            res++;
                        }
                        else
                        {
                            dp[i][j] = dp[i + 1][j - 1];
                            if (dp[i][j] == true)
                            {
                                res++;
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};
int main()
{
    return 0;
}