# include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int longestConsecutive(vector<int>& nums) {
        // 如果长度为零，直接弹出
        if (nums.size() == 0){
            return 0;
        }
        // 使用set来记录每一个元素的状态
        unordered_set<int> numsset;
        for (auto num : nums){
            numsset.insert(num);
        }
        int ans = 1;
        for (auto n = numsset.begin(); n!= numsset.end(); n++){
            int longval = *n;
            //进行一个剪枝操作进行处理
            if (numsset.find( longval-1) != numsset.end()){
                // -1的元素在set集合里面已经出现过了，时候直接继续就OK
                continue;
            }
            int cur = 1;
            while (numsset.find(longval + 1) != numsset.end())
            {
                cur++;
                longval++;
            }
            cout <<endl;
            ans = max(ans, cur);
        }
        return ans;
    }
};
int main(){
    vector<int> vec ={0,3,7,2,5,8,4,6,0,1};
    Solution a;
    int ans = a.longestConsecutive(vec);
    cout <<"ans: "<<ans<<endl;
    return 0;
}