#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 寻找排序数组中只出现一次的数字、要求时间复杂度为log(n)
    int singleNonDuplicate(vector<int> &nums)
    {

        // 根据除了目标元素之外每一个元素都出现两次进行分析  可以根据下边进行判断左右的位置

        int left = 0;
        int right = nums.size() - 1;
        if(right == 0){
            return nums[0];
        }
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] == nums[mid +1]){
                if(mid % 2 == 0){
                    //位于待查找元素的左边
                    left = mid;
                }else{
                    right = mid;
                }
                
            }else if (nums[mid] == nums[mid -1]){
                if((mid -1)%2 == 0){
                    left = mid;
                }else{
                    right = mid;
                }
                
            }else{
                return mid;
            }

        }
        return mid;
    }
};

int main()
{
    int a = 11;
    a = a ^ 1;
    cout << a;
    return 0;
}
