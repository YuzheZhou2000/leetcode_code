#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int size = nums.size();
        // 在这里回顾快速排序的算法

        // 首先确定左右哨兵位置
        int left = 0;
        int right = size-1;

        fastSort(nums, left, right);
        return 0;
    }
    void fastSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int midPos = partition(nums, left, right);
            fastSort(nums, left, midPos - 1);
            fastSort(nums, midPos + 1, right);
        }
    }

    // 进而一个分治的递归子组件
    int partition(vector<int> &nums, int left, int right)
    {
        // 首先保存当前left的位置信息
        int temp = nums[left];
        while (left < right)
        {
            while (left < right && nums[right] > temp)
            {
                right--;
            }
            // 找到比temp小的元素
            nums[left] = nums[right];

            while (left < right && nums[left] <= temp)
            {
                left++;
            }
            nums[right] = nums[left];
        }
        // 最后相遇  将元素赋值
        nums[left] = temp;
        for (const auto &ele : nums)
        {
            cout << " " << ele;
        }
        cout<<endl;

        return left;
    }
};

int main()
{
    vector<int> vec = {1, 4, 5, 6, 7, 2, 88, 32};
    Solution s;
    s.findKthLargest(vec, 1);
    cout<<"end:";
    for (const auto &ele : vec)
    {
        cout << " " << ele;
    }

    return 0;
}