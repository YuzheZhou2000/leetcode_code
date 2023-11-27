#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans;
        vector<string> temStr;
        int len = s.size();
        string tem;
        tem.clear();
        for (int i = 0; i < len; i++)
        {
                        
            if(s[i] == ' '){
                if (!tem.empty()){
                    temStr.push_back(tem);
                }
                tem.clear();
            }else{
                tem +=s[i];
            }
        }
        if(!tem.empty()){
            temStr.push_back(tem);
        }
        reverse(temStr.begin(),temStr.end());
        if(temStr.size()>0){
            ans += temStr[0];
        }
        for (int i = 1;i <temStr.size();i++){
            ans += ' ';
            ans += temStr[i];
        }
        return ans;

    }
};

int main()
{
}