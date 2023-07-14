# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // 使用二分查找 寻找给定元素的平方根

        int left = 0;
        int right = x;
        int ans = -1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if((long long )mid * mid <= x){
                left = mid+1;
                ans = mid;
            }else{
                right = mid-1;
            }
        }
        return ans;

    }
};

int main(){
    Solution s;

    int a = s.mySqrt(8);
    cout<<a<<endl;

    return 0;
}