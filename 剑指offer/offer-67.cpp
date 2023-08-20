#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int strToInt(string str)
    {
        int len = str.size();
        int PN = 1;
        int star = 0;
        // 找到第一个开始记录的数组

        for (; star < len; star++)
        {
            cout<<str[star]-'0'<<endl;

            if (str[star] != '-' && (str[star] < '0' || str[star] > '9'))
            {
                // 不是负数  并且  不是阿拉伯数字
                return 0;
            }

            else
            {
                cout <<"s";
                if (str[star] == '-')
                {
                    PN = -1;
                    star++;

                    if (!(str[star] < '0' && str[star] > '9'))
                    {
                        return 0;
                    }
                }
                break;
            }
        }
        cout << "why"<<endl;
        string temStr;
        for (; star < len; star++)
        {
            if (str[star] >= '0' && str[star] <= '9')
            {
                temStr += str[star];
            }
            else
            {
                break;
            }
        }
        cout <<"temstr: "<< temStr << endl;
        int ans = atoi(temStr.c_str());
        return ans;
    }
};

int main()
{
    Solution s;
    cout << "res: " << s.strToInt("   -42");

    return 0;
}