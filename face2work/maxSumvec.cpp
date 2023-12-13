#include <bits/stdc++.h>
using namespace std;
/**
 * 最大的子数组的和
 * 可以直接在原来的数组上进行修改
 * 属于是简单类型的题目
 *
 */
int MaxsumSubvec(vector<int> &vec)
{
    if (vec.size() <= 0)
    {
        return -1;
    }
    if (vec.size() == 1)
    {
        return vec[0];
    }
    for (int i = 1; i < vec.size(); i++)
    {
        vec[i] = max(vec[i], vec[i] + vec[i - 1]);
    }
    return vec[vec.size() - 1];
}
int main()
{
    vector<int> vec = {1, 2, -4, 6, -5, 7};
    int res = MaxsumSubvec(vec);
    cout << "res: " << res;

    return 0;
}