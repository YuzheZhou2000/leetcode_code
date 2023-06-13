# include<bits/stdc++.h>

using namespace std;

/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int length = nums.size()-1;
        int i = 0;
        int j = length;

        while(i<j){
            if(nums[i] % 2 == 1){
                // 从左边开始遍历 如果是奇数，向右看
                i++;
                continue;
            }else{
                if(nums[j] % 2 == 0){
                    j--;
                    continue;
                }else{
                    int tem = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tem;
                    i++;
                    j--;
                }
            }
        }
        return nums;

    }
};

int main(){
    vector <int> v = {1,2,3,4};

    Solution s;
    v = s.exchange(v);

    for (int i =0;i<v.size();i++){
        cout<<v[i]<<endl;
    }


    return 0;
}
