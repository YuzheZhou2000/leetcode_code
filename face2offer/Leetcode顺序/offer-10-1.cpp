# include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int fib_(int n) {
        // 直接递归 超出时间限制
        if (n ==0){
            return 0;
        }
        if (n == 1){
            return 1;
        }
        return getn(n);

    }
    int getn(int n){
        if(n == 1){
            return 1;
        }
        if (n == 0){
            return 0;
        }
        return getn(n-1) + getn(n-2);
    }

    int fib(int n){
        if (n<2){
            return n;
        }
        vector<long long> dp (n+1,0);
        dp[0]= 0 ;
        dp [1] =1;
        for(int i=2;i<=n;i++){
            dp[i] = (dp[i-1] + dp[i-2])  % 1000000007;
        }
        return dp[n];
    }
};

int main(){

    Solution s;
    
    int a = s.fib(43);
    cout<<a<<endl;

    return 0;
}