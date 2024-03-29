#include <bits/stdc++.h>
using namespace std;

void myMerge(vector<int> &sourceVec, vector<int> &tem, int star, int midIndex, int end)
{
    // 在完成两个子数组排序后，进行合并的函数
    // 其实在这个合并过程中，也就是比较两个子数组，根据大小进行比较
    // cout << "star: " << star << "mid: " << midIndex << "end: " << end << endl;
    int k = star; // 存储排序完成后的数组的下标
    int i = star;
    int j = midIndex + 1;
    while (i <= midIndex && j <= end)
    {
        if (sourceVec[i] > sourceVec[j])
        {
            tem[k++] = sourceVec[i++];
        }
        else
        {
            tem[k++] = sourceVec[j++];
        }
    }
    while (i <= midIndex)
    {
        tem[k++] = sourceVec[i++];
    }
    while (j <= end + 1)
    {
        tem[k++] = sourceVec[j++];
    }
    // 将辅助数组中的元苏返回回去
    for (int i = star; i <= end; i++)
    {
        sourceVec[i] = tem[i];
    }

    return;
}

void mergeSort(vector<int> &sourceVec, vector<int> &temVec, int star, int end)
{
    /**
     * 归并排序
     */
    if (star >= end)
    {
        return;
    }
    // 求分割数组时的index
    int midIndex = star + (end - star) / 2;
    // 子数组排序
    mergeSort(sourceVec, temVec, star, midIndex);
    mergeSort(sourceVec, temVec, midIndex + 1, end);
    myMerge(sourceVec, temVec, star, midIndex, end);
}

int main()
{
    // 需要排序的数组
    vector<int> sourceVector = {5, 1, 3, 3, 7, 4, 8, 6};
    vector<int> tempVector(sourceVector.size());
    int len = sourceVector.size() - 1;
    mergeSort(sourceVector, tempVector, 0, len);
    for (auto &i : sourceVector)
    {
        cout << i << "  ";
    }
    return 0;
}

// void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
// {
//     int i = startIndex, j = midIndex + 1, k = startIndex;
//     while (i != midIndex + 1 && j != endIndex + 1)
//     {
//         if (sourceArr[i] > sourceArr[j])
//             tempArr[k++] = sourceArr[j++];
//         else
//             tempArr[k++] = sourceArr[i++];
//     }
//     while (i != midIndex + 1)
//         tempArr[k++] = sourceArr[i++];
//     while (j != endIndex + 1)
//         tempArr[k++] = sourceArr[j++];
//     for (i = startIndex; i <= endIndex; i++)
//         sourceArr[i] = tempArr[i];
// }

// // 内部使用递归
// void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
// {
//     int midIndex;
//     if (startIndex < endIndex)
//     {
//         midIndex = startIndex + (endIndex - startIndex) / 2; // 避免溢出int
//         MergeSort(sourceArr, tempArr, startIndex, midIndex);
//         MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
//         Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
//     }
// }

// int main(int argc, char *argv[])
// {
//     int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
//     int i, b[8];
//     MergeSort(a, b, 0, 7);
//     for (i = 0; i < 8; i++)
//         printf("%d ", a[i]);
//     printf("\n");
//     return 0;
// }