#include <bits/stdc++.h>
using namespace std;
/**
 * 组合总和： https://leetcode.cn/problems/combination-sum/description/
 * 在这个题目中 数字是可以重复出现的
 * 我们使用递归解法来解决本题目
 */

// 通过递归实现
void mySum(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &combine, int target, int sum, int index)
{
    if (index >= candidates.size())
    {
        // 已经发生越界了  直接终止把
        return;
    }

    if (sum == target)
    {
        // 找到了
        ans.emplace_back(combine);

        return;
    }
    // 当前遍历是到了index， 那么我们如果不要这个元素，那么直接换到下一个元素上来
    mySum(candidates, ans, combine, target, sum, index + 1);

    // 那么肯定也得考虑要这个元素，如果是要这个元素，那么需要直到要这个元素的是不是满足条件，
    // 也就是两个数的和加起来有没有超过target

    if (sum + candidates[index] <= target)
    {
        // 可以要
        combine.emplace_back(candidates[index]);
        // 需要考虑重复的情况哇 所以最后index 没有 +1
        mySum(candidates, ans, combine, target, sum + candidates[index], index);
        combine.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;

    // 首先把边界值处理了
    if (candidates.size() <= 0)
        return ans;

    vector<int> combines; // 作为中间变量出现

    mySum(candidates, ans, combines, target, 0, 0);

    return ans;
}
int main()
{
    vector<int> candidates = {2, 3, 4, 7};

    vector<vector<int>> ans = combinationSum(candidates, 7);
    for (auto &row : ans)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}