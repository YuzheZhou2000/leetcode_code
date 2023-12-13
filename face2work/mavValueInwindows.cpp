#include <bits/stdc++.h>
using namespace std;
/**
 * 滑动窗口中的最大值
 * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
 * 你只可以看到在滑动窗口 k 内的数字。滑动窗口每次只向右移动一位。
 * 返回滑动窗口最大值。
 * 在线性时间复杂度内解决此题
 *
 * 解决本题目的关键在于使用这个优先队列 但是这个优先队列是由两个值组成的
 */
vector<int> maxValinWindows(vector<int> &vec, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int>> que;
    int size = vec.size();
    if (size < k)
        return ans;
    for (int i = 0; i < k; i++)
    {
        que.emplace(vec[i], i);
    }
    ans.push_back(que.top().first);

    for (int i = k; i < size; i++)
    {
        que.emplace(vec[i], i);
        while (que.top().second <= i - k)
        {
            que.pop();
        }
        ans.push_back(que.top().first);
    }
    return ans;
}
int main()
{
    vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> res = maxValinWindows(vec, 3);
    cout << "ans: ";
    for (auto &i : res)
    {
        cout << i << " ";
    }

    return 0;
}