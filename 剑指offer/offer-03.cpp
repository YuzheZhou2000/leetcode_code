# include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 找出任意重复的数字
        int len = nums.size();
        sort(nums.begin(),nums.end());

        // 利用数组Z记录
        set<int> tem;

        
        for(int i = 0;i<len;i++){
            if(tem.find(nums[i]) != tem.end()){
                return nums[i];
            }else{
                tem.insert(nums[i]);
            }

        }

        return 0;

    }
};

int main(){

    vector<int> num(10, 1);
    Solution s;
    int a = s.findRepeatNumber(num);
    cout <<a <<endl;


    return 0;
}