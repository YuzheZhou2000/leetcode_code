# include<bits/stdc++.h>

using namespace std;


// class Solution {
// public:
//     vector<vector<int> > ans;
//     vector<vector<int>> subsets(vector<int>& nums) {

//         int size = nums.size()-1;
//         vector<int> temp;
//         makeSubSet(nums,temp,0,size);
//         return ans;

//     }
//     void makeSubSet(vector<int>& nums, vector<int> temp, int left, int right){
//         if(left>right){
//             ans.push_back(temp);
//             temp.clear();
//             return;
//         }
//         makeSubSet(nums, temp, left+1, right);
//         temp.push_back(nums[left]);
//         makeSubSet(nums, temp, left+1, right);
//     }

// };
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            // 当前已经遍历到数组的最后
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // 寻找nums中的所有可能子集
        dfs(0, nums);
        return ans;
    }
};


int main(){
    return 0;
}