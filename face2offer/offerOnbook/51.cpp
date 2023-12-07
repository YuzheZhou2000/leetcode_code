#include <bits/stdc++.h>
using namespace std;
/**
 * 正则表达式的匹配
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */
    bool match(string str, string pattern)
    {
        // write code here
        if (str.size() == 0 && pattern.size() == 0)
        {
            return true;
        }
        bool ans = matchString(str, pattern);
        return ans;
    }

    // 使用递归判断str和模板pattern之间的一一对应关系
    bool matchString(string str, string patt)
    {
        cout << "str: " << str << "    patt: " << patt << endl;
        //  当走到最后的时候，返回true
        if (str.size() == 0 && patt.size() == 0)
        {
            return true;
        }
        if (str.size() != 0 && patt.size() == 0)
        {
            // 目标string已经完了， 但是模板中还存在剩余
            return false;
        }

        // 考虑'*'表示它前面的字符可以出现任意次的情况
        if (patt.size() >= 2)
        {

            if (patt[1] == '*')
            {
                // 在当前匹配过程中，第二个字符是*
                if ((str[0] == patt[0]) || (patt[0] == '.' && str.size() >= 1))
                {
                    // 第一个字符可以匹配上
                    // 消耗掉 "x*"的方式有两种，那么把这个x*看作是个废物不出现，要么是直接吞掉前字符
                    // 如果不消耗 "X*" 那么就做多了一个
                    // 字符串向后走一个   模板向后走两个
                    return matchString(str.substr(1, str.size()), patt.substr(2, patt.size())) || matchString(str, patt.substr(2, patt.size())) || matchString(str.substr(1, str.size()), patt);
                }
                else
                {
                    // 第一个不一样的情况下  只能使用* 将前面的字符消耗
                    return matchString(str, patt.substr(2, patt.size()));
                }
            }
        }

        // 不考虑第二个是* 那么这个时候
        if (str[0] == patt[0])
        {
            return matchString(str.substr(1, str.size()), patt.substr(1, patt.size()));
        }

        if (patt[0] == '.' && str.size() >= 1)
        {

            return matchString(str.substr(1, str.size()), patt.substr(1, patt.size()));
        }

        return false;
    }
};
int main()
{
    Solution s;
    bool flag = s.match("aaba", "ab*a*c*a");
    cout << "flag: " << flag << endl;
    return 0;
}