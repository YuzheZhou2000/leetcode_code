#include <bits/stdc++.h>
using namespace std;
/***
 * 替换空格
 * 给的是字符串的头指针，需要做的是将字符串重新替换
 * 因此可以 首先统计空格出现个数
 * 然后拓展以后重新赋值
 *
 */
class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        int spaceCount = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
            {
                spaceCount++;
            }
        }
        // 在统计完成空格的个数以后，可以进行字符串的延长
        int newLength = length + spaceCount * 2;
        int i = length;
        int j = newLength;
        while (j >= 0)
        {
            if (str[i] != ' ')
            {
                str[j--] = str[i--];
            }
            else
            {
                i--;
                // 首先需要对新的数组进行
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
        }
    }
};

int main()
{
    char str[] = "zh  ouyuz he";
    Solution s;
    s.replaceSpace(str, 12);
    cout << str;
    return 0;
}