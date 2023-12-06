#include <bits/stdc++.h>
using namespace std;
/**
 * 实现单词的反转
 */
class Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str.size() == 0)
        {
            return str;
        }
        vector<string> tempVec;
        string tem = "";
        str += ' ';
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                if (tem.size() > 0)
                    tempVec.push_back(tem);
                tem = "";
            }
            else
            {
                tem.push_back(str[i]);
            }
        }
        reverse(tempVec.begin(), tempVec.end());
        string ans;
        ans += tempVec[0];
        for (int i = 1; i < tempVec.size(); i++)
        {
            ans += ' ';
            ans += tempVec[i];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ans = s.ReverseSentence("");
    cout << ans;
    return 0;
}