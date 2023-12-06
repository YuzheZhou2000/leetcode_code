#include <bits/stdc++.h>
using namespace std;
class Solution
/**
 * 圆圈中最后剩下的数字
 */
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    int LastRemaining_Solution_v0(int n, int m)
    {
        // write code here
        if (n <= 0 || m <= 0)
        {
            return -1;
        }
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans = (ans + m) % i;
        }
        return ans;
    }

    int LastRemaining_Solution_v0(int n, int m)
    {
        return 0;
    }
};
int main()
{
    return 0;
}