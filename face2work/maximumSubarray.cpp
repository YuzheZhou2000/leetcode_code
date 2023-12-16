#include <bits/stdc++.h>
using namespace std;
/**
 * 最大子数组的和
 * 使用动态规划解决即可
 */
int maxSubArray(vector<int> &nums)
{
    int size = nums.size();
    if (size <= 0)
        return -1;
    int maxVal = nums[0];
    for (int i = 1; i < size; i++)
    {
        nums[i] = max(nums[i], nums[i - 1] + nums[i]);
        if (nums[i] > maxVal)
            maxVal = nums[i];
    }
    return maxVal;
}
int main()
{
    vector<int> vec = {5, 4, -1, 7, 8};
    int ans = maxSubArray(vec);
    cout << "ans: " << ans;
    return 0;
}