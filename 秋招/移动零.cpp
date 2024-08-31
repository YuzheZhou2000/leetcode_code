# include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void moveZeroes(vector<int>& nums) {
        // 在保持以前顺序的基础上，完成
        if (nums.size() == 0){
            return;
        }
        // 使用双指针完成
        int fast_index = 0;
        int slow_index = 0;
        while (fast_index < nums.size())
        {
            if (nums[fast_index] !=0){
                swap(nums[slow_index], nums[fast_index]);
                slow_index++;
            }
            fast_index ++;
        }
    }
};
int main(){
    vector<int> nums = {0,1,0,3,0,11,12,0};
    Solution s;
    s.moveZeroes(nums);
    for (auto num: nums){
        cout<<num <<" ";
    }
    return 0;
}