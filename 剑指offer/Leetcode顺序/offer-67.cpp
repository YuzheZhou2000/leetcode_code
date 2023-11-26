#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int strToInt(string str)
    {
        int len = str.size();
        bool PN = true; // 默认是一个正数
        int i = 0;
        for (; i < len; i++)
        {
            if (str[i] == ' ')
            {
                continue;
            }
            else if(str[i] == '+')
            {
                i++;
                break;
            }
            else if (str[i] == '-')
            {
                PN = false;
                i++;
                break;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                break;
            }
            else
            {
                // 出现了非法字符，直接返回
                return 0;
            }
        }
        string temStr;
        // 此时i记录了第一个可能出现的字符
        for (; i < len; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                temStr += str[i];
            }
            else
            {
                break;
            }
        }

        // 现在需要做的就是将temStr字符串转为int类型的数据
        int ans;
        ans = myStr2Int(temStr, PN);
        return ans;
    }

    int myStr2Int(string str, bool PN)
    {
        int ans = 0;
        int len = str.size();
        int wei = 1;
        
        for (int i = len - 1; i >= 0; i--)
        {
            ans += (str[i] - '0') * wei;
            wei *= 10;
        }

        // 首先判断 32 位大小的有符号整数

        if (PN == true)
        {
            // 是一个正数
            if (ans > numeric_limits<int>::max())
            {
                return numeric_limits<int>::max();
            }
            else
            {
                return int(ans);
            }
        }
        else
        {
            ans = -1 * ans;
            if (ans < numeric_limits<int>::min())
            {
                return numeric_limits<int>::min();
            }
            else
            {
                return int(ans);
            }
        }
    }
};

int main()
{
    Solution s;
    cout << "res: " << s.strToInt("  0000000000012345678");

    return 0;
}