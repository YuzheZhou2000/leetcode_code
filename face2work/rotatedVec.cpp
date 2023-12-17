#include <bits/stdc++.h>
using namespace std;
/**
 * 旋转数组
 */
int search(vector<int> &nums, int target)
{
    // 因为是一个旋转数组，但是也是排序数组
    // 因此我们需要做的就是利用二分查找
    // 通过二分查找将时间复杂度降下来

    int size = nums.size();
    if (size <= 0)
        return -1;
    if (size == 1)
    {
        if (nums[0] == target)
            return 0;
        else
            return -1;
    }
    int star = 0;
    int end = nums.size() - 1;

    while (star <= end)
    {
        int mid = star + (end - star) / 2;
        cout << "mid: " << mid << endl;

        if (nums[mid] == target)
            return mid;

        // 因为不是一个正经的排序数组，因此需要首先判断两边之间是不是一个有序的数组

        if (nums[star] <= nums[mid])
        {
            // 左边是一个排序的完整数组
            if (nums[mid] > target && nums[star] <= target)
            {
                // 中间的比目标值小
                end = mid - 1;
            }
            else
            {
                star = mid + 1;
            }
        }
        else
        {
            // 右边的是一个排序的完整数组
            if (nums[mid] < target && nums[end] >= target)
            {
                star = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}
int main()
{
    vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
    int ans = search(vec, 0);
    cout << "ans : " << ans;
    return 0;
}