#include <bits/stdc++.h>
using namespace std;
/**
 * 不使用四则运算求两数之和
 */
class Solution
{
public:
    int Add(int num1, int num2)
    {
        // 通过设计加法器来实现
        /**
         * num1: 表示两个数字的相加的和（不考虑进位
         * num2: 表示两个数字的相加的进位
         */
        while (num2 != 0)
        {
            /* code */
            int sum = num1 ^ num2;
            int carray = (num1 & num2) << 1;
            num1 = sum;
            num2 = carray;
        }
        return num1;
    }
};

int main()
{
    Solution s;
    int ans = s.Add(10, 9);
    cout << "ans: " << ans;
    return 0;
}