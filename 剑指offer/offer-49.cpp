#include <bits/stdc++.h>

using namespace std;

/*
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
*/
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        // 通过学习题解 我们使用最小堆来解决本问题。
        int ans = -1;

        // 首先 申请一个最小堆、根据最小堆的性质，堆顶的元素就是当前最小的元素
        priority_queue<long, vector<long>, greater<long>> minHeap;
        minHeap.push(1L);

        // 只包含质因子 2，3，5
        vector<int> factors = {2, 3, 5};

        // 每一次重新插入和时候，不能存在之前已经有的值
        unordered_set<int> mySet;
        mySet.insert(1L);

        for (int i = 0; i < n; i++)
        {
            long curr = minHeap.top(); // 当前堆中最小的一个元素
            ans = int(curr);           // 此时表示最小的这个丑数
            minHeap.pop();             // 将当前元素从堆中删除

            // 开始更新
            for (auto factor : factors)
            {
                long temVal = factor * curr;
                if (mySet.count(temVal) == 0)
                {
                    minHeap.push(temVal);
                    mySet.insert(temVal);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << "ans: " << s.nthUglyNumber(1);
    return 0;
}