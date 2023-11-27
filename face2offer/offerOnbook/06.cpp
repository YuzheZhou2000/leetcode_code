#include <bits/stdc++.h>
using namespace std;
/**
 * 寻找旋转数组中最小的元素
 * 注意并没有说数组中的元素是唯一的
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberInRotateArray(vector<int> &nums)
    {
        // write code here
        /**
         * 首先本题目作为一个二分查找的题目，由于说明了在旋转前是一个'非降序'数组
         * 那么就是说存在相同的情况
         *
         */
        int left = 0, right = nums.size() - 1;
        if (right == 0)
        {
            return 0;
        }
        while (left + 1 < right)
        {
            // 使用二分查找， 断开的条件为left和right是相邻的两个
            // 这时候只需要返回两个中的最小值就可以了
            // 但是需要注意的是left和right都不可以越界

            // 二分查找标配吗，计算中间点的索引
            int mid = left + (right - left) / 2;

            // 针对旋转数组的判断，需要定位到最小的元素
            if (nums[mid] < nums[right])
            {
                // 中间mid的索引落在了旋转以后的这个子序列上
                right = mid;
            }
            else if (nums[mid] == nums[right])
            {
                // 中间的位置和子区间右边的节点
                right--;
            }
            else
            {
                left = mid + 1;
            }
        }

        return min(nums[left], nums[right]);
    }
};

int main()
{
    vector<int> vec = {1, 0};
    Solution s;
    int ans = s.minNumberInRotateArray(vec);
    cout << "ans " << ans << endl;

    return 0;
}