#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // // 因为题目中要求直接统计target在数组中的出现次数，因此直接遍历匹配
    // int search(vector<int> &nums, int target)
    // {
    //     int len = nums.size();
    //     if (len <= 0 || target < nums[0] || target > nums[len - 1])
    //     {
    //         return 0;
    //     }

    //     int ans = 0;

    //     for (int i = 0; i < len; i++)
    //     {
    //         if (nums[i] == target)
    //         {
    //             ans++;
    //         }
    //     }

    //     return ans;
    // }
    // 但是题目中给出数组numss是一个有序数组，因此考虑使用二分查找降低时间复杂度
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        int ans = 0;
        int left = 0;
        int right = len - 1;
        while (right >= left) // 二分查找的结束条件
        {
            int midIdx = left + (right - left) / 2;
            cout << "midIdx: " << midIdx << " left: " << left << " right: " << right << endl;
            if (nums[midIdx] == target)
            {
                // 找到了！！
                for (int i = midIdx; (i < len && nums[i] == target); i++)
                {
                    ans++;
                }
                for (int i = midIdx - 1; (i > -1 && nums[i] == target); i--)
                {
                    ans++;
                }
                break;
            }
            else if (nums[midIdx] > target)
            {
                right = midIdx - 1;
            }
            else
            {
                left = midIdx + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 5;
    cout << "ans: " << s.search(nums, target);
    return 0;
}