#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型
     */
    int FindGreatestSumOfSubArray_v0(vector<int> &array)
    {
        // write code here
        int ans = INT_MIN;
        int size = array.size();
        vector<int> dp(size);
        if (array.size() < 1)
        {
            return ans;
        }
        // dp[0] = array[0];
        ans = max(array[0], ans);
        for (int i = 1; i < size; i++)
        {
            dp[i] = max(dp[i - 1] + array[i], array[i]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
    int FindGreatestSumOfSubArray_v1(vector<int> &array)
    {
        // write code here
        int ans = INT_MIN, maxNum = INT_MIN;
        int size = array.size();
        if (array.size() < 1)
        {
            return ans;
        }
        // dp[0] = array[0];
        // ans = max(array[0], ans);
        maxNum = array[0];
        ans = max(maxNum, ans);
        for (int i = 1; i < size; i++)
        {
            if (maxNum + array[i] > maxNum)
            {
                maxNum = maxNum + array[i];
            }
            else
            {
                maxNum = array[i];
            }
            ans = max(maxNum, ans);
        }
        return ans;
    }
    int FindGreatestSumOfSubArray(vector<int> &array)
    {
        // write code here
        int ans = INT_MIN;
        int size = array.size();
        if (array.size() < 1)
        {
            return ans;
        }
        // dp[0] = array[0];
        ans = max(array[0], ans);
        for (int i = 1; i < size; i++)
        {
            array[i] = max(array[i - 1] + array[i], array[i]);
            ans = max(array[i], ans);
        }
        return ans;
    }
};
int main()
{
    vector<int> dp = {1, 2, 3, 45, 6, 7, 43, 3, 23};

    Solution s;
    int ans = s.FindGreatestSumOfSubArray(dp);
    cout << ans;

    return 0;
}