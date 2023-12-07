#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int StrToInt(string str)
    {
        int len = str.size();
        if (len == 0)
            return len;

        int star = 0;
        int flag = 1;
        int ans = 0, pow = 1;
        if (str[star] == '-')
        {
            flag = -1;
            star++;
        }
        else if (str[star] == '+')
        {
            star++;
        }
        for (int i = len - 1; i >= star; i--)
        {
            if ((str[i] - '0') > 9 || (str[i] - '0') < 0)
            {
                return 0;
            }
            else
            {
                ans += (str[i] - '0') * pow;
                pow *= 10;
            }
        }
        return flag * ans;
    }
};
int main()
{
    Solution s;
    int ans = s.StrToInt("+1187");
    cout << "ans: " << ans << endl;
    return 0;
}