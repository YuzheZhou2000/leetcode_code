#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pre;
    Solution(vector<int> &w) : pre(w.size() + 1, 0)
    {
        for (int i = 1; i < pre.size(); i++)
        {
            // 生成一个区间数组，作为可以生成随机数的区间范围
            pre[i] = pre[i - 1] + w[i - 1];
            cout << "pre[i]:" << pre[i] << endl;
        }
        // 设置随机种子
        srand(time(0));
    }

    int pickIndex()
    {
        // 开始随机采样的过程
        int x = rand() % pre[pre.size() - 1] + 1; // 生成从 1 - sum 之间的随机数
        // 根据随机数开始随机命中

        int ans = help(x);
        return ans - 1;
    }
    int help(int target)
    {
        // 随机产生的随机数是target

        // 使用二分查找
        int left = 0;
        int right = pre.size();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (pre[mid] == target)
            {
                // 正好命中边界值
                return mid;
            }
            else if (pre[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{
    vector<int> res = {1, 2, 3, 4, 5};
    Solution s(res);
    s.pickIndex();
}