#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int translateNum(int num)
    {
        // 将数字字符串翻译为字母字符字符串

        // step 1: 将int类型的数据转化为字符串类型的数据
        string str = to_string(num);
        int len = str.size();

        // step 2: 动态规划 设置状态矩阵
        vector<int> dp(len + 1, 0);

        if (len == 1)
        {
            return 1;
        }
        dp[0] = 1;
        auto subStr = str.substr(0, 2);
        // 需要判断这两个能不能组成一个新的
        if (subStr >= "10" && subStr <= "25")
        {
            // 这里是个涉及到了字符串比较大小
            dp[1] = 2;
        }
        else
        {
            dp[1] = 1;
        }
        // cout<<dp[0]<<" "<<dp[1]<<endl;

        for (int i = 2; i < len; i++)
        {
            auto subStr = str.substr(i - 1, 2);
            if (subStr >= "10" && subStr <= "25")
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else
            {
                dp[i] = dp[i - 1];
            }

            // cout<<"substr:"<<subStr<<"   dp:"<<dp[i]<<endl;
        }

        return dp[len - 1];
    }
};

int main()
{
    Solution s;
    cout << s.translateNum(10);
    return 0;
}