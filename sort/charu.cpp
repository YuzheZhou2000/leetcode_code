#include <bits/stdc++.h>
using namespace std;
/**
 * 直接插入排序
 * 其实就是维护一个前面已经完成排序的数组，如果前面 已经排序完成的比目标大
 * 那么向后移动一个位置
 * 直到结束以后直接插入原来位置
 */
void charu(vector<int> &vec)
{
    if (vec.size() <= 1)
        return;

    // 应该是从前一个元素开始向后挪 直到满足条件以后结束
    for (int i = 1; i < vec.size(); i++)
    {
        // 之所以从1开始，是因为index=0的时候是不需要排序的
        int tem = vec[i]; // 记录当前趟中目标的值
        int j = i - 1;    // 开始从已经完成排序的排序数组中查找
        while (j >= 0 && vec[j] > tem)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = tem;
    }
}

int main()
{
    vector<int> vec = {1, 21, 4, 33, 7, 2, 9, 120};
    charu(vec);
    cout << "charu sort: ";
    for (auto &i : vec)
    {
        cout << i << "  ";
    }
}