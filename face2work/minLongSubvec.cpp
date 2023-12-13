#include <bits/stdc++.h>
using namespace std;
/**
 * 长度最小的子数组
 */
int minLongSubvec(vector<int> &nums, int target)
{

    if (nums.size() <= 0)
    {
        return -1;
    }

    int sum = 0, left = 0, right = 0, ans = INT_MAX, size = nums.size();

    while (right < size)
    {
        // 向左边移动一个位置
        sum += nums[right];
        while (sum >= target)
        {
            // 出现了 大的情况  直接计算结果i
            ans = min(ans, right - left + 1);
            // 然后建一个 右指针移动
            sum -= nums[left];
            left++;
        }
        right++;
    }

    return ans == INT_MAX ? 0 : ans;
}
int main()
{
    vector<int> vec = {2, 3, 1, 2, 4, 3};
    int res = minLongSubvec(vec, 7);
    cout << "res: " << res;

    return 0;
}