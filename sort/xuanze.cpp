#include <bits/stdc++.h>
using namespace std;
/**
 * 简单选择排序
 * 两层遍历
 * 首先外层遍历确定每一个需要改变的元素
 * 内层遍历从这个元素之外开始走起 每一次选择当前序列中最值所在的位置
 * 完成一次内层遍历， 交换两个位置
 * 直到完成整体遍历 结束工作
 */
void xuanze(vector<int> &vec)
{
    if (vec.empty())
        return;

    for (int i = 0; i < vec.size(); i++)
    {
        int index = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[index])
                index = j;
        }
        int tem = vec[index];
        vec[index] = vec[i];
        vec[i] = tem;
    }

    return;
}

int main()
{
    vector<int> vec = {1, 21, 4, 33, 7, 2, 9, 120};
    xuanze(vec);
    cout << "xuanze sort: ";
    for (auto &i : vec)
    {
        cout << i << "  ";
    }
}