#include <bits/stdc++.h>
using namespace std;
/**
 * 希尔排序
 * 希尔排序可以堪称插入排序的一个拓展
 * 什么叫写排序呢，其实说白了就是想让直接的序列尽可能的有序
 * 这个之前序列尽可能有序的过程 是通过希尔操作实现的
 * 希尔操作的实现，是通过划分间隔实现的
 * 通过对每一个间隔之间进行排序 实现整体的排序
 */

/**
 * 那么在这里复习以下直接插入排序是怎么来的
 * 其实就是每次固定i+1的值
 * 去和之前的元素作比较
 * 比i+1的位置上的元素大的  直接交换
 * 然后后移一个
 */
void xier(vector<int> &vec)
{
    if (vec.size() <= 1)
        return;
    // 第一步  找到初始增量

    int dis = vec.size() / 2;
    while (dis >= 1)
    {
        for (int k = 0; k < dis; k++)
        {
            // 每一个k代表了一个希尔以后间隔的子序列
            for (int i = k + dis; i < vec.size(); i += dis)
            {
                // 每一次移动的间隔都是dis
                int tem = vec[i];
                int j = i - dis;

                while (j >= k && vec[j] > tem)
                {
                    /* code */
                    vec[j + dis] = vec[j];
                    j -= dis;
                }
                vec[j + dis] = tem;
            }
            dis /= 2;
        }
    }
    return;
}

int main()
{
    vector<int> vec = {1, 21, 4, 33, 7, 2, 9, 120};
    xier(vec);
    cout << "xier sort: ";
    for (auto &i : vec)
    {
        cout << i << "  ";
    }
}