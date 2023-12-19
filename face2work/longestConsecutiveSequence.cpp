#include <bits/stdc++.h>
using namespace std;
/**
 * 最长的连续序列长度
 * 这道题目最大的坑在于可能存在相同的元素
 * 这时候需要根据上一个的状态将当前状态复制
 */
int longestConsecutive(vector<int> &nums)
{
    // 首先进行排序
    sort(nums.begin(), nums.end());
    int size = nums.size();
    if (size <= 1)
        return size;
    vector<int> tem(size, 1);
    int ans = 1;
    for (int i = 1; i < size; i++)
    {
        if (nums[i] == nums[i - 1] + 1)
        {
            tem[i] = tem[i - 1] + 1;
            ans = max(ans, tem[i]);
        }
        if (nums[i] == nums[i - 1])
        {
            tem[i] = tem[i - 1];
        }
    }
    return ans;
}
int main()
{
    vector<int> vec = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int ans = longestConsecutive(vec);
    cout << "ans: " << ans << endl;
    return 0;
}