#include <bits/stdc++.h>
using namespace std;
/**
 * 本题目为基础动态规划类题目
 * 首先可以根据题目知道，需要求解的就是到了右下角以后的数字的值
 * 那么这个时候  需要做的就i是根据上面和左边两个不同位置的元素，求一个最小值，根据这个最小的值
 * 去判断到底属于是哪一个
 * 可以在原数组上进行修改，这样就不需要开辟新的数据空间了
 */
int minPathSum(vector<vector<int>> &res)
{
    if (res.size() == 0 || res[0].size() == 0)
    {
        return -1;
    }
    // 边界值
    for (int i = 1; i < res.size(); i++)
    {
        res[i][0] += res[i - 1][0];
    }
    for (int i = 1; i < res[0].size(); i++)
    {
        res[0][i] += res[0][i - 1];
    }
    for (int i = 1; i < res.size(); i++)
    {
        for (int j = 1; j < res[0].size(); j++)
        {
            res[i][j] = res[i][j] + min(res[i][j - 1], res[i - 1][j]);
        }
    }
    return res[res.size() - 1][res[0].size() - 1];
}

int main()
{
    vector<vector<int>> vecs(4, vector<int>(4, 0));
    vecs[0] = {1, 3, 5, 9};
    vecs[1] = {8, 1, 3, 4};
    vecs[2] = {8, 7, 5, 3};
    vecs[3] = {1, 1, 2, 3};

    cout << vecs[0][1] << endl;
    cout << vecs.size() << "  " << vecs[0].size() << endl;
    int ans = minPathSum(vecs);
    cout << "ans: " << ans << endl;
    return 0;
}