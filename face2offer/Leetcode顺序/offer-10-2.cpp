# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n<2){
            return 1;
        }
        
        // 本题目是一个经典的动态规划问题        
        vector<int> dp(n+1,0);

        // 边界条件的初始化
        // 0号台阶只能是1 1号台阶只能使用1种方式
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;// 从上一个台阶过来或者从上上个台阶直接跳跃两次
        }
        return dp[n];
    }
};



int main(){
    return 0;
}