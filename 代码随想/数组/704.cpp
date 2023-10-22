#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int ans = 0;
        // for (auto &num : nums)
        // {
        //     cout << num << " " << endl;
        // }
        int star = 0;
        int end = nums.size() - 1;

        while (end >= star)
        {
            // 这里使用的是>=符号，这就决定了target再这个区间内
            // 是一个闭区间。那么这个就说明在选择区间的时候，需要-1或者+1
            // 跳开mid这个下标
            /* code */
            int mid = star + (end - star) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                star = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 12;
    Solution s;
    int ans = s.search(nums, target);
    cout << "res:" << ans << endl;
    return 0;
}