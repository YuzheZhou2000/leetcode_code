#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // 本题目为求解最长公共子序列

        // 首先肯定是通过动态规划解决本题目
        int size1 = text1.size();
        int size2 = text2.size();

        // step 1：设计记录状态变量的二维数组
        vector<vector<int>> dp(size1+1, vector<int>(size2+1,0));

        // step 2：进行初始化边界值 dp[i][j]:表示 text1[0:i] 和 text2[0:j]的最长公共子序列的长度
        for(int i =0 ;i<size1;i++)
            dp[i][0] = 0;
        for(int i =0 ;i<size2;i++)
            dp[0][i] = 0;
        
        // step 3: 设计转移方程
        for(int i = 1; i<=size1;i++){
            for(int j =1;j<=size2;j++){
                if(text1[i-1] == text2[j-1]){
                    // 两个值相等
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // step 4: 得到最后的结果
        return dp[size1][size2];
    }
};

int main()
{

    return 0;
}