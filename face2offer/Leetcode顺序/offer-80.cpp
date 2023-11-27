#include <bits/stdc++.h>

using namespace std;

// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

class Solution {
public:
    vector<int> temp;
    vector< vector <int> > ans;
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k)
    }
    void dfs(int cur,int max, int k){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(cur > max){
            return;
        }
        temp.push_back(cur);
        dfs(cur+1,max,k);
        temp.pop_back();
        dfs(cur+1,max,k);
    }
};

int main()
{
    return 0;
}