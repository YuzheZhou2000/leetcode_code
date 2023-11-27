#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

/*
- 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
- 时间复杂度要求O(n)
*/
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // 由于需要遍历数组确定是否存在当前元素，因此首先使用集合set存储原来得元素
        unordered_set<int> numsSet;
        for (const int &num : nums)
        {
            numsSet.insert(num);
        }

        int longest = 0;

        // 开始遍历原来数组，寻找最长连续字串
        for (const int &num : nums)
        {

            // 为了降低时间复杂度，采用优化，如果数组中存在前驱，则直接跳过
            // （因为他的前驱引导的最长序列一定更长）
            if (numsSet.count(num - 1))
            {
                // 如果存在，则直接跳过
                continue;
            }
            // 开始向后查找存在的元素
            int curr_num = num + 1;
            int curr_len = 1;
            while (numsSet.count(curr_num))
            {
                // 向后遍历寻找
                curr_len += 1;
                curr_num += 1;
            }
            // 判断是不是当前最长
            longest = max(curr_len, longest);
        }

        return longest;
    }
};

int main()
{
    vector<int> test = {1, 2, 2, 5, 777, 33};
    Solution s;
    unordered_set<int> tesSet;
    int a = 1;
    cout << tesSet.count(2);

    return 0;
}