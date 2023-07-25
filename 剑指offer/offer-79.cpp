# include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> subsets(vector<int>& nums) {

        int size = nums.size()-1;
        vector<int> temp;
        makeSubSet(nums,temp,0,size);
        return ans;

    }
    void makeSubSet(vector<int>& nums, vector<int> temp, int left, int right){
        if(left>right){
            ans.push_back(temp);
            temp.clear();
            return;
        }
        makeSubSet(nums, temp, left+1, right);
        temp.push_back(nums[left]);
        makeSubSet(nums, temp, left+1, right);
    }

};

int main(){
    return 0;
}