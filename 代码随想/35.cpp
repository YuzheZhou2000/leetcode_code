#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 首先使用二分查找寻找是不是可以找得到
        int star = 0;
        int end = nums.size() - 1;
        int mid = -1;
        while (end >= star)
        {
            mid = star + (end - star) / 2;
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
        if (nums[mid] > target)
        {
            return mid;
        }
        else
        {
            return mid + 1;
        }
    }
};

int main()
{
    vector<int> nums = {1, 4, 5, 6, 8};
    int target = 0;
    Solution s;
    int ans = s.searchInsert(nums, target);
    cout << "ans: " << ans << endl;
    return 0;
}