#include <bits/stdc++.h>
using namespace std;
/**
 * 数组中的逆序对
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int ans = 0;
    void calcuInvers(vector<int> &sourceNum, vector<int> &temNum, int star, int mid,
                     int end)
    {
        int k = end; // 从后向前开始复制
        int j = end; // 后面数组的区间是 mid+1 - end
        int i = mid; // 前面数组的区间是 star  - mid
        while (i >= star && j > mid)
        {
            if (sourceNum[i] > sourceNum[j])
            {
                // 复制到辅助数组中
                temNum[k] = sourceNum[i];
                // 因为前面的数组中的大于后面了 需要统计逆序的
                ans = (ans + (j - mid)) % 1000000007;
                k--;
                i--;
            }
            else
            {
                temNum[k--] = sourceNum[j--];
            }
        }
        while (i >= star)
        {
            temNum[k--] = sourceNum[i--];
        }
        while (j > mid)
        {
            temNum[k--] = sourceNum[j--];
        }
        for (int i = star; i <= end; i++)
        {
            sourceNum[i] = temNum[i];
        }
        return;
    }
    void slicePairs(vector<int> &sourceNum, vector<int> &temNum, int star,
                    int end)
    {
        if (star >= end)
        {
            return;
        }
        int midIndex = star + (end - star) / 2;

        slicePairs(sourceNum, temNum, star, midIndex);
        slicePairs(sourceNum, temNum, midIndex + 1, end);

        // 完成分开的操作后，开始归并，注意是在这个归并的过程中，需要机理ans
        calcuInvers(sourceNum, temNum, star, midIndex, end);
        return;
    }
    int InversePairs(vector<int> &nums)
    {
        // write code here
        // 因为要求了时间复杂度， 因此我们尝试使用归并排序
        int len = nums.size();
        if (len <= 1)
        {
            return ans;
        }
        // 首先构建一个辅助的空间，用于归并排序的时候记录

        vector<int> tem(len - 1);

        // 进入归并排序，实际逻辑
        slicePairs(nums, tem, 0, len - 1);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {1, 2, 3};
    int res = s.InversePairs(vec);
    cout << "res: " << res << endl;
    cout << INT_MAX << endl;
    return 0;
}