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

    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0 || m <= 0)
        {
            return -1;
        }

        vector<int> numbers(n, 0); // 模拟这个圈中的n个样本
        int index = -1;
        int step = 0;
        int count = n; // 开始是n个人的
        while (count > 0)
        {
            index++; // 因为上一个删除了，因此下一次指向了下一个元素
            if (index >= n)
            {
                // 如果超出了n个人，那么这个环就需要从0重新开始
                index = 0;
            }
            if (numbers[index] == -1)
            {
                // -1表示这个人已经被删除了
                continue;
            }
            step++;
            if (step == m)
            {
                // 找到了第m次
                numbers[index] = -1;
                step = 0;
                count--;
            }
        }
        return index;
    }
};
int main()
{
    return 0;
}