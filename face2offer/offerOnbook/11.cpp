#include <bits/stdc++.h>
using namespace std;
/***
 * 二进制中1的个数
 * 因为题目中要求计算二进制中1的个数
 * 涉及到二进制，首先需要想到的就是二进制的位运算
 */

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int NumberOf1(int n)
    {
        // write code here
        // 题目的整体思路就是根据给定数字的二进制形式
        // 进行循环遍历
        int ans = 0;
        while (n)
        {
            ans++;
            n = (n - 1) & n;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int a = 3;
    cout << s.NumberOf1(a);
    return 0;
}