#include <bits/stdc++.h>
using namespace std;

/**
 * 快速排序算法
 * 1. 使用递归的写法
 *      首先递归  得到排序和中间锚点位置
 * 2. 根据中间锚点位置，分为两部分重新递归 得到最后的结果
 * 3. 在递归过程中，while循环分别遍历
 */
int kuaisu(vector<int> &vec, int star, int end)
{
    int flag = vec[star]; // 作为本次调整的锚点
    while (star < end)
    {
        while (star < end && vec[end] >= flag)
        {
            end--;
        }
        // 从右向左找到了比锚点小的数字，替换
        vec[star] = vec[end];
        while (star < end && vec[star] < flag)
        {
            star++;
        }
        // 找到了比锚点大的数字
        vec[end] = vec[star];
    }
    vec[end] = flag;
    // 最初的那个元素复制

    return end;
}
void fastSort(vector<int> &vec, int star, int end)
{
    // 递归结束条件
    if (star >= end)
        return;
    int index = kuaisu(vec, star, end);
    kuaisu(vec, star, index - 1);
    kuaisu(vec, index + 1, end);
}

int main()
{
    vector<int> vec = {30, 21, 4, 33, 7, 9, 9, 120};
    cout << "source: ";
    for (auto &i : vec)
    {
        cout << i << "  ";
    }

    cout << endl;
    fastSort(vec, 0, vec.size() - 1);

    cout << "sort: ";
    for (auto &i : vec)
    {
        cout << i << "  ";
    }
}