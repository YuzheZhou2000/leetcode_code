#include <bits/stdc++.h>
using namespace std;
/**
 * 组合总和2： https://leetcode.cn/problems/4sjJUc/
 * 在这个题目中 不可以重复出现在结果序列中的
 * 也就是说在结果中每一个元素在一个combine中只能出现一次
 * 我们使用递归解法来解决本题目
 */

void mySum(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &combine,
           int target, int index, int sum)
{
    // 下面开始实际的业务逻辑
    if (index > candidates.size())
    {
        // 越界啦
        return;
    }

    if (sum > target)
    {
        return;
    }
    if (sum == target)
    {
        ans.emplace_back(combine);
        return;
    }
    // 不使用这一个
    mySum(candidates, ans, combine, target, index + 1, sum);

    // 使用这一个
    combine.push_back(candidates[index]);
    mySum(candidates, ans, combine, target, index + 1, sum + candidates[index]);
    combine.pop_back();
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    if (candidates.size() <= 0)
        return ans;
    vector<int> combin;

    mySum(candidates, ans, combin, target, 0, 0);

    unordered_set<vector<int>> myset;
    for (int i = 0; i < ans.size(); i++)
    {
        myset.insert(ans[i]);
    }
    // ans.clear();
    // for (auto &i : myset)
    // {
    //     ans.emplace_back(i);
    // }

    return ans;
}
int main()
{
    vector<int> candidates = {2, 2, 3, 4, 7};

    vector<vector<int>> ans = combinationSum2(candidates, 7);
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