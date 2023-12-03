#include <bits/stdc++.h>
using namespace std;
/**
 * 求给定一个n。1-n中所有数组中1出现的次数之和
 */
class Solution {
  public:
    int NumberOf1Between1AndN_Solution(int n) {
        if (n <= 0)
            return 0;
        if (n < 10)
            return 1;

        int high = n;
        int pow = 1;
        int ans;
        while (high >= 10) {
            // 注意这里的判断，当到了最后一位后，直接停止
            // 这种设计可以保存最高位的数字
            high /= 10;
            pow *= 10;
        }
        // 此时高位数字可以理解为higt
        // 接下来计算低位数字
        int low = n - high * pow;
        if (high == 1) {
            // 如果最高位置是1 ，那么1的次数就是以后的所有字符+1....
            ans = low + 1;
        } else {
            // 如果最高位置不是1 ， 那么1的次数就是pow
            ans = pow;
        }
        return ans + NumberOf1Between1AndN_Solution(low) + high *
               NumberOf1Between1AndN_Solution(pow - 1);

    }
};
int main()
{
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(2345);
    return 0;
}