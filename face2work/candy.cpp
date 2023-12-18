#include <bits/stdc++.h>
using namespace std;
/**
 * 分糖果
 * 前后分别遍历
 * 贪心算法
 */
int candy(vector<int> &ratings)
{
    int size = ratings.size();
    if (size <= 1)
        return size;
    vector<int> vec(size, 1);
    for (int i = 1; i < size; i++)
    {
        if (ratings[i] > ratings[i - 1])
            vec[i] = vec[i - 1] + 1;
    }
    for (int i = size - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            vec[i] = max(vec[i], vec[i + 1] + 1);
        }
    }
    int ans = 0;
    for (auto &i : vec)
    {
        ans += i;
    }
    return ans;
}

int main()
{
    return 0;
}