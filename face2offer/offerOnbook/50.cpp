#include <bits/stdc++.h>
using namespace std;
/**
 * 构建乘积数组
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A int整型vector
     * @return int整型vector
     */
    vector<int> multiply(vector<int> &A)
    {
        // write code here
        vector<int> ans(A.size());
        if (A.size() <= 0)
        {
            return ans;
        }
        // 首先从左向右算一遍啦
        ans[0] = 1;
        for (int i = 1; i < A.size(); i++)
        {
            // 这时候ans[i]中保存了i左边值
            ans[i] = ans[i - 1] * A[i - 1];
        }
        // 继续从右向左计算
        int right = 1;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * right;
            right = right * A[i];
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {100, 50};
    vector<int> ans = s.multiply(vec);
    for (auto &i : ans)
    {
        cout << i << "  ";
    }
    return 0;
}