#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 直接使用动态规划超出内存限制，因此需要进行优化
    int maxSubArray_outmemery(vector<int> &nums)
    {
        // 寻找最大的连续子数字
        int res = INT_MIN;

        // 首先声明dp
        int size = nums.size();

        vector<vector<int>> dp(size, vector<int>(size));
        for (int i = 0; i < size; i++)
        {
            // 初始化边界值
            dp[i][i] = nums[i];
            res = res > nums[i] ? res : nums[i];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++){
                dp[i][j] = dp[i][j-1] + nums[j];
                res = res > dp[i][j] ? res : dp[i][j];
            }
        }
        return res;
    }

    int maxSubArray(vector<int> &nums)
    {

        // 对dp进行优化 使用dp[i]表示以i结尾的子数组的最大值
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if(nums.size() == 1){
            return dp[0];
        }
        for(int i =1; i<nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i] , nums[i]);
        }

        int max_ele = * max_element(dp.begin(), dp.end());
        return max_ele;

        
    }


};

int main()
{
    vector<int> dp  = {-2,1,-3,4,-1,2,1,-5,4};
    int max_ele = * max_element(dp.begin(), dp.end());
    cout<< max_ele;
    return 0;
}