# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int len = s.size();
        string res = "";
        for (int i = 0;i<len;i++){
            if(s[i] != ' '){
                res += s[i];
            }else{
                res += "%20";
            }
        }
        return res;

    }
};

int main(){
    Solution s;
    string str = s.replaceSpace("zhou yu zhe");
    cout << str <<endl;
    return 0;
}