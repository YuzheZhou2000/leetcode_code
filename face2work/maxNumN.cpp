#include <bits/stdc++.h>
using namespace std;

/**
 * 小于n的最大的数
*/

bool dfs(vector<int> & nums, vector<int> & target, vector<int>& ans, int index){
    if (index >= target.size())return true;
    int val = target[index];// 当前数位上许需要比较的元素
    int i = nums.size()-1;
    for (;i>=0;i--){
        if (nums[i] == val){
            // 这个时候这一个位置上的数字一样了，需要比较下面的元素 了就
            ans.emplace_back(nums[i]);
            dfs(nums, target, ans, index+1);
            break;
        }
        if(nums[i] < val){
            // 这个位已经笑了  以后全是最大的
            ans.emplace_back(nums[i]);
            int  n = target.size()- index-1;
            while(n--){
                ans.emplace_back(nums[nums.size()-1]);
            }
            return;
        }
        
    }
    // 这个使用全是大于当权元素得了
    if(i < 0){
        // 备选的所有值都大于当前元素
        if (index == 0){
            ans.push_back(0);
            dfs(nums, target, ans, index+1);
        }else{
            // 这时候应该让上面的位置的数字比原来小了
        }
    }
    return;
}

int maxNum(vector<int> vec, int target){
    int ans = 0;
    // 首先做一个分割，把target中的每一位都分割出来
    sort(vec.begin(), vec.end());
    vector<int> nums;
    while(target){
        int tem = target%10;
        nums.emplace_back(tem);
        target = target/10;
    }
    reverse(nums.begin(), nums.end());

    // 下面开始使用递归的方法解决本问题
    vector<int> vecAns;
    dfs(vec, nums, vecAns, 0);

    for (auto &i : nums){
        cout <<i<<"  ";
    }

    return ans;
}

int main(){
    vector<int> vec = {1,2,4,6,8,9};
    int target = 873;
    maxNum(vec, target);
    return 0;
}