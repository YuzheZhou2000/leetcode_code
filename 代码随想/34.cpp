#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> searchRange_v0(vector<int> &nums, int target)
    {
        vector<int> ans = {-1, -1};
        int star = 0;
        int end = nums.size() - 1;
        int mid = -1;
        while (end >= star)
        {
            mid = star + (end - star) / 2;
            if (nums[mid] == target)
            {
                // find the target
                // 在写两个循环的时候，一定要注意的就是短路问题，可能会造成内存的溢出
                // 使用这种解法 会造成时间复杂度最坏的情况下变成时间复杂度为O(n)
                for (int i = mid; i >= 0 && nums[i] == target; i--)
                {
                    ans[0] = i;
                }
                for (int i = mid; i < nums.size() && nums[i] == target; i++)
                {
                    ans[1] = i;
                }
                return ans;
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
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        // 因为对时间复杂度有了新的要求
        // 因此使用二分查找分别定位相同序列的边界
        int left = get_left(nums, target);
        int right = get_right(nums, target);
        vector<int> ans = {-1, -1};
        int len = nums.size() - 1;
        if (left == -2 || right == -2 || abs(right - left) == 1)
        {
            return ans;
        }
        ans[0] = left + 1;
        ans[1] = right - 1;
        return ans;
    }
    int get_left(vector<int> &nums, int target)
    {
        int ans = -2;
        int star = 0;
        int end = nums.size() - 1;
        int mid = -1;
        while (end >= star)
        {
            mid = star + (end - star) / 2;
            if (nums[mid] >= target)
            {
                end = mid - 1;
                ans = end;
            }
            else
            {
                star = mid + 1;
            }
        }
        return ans;
    }
    int get_right(vector<int> &nums, int target)
    {
        int ans = -2;
        int star = 0;
        int end = nums.size() - 1;
        int mid = -1;
        while (end >= star)
        {
            mid = star + (end - star) / 2;
            if (nums[mid] <= target)
            {
                star = mid + 1;
                ans = star;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 4, 4, 4, 4, 4};
    int target = 4;
    Solution s;
    vector<int> ans = s.searchRange_v2(nums, target);
    for (auto &num : ans)
    {
        cout << num << " ";
    }
    // int left = s.get_left(nums, target);
    // int right = s.get_right(nums, target);
    // cout << "left: " << left;
    // cout << " right: " << right;
    return 0;
}