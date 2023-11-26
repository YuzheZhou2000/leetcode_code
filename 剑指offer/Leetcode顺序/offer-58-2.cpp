# include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans;
        int len = s.size();
        ans += s.substr(n,-1);

        ans += s.substr(0,n);
        

        return ans;
    }
};

int main(){
    Solution s;

    cout << s.reverseLeftWords("zhouyuzhe",2);
    return 0;
}