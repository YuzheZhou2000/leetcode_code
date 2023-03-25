# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 寻找最长的回文子串
        int n = s.size();

        // 定义动态存储空间
        vector<vector<int>> dp(n, vector<int>(n));
        int left = 0;
        int right = 0;
        int len = right-left;
        for (int i = 0; i < n; i++){
            dp[i][i] = true;// 表示str[i] - str[i] 是一个回文子串
        }
        // 转移方程：进行遍历循环 判断是不是存在回文字符
        for (int L = 2; L <= n; L++){
            // 从字串长度为2开始
            for (int i = 0;i<n; i++){
                // i代表起始子串的左侧位置
                int j = i + L - 1; // 左侧+长度-1 = 右侧
                if(j>=n){
                    // 右侧越界
                    break;
                }else{
                    // 右侧没有越界
                    if(s[i] == s[j]){
                        if(L == 2){
                            dp[i][j] = true;
                        }else{
                            // 动态规划的方程
                            dp[i][j] = dp[i + 1][j - 1];
                        }
                    }
                }
                if(dp[i][j] && j-i+1 > len){
                    // 存在更长的子串，进行状态更新
                    left = i;
                    right = j;
                }

            }
        }

        return s.substr(left, right - left + 1);
    }
};



int main(){
    string str = "zhouyuyuohz";
    string res = str.substr(2, 5);
    cout << res;
    // Solution s;
    // s.longestPalindrome(str);
    return 0;
}



