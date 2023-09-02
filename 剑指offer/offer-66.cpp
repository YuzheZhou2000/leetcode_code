#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        // 首先构造左右数组，用于存储索引位n的元素中的对应值
        int len = a.size();
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        if (len == 0)
        {
            return a;
        }
        if (a[0] != 0)
        {
            left[0] = 1;
        }
        if (a[len - 1] != 0)
        {
            right[len - 1] = 1;
        }
        for (int i = 1; i < len; i++)
        {
            left[i] = left[i - 1] * a[i - 1];
        }
        for (int i = len - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * a[i + 1];
        }
        vector<int> ans(len);
        for (int i = 0; i < len; i++)
        {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
int main()
{
    return 0;
}