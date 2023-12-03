#include <bits/stdc++.h>
using namespace std;
/**
 * 求最小的K个数
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param input int整型vector
     * @param k int整型
     * @return int整型vector
     */
    vector<int> GetLeastNumbers_Solution(vector<int> &input, int k)
    {
        // write code here
        // 要求空复杂度为O(n) 时间复杂度为O(nlogk)
        // 因此考虑使用最大堆,堆顶保留最大的元素

        vector<int> ans;
        priority_queue<int> que;
        for (auto &i : input)
        {
            if (que.size() < k)
            {
                que.emplace(i);
            }
            else
            {
                if (!que.empty())
                {
                    if (que.top() > i)
                    {
                        que.pop();
                        que.emplace(i);
                    }
                }
            }
        }
        while (!que.empty())
        {
            ans.push_back(que.top());
            que.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    priority_queue<int> que;
    que.emplace(100);
    que.emplace(10);
    que.emplace(9);

    for (auto &i : que)
    {
        cout << i << "   ";
    }

    return 0;
}