#include <bits/stdc++.h>
using namespace std;
/**
 * 归并排序
 * 归并排序同样的也是先经过分割，但是这个分割时最小化分割的感觉
 * 什么意思呢，就是说不断地取中间值， 进行最小的划分
 * 然后等到只有两个元素的时候  开始合并
 * 和快速排序一致，也是需要写两个递归函数的
 * 第一个函数时真是的递归
 * 第二个函数时表示当完成条件以后，对有序数组的合并操作
 */

void merge(vector<int> &vec, int star, int mid, int end)
{
    vector<int> tem;
    int i = star;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (vec[i] < vec[j])
        {
            tem.push_back(vec[i]);
            i++;
        }
        else
        {
            tem.push_back(vec[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        tem.push_back(vec[i++]);
    }
    while (j <= end)
    {
        tem.push_back(vec[j++]);
    }
    // 将辅助数组中的元素放回来
    for (int i = 0; i < tem.size(); i++)
    {
        vec[star++] = tem[i];
    }
}

void guibing(vector<int> &vec, int star, int end)
{
    if (star >= end)
    {
        return;
    }
    // 和快速排序不同，归并排序的中间的划分是根据mid求出来，而快速排序的额mid是根据位置调整返回回来的
    int mid = star + (end - star) / 2;
    // 得到以后对两边的子序列分别进行归并
    guibing(vec, star, mid);
    guibing(vec, mid + 1, star);
    merge(vec, star, mid, end);
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
    guibing(vec, 0, vec.size() - 1);

    cout << "sort: ";
    for (auto &i : vec)
    {
        cout << i << "  ";
    }
}