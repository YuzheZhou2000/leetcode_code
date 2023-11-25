#include <bits/stdc++.h>
using namespace std;
/***
 * 斐波那契数列
 * 本题目为经典的递归问题
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
    // int Fibonacci(int n)
    // {
    //     // write code here
    //     // 如果直接使用递归的解法，效果会超级超级慢，因为涉及到了很多无效的计算
    //     if (n <= 2)
    //     {
    //         return 1;
    //     }
    //     return Fibonacci(n - 1) + Fibonacci(n - 2);
    // }

    int Fibonacci(int n)
    {
        if (n <= 2)
        {
            return 1;
        }
        long long val_2 = 1;
        long long val_1 = 1;
        long long ans = 2;
        for (int i = 2; i < n; i++)
        {
            ans = val_1 + val_2;
            val_2 = val_1;
            val_1 = ans;
        }
        return ans;
    }
};

int main()
{
    Solution S;
    int ans = S.Fibonacci(6);
    cout << ans;

    return 0;
}