#include <bits/stdc++.h>
using namespace std;

/**
 * 左旋字符串
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param n int整型
     * @return string字符串
     */
    string LeftRotateString(string str, int n)
    {
        // write code here
        int len = str.size();
        if (len == 0)
        {
            return str;
        }
        n %= len;
        string tem = str.substr(0, n);
        string tem2 = str.substr(n, len);
        return tem2 + tem;
    }
};

int main()
{
    int n = 20;
    Solution cla;
    string ans = cla.LeftRotateString(s, n);
    cout << "ans: " << ans << endl;

    return 0;
}