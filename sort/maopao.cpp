#include <bits/stdc++.h>

using namespace std;

void maopao(vector<int> &vec)
{
    /**
     * 冒泡排序
     * 使用两层循环  外层循环控制是第几次冒泡
     * 内层循环控制每一次冒泡到哪里结束
     * 内层循环只需要保证每次循环的终点到了已经完成排序的那个索引结束即可
     */
    if (vec.size() == 0)
    {
        return;
    }
    int len = vec.size();

    for (int i = 0; i < len; i++)
    {
        // 开始冒泡
        for (int j = 1; j < len - i; j++)
        {
            // 每一趟开始的时候 后面的和前面的比较，将这一趟大的元素交换位置
            int tem = vec[j];
            if (tem < vec[j - 1])
            {
                vec[j] = vec[j - 1];
                vec[j - 1] = tem;
            }
        }
    }
}
int main()
{
    vector<int> vec = {1, 21, 4, 33, 7, 2, 9, 120};
    maopao(vec);
    cout << "maopao sort: ";
    for (auto &i : vec)
    {
        cout << i << "  ";
    }
}