#include <bits/stdc++.h>
using namespace std;
/**
 * 判断字符串是不是一个数
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return bool布尔型
     */
    bool isNumeric(string str)
    {
        // write code here
        int flag = 1; // 1: 整数部分 2： 小数部分 3： 指数部分
        int ans = false;
        int len = str.size();
        if (len == 0)
        {
            return false;
        }
        // 清理前后的空格
        int star = 0;
        for (; star < len; star++)
        {
            if (str[star] != ' ')
            {
                break;
            }
        }
        int end = len - 1;
        for (; end >= 0; end--)
        {
            if (str[end] != ' ')
            {
                break;
            }
        }
        if (end < star)
        {
            return false;
        }

        // 得到一个去除空格后的字符串
        str = str.substr(star, end - star + 1);

        int len_whole = 0;

        if (str.size() == 0)
        {
            return false;
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (i == 0)
            {
                if (str[i] == '+' || str[i] == '-')
                {
                    // 处理整数部分的符号位置
                    continue;
                }
                if (str[i] == '.')
                {
                    // 直接进入小数部分
                    flag = 2;
                    i++;
                }
                if (str[i] == 'e' || str[i] == 'E')
                {
                    return false;
                }
            }
            if (flag == 1)
            {
                // 整数部分
                if (str[i] == '.')
                {
                    flag = 2;
                    continue;
                }
                else if (str[i] == 'e' || str[i] == 'E')
                {
                    if (len_whole == 0){
                        return false;
                    }
                    flag = 3;
                    ans = false;

                    if ((i < str.size() - 1) && (str[i + 1] == '+' || str[i + 1] == '-'))
                    {

                        i++;
                    }

                    continue;
                }
                else if ((str[i] - '0' <= 9) && (str[i] - '0' >= 0))
                {
                    ans = true;
                    len_whole ++;
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else if (flag == 2)
            {
                // 小数部分
                if (str[i] == 'e' || str[i] == 'E')
                {
                    if (len_whole == 0){
                        return false;
                    }
                    ans = false;
                    flag = 3;
                    if ((i < str.size() - 1) && (str[i + 1] == '+' || str[i + 1] == '-'))
                    {
                        i++;
                    }

                    continue;
                }
                else if ((str[i] - '0' <= 9) && (str[i] - '0' >= 0))
                {
                    len_whole++;
                    ans = true;
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                // 指数部分
                if ((str[i] - '0' <= 9) && (str[i] - '0' >= 0))
                {
                    ans = true;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        return ans;
    }
};
int main()
{
    Solution s;
    bool flag = s.isNumeric("12e");
    cout << "ans: " << flag;
    return 0;
}