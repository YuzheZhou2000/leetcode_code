# include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // 首先对数组进行排序
        sort(nums.begin(),nums.end());
        int lenght = nums.size();
        
        return nums[lenght/2];       

    }
};

int main(){
    return 0;
}