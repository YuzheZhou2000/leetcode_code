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
/**
 * 看到面经里有的面试希望可以优化到nlogn
 * 尽管我们想到的使用两个指针的方法可以直接变成n
 * 但是估计这里就是考察对二分查找的理解吧
 * 1. 首先计算一个前n-1数组的前缀和
 * 2. 遍历，对于每一个index下的元素，让他加上前面的 得到的是本身+前缀
 * 3. 二分找到最后比2的和+target还小的第一个index 做差
 * 这里可以的依据： 前缀和一定是一个递增的数列
 * 因此可以使用二分查找进行计算。
 */