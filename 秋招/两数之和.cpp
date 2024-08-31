# include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> ans;

        // 使用unordered_map记录
        unordered_map<int, int> hashtable;

        for (int i = 0 ; i<nums.size(); i++){
            // 查找是不是有对应的另一个元素,使用auto进行类型推导
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end()){
                return {hashtable[target - nums[i]], i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector<int> vec = {2,7,11,15};
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum(vec, target);
    for (auto& i: res){
        cout << i<<endl;
    }

    return 0;
}
