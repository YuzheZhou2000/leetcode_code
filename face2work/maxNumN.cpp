#include <bits/stdc++.h>
using namespace std;

/**
 * 小于n的最大的数
 */

bool dfs(vector<int> &vec, vector<int> &nums, vector<int> &vecAns, int index, bool flag)
{
    /**
     * vec: 候选的字符集  单调递减
     * nums: 切割以后每一个数位上的值
     * vecAns: 存放的结果值
     * index：目标索引
     * flag : 是不是可以直接往后面压入候选集合最大了
     */
    // 匹配当前index位置上的元素的值

    if (index == nums.size())
        return true;
    if (flag)
    {
        // 直接压入最大的 然后index游标后移，一直循环到最后就可以了
        vecAns.push_back(vec[vec.size() - 1]);
        return dfs(vec, nums, vecAns, index + 1, true);
    }
    else
    {
        // 如果不是，那么就需要一个比较
        // 比较什么呢。比较是正好相等，还是之前有过比他大的了
        int tem = nums[index];
        for (int i = 0; i < vec.size(); i++)
        {
            // 这个循环的目的就是为了看
            if (tem == vec[i])
            {
                // 当前的值和原来的值是一样的
                vecAns.push_back(vec[i]);
                if (dfs(vec, nums, vecAns, index + 1, false))
                    return true;
                else
                    // 如果返回了false 那么就说后面的存在都打了
                    vecAns.pop_back();
            }
            else if (tem > vec[i])
            {
                // 以后全部是最小的元素
                vecAns.push_back(vec[i]);
                if (dfs(vec, nums, vecAns, index + 1, true))
                    return true;
                else
                    vecAns.pop_back();
            }
        }
        // 数组中最小的元素都大于数字该位的值
        if (index != 0)
            return false;
        else
            // 少了一位,直接放最大的
            return dfs(vec, nums, vecAns, index + 1, true);
    }
}

int maxNum(vector<int> vec, int target)
{
    int ans = 0;
    if (vec.size() == 0 || target <= 0)
        return ans;

    // 首先做一个分割，把target中的每一位都分割出来
    vector<int> nums;
    while (target)
    {
        int tem = target % 10;
        nums.emplace_back(tem);
        target = target / 10;
    }
    reverse(nums.begin(), nums.end());

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    // 下面开始使用递归的方法解决本问题
    vector<int> vecAns;
    dfs(vec, nums, vecAns, 0, false);

    for (int i = 0; i < vecAns.size(); i++)
    {
        ans = ans * 10 + vecAns[i];
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 4, 6, 8, 9};
    int target = 803;
    int ans = maxNum(nums, target);
    cout << "ans: " << ans << endl;
    return 0;
}