# include <bits/stdc++.h>

using namespace std;
class Solution {

public:
    bool canPartition(vector<int>& nums) {
        // 判断是否可以等分数组，如果等分，每一个子集的和都为原来的1/2

        int len = nums.size();
        int sum =0;
        for(int i =0;i<len;i++){
            sum += nums[i];            
        }
        if (sum%2 ==1){
            return false;
        }
        int targetSum = sum2;
        // 此时题目转化为查找是否存在和为targetSum 的子集 0−1 背包问题



    }
};

int main(){
    return 0;

}