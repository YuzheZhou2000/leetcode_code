#include <bits/stdc++.h>
using namespace std;
/***
 * 跳台阶
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 * 求该青蛙跳上一个 n 级的台阶总共有多少种跳法
 * 先后次序不同算不同的结果
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
    int jumpFloor(int number)
    {
        // write code here
        // 根据斐波那契数列的经验，我们知道直接使用递归会超级耗时
        // 因此采用使用中间变量记录的方法
        if (number <= 2)
        {
            return number;
        }

        // 通过观察可以发现规律，每一次都是上一层(再跳一个)+上上层(再跳两个)
        int val_2 = 1;
        int val_1 = 2;
        int ans;

        for (int i = 2; i < number; i++)
        {
            ans = val_2 + val_1;
            // 更新状态
            val_2 = val_1;
            val_1 = ans;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    int ans = s.jumpFloor(7);
    cout << "ans: " << ans;
    return 0;
}