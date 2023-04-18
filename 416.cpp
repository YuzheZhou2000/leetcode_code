#include <bits/stdc++.h>

using namespace std;
class Solution
{

public:
    bool canPartition(vector<int> &nums)
    {
        // 判断是否可以等分数组，如果等分，每一个子集的和都为原来的1/2

        int len = nums.size();
        if (len < 2)
        {
            // 对于一个长度小于2的数组，不可能继续划分出两个等和的数组
            return false;
        }
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        int targetSum = sum / 2;
        // 此时题目转化为查找是否存在和为targetSum 的子集 0−1 背包问题  0-1问题  使用动态规划的方法求解
        // 定义动态方程的数组 len * target+1 , dp[i][j]表示从数组nums的0~i个元素中，是否存在组合的和，为j
        vector<vector<bool>> dp(len, vector<bool>(targetSum + 1, false));

        // 初始化动态方程
        // for dp[0][~]只有当值为nums[0]的数中为true
        // 这里要保证最大的元素小于整体和的一半
        int maxEle = *max_element(nums.begin(), nums.end());
        if (maxEle > targetSum)
        {
            return false;
        }
        dp[0][nums[0]] = true;

        // for dp[~][0] 只要不选择，就是0 故全部为true
        for (int i = 0; i < len; i++)
        {
            dp[i][0] = true;
        }

        // 开始转移方程
        for (int i = 1; i < len; i++)
        {
            for (int j = 1; j < targetSum + 1; j++)
            {
                if(nums[i] >j){
                    // j表示当前待比较的和，如果nums[i]大于j ，nums[i]肯定不能选择
                    dp[i][j] = dp[i-1][j];
                }else{
                    // 可以选择当前nums[i]
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]];
                }
                
            }
        }
        return dp[len-1][targetSum];
    }
};

int main()
{
    bool tem = true || false;
    cout<<tem<<endl;
    return 0;
}