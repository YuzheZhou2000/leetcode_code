#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // 因为数组是排序好的数组，且每一个数子唯一。
        // 因此我们可以得出结论，在目标值左边的都是合规的反之是不合规的
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while (right >= left)
        {
            int midIdx = left + (right - left) / 2;
            if (nums[midIdx] == midIdx)
            {
                // 目标结果在midIdx的右边
                left = midIdx + 1;
            }
            else
            {
                // 目标结果为midIdx或者其左边
                right = midIdx - 1;
            }
        }
        return left;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 9};
    cout << "ans: " << s.missingNumber(nums);
    return 0;
}
