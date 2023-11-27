#include <bits/stdc++.h>
using namespace std;
/**
 * 面试题16 数字的整数次方
 */
class Solution
{
public:
    double Power(double base, int exponent)
    {
        // 在本题目中，需要知道底数base是一个doubel类型的数据，因此
        // 需要讨论base的情况
        if (fabs(base - 0.0) < 1e-6)
        {
            // 如果底数是0，那么我们直接返回
            return 0.0;
        }
        if (exponent == 0)
        {
            return 1.0;
        }
        bool sign = false;
        if (exponent < 0)
        {
            sign = true;
        }
        exponent = abs(exponent);
        // 开始正式计算逻辑 -- 递归
        double ans = myPower(base, exponent);
        if (sign)
        {
            ans = 1 / ans;
        }
        return ans;
    }
    double myPower(double base, int exponent)
    { // 首先使用位运算判断
        if (exponent == 1)
        {
            return base;
        }
        while (exponent)
        {
            if ((exponent & 0x01) == 0x01)
            {
                // 是一个记述

                return base * myPower(base, exponent >> 1) * myPower(base, exponent >> 1);
            }
            else
            {
                return myPower(base, exponent >> 1) * myPower(base, exponent >> 1);
            }
        }
    }
};

int main()
{
    Solution s;
    double ans = s.Power(4, -1);
    cout << ans;
}