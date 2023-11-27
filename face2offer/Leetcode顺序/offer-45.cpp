#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), comp);
        string ans;
        for(int i =0;i<nums.size();i++){
            cout << nums[i]<< "  ";
            if(nums[i] == 0){
                ans += '0';
            }else{
                ans += to_string(nums[i]);
            }
        }
        cout <<endl;
        return ans;

    }
    // 自定义两个数字的比较函数
    static bool comp(const int a, const int b)
    {
        return to_string(a) + to_string(b) < to_string(b) + to_string(a);
    }
};

int main()
{
    // 999999999  999999997  999999998  
    // 2147483647 2147483646
    Solution s;
    cout << s.comp(2147483647,2147483646);
    
    // vector<int> num = {3,30,34,5,9};
    // string ans = s.minNumber(num);
    // cout <<"ans: "<<ans;

    return 0;
}