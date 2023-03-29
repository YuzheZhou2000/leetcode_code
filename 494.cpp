# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int res = 0;
    int len = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        len = nums.size();
        findnum(nums, target, 0,0);
        return res;

    }

    void findnum(vector<int>& nums, int target, int start,int sum){
        if(start < len){
            if(sum == target){
                res++;
            }
            findnum(nums,target, start+1,sum + nums[start]);
            findnum(nums,target, start+1,sum - nums[start]);
        }       

        return;
    }
};

int main(){

    return 0;
}