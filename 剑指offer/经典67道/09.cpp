#include <bits/stdc++.h>
using namespace std;
/**
 * 变态眺台阶
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param number int整型
     * @return int整型
     */
    int jumpFloorII(int number)
    {
        // write code here、
        // 因为本题目中第n个状态可以看成是前面(n-1)个状态的和
        // 因此使用等比数列进行解决即可。2^(n-1)
        return pow(2, number - 1);

        // return 0x01 << (number - 1);
    }
};

int main()
{
    int n = 3;
    int ans = 0x01 << n;
    cout << "ans: " << ans;
    return 0;
}