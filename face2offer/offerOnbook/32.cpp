#include <bits/stdc++.h>
using namespace std;
/**
 * 求第index个丑数(只包含质因子2，3，5)
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param index int整型
     * @return int整型
     */
    int GetUglyNumber_Solution(int index)
    {
        // write code here
        if (index <= 0)
        {
            return -1;
        }
        if (index == 1)
        {
            return 1;
        }
        // 正式逻辑  计算2 3 5 的组合
        // 开辟一个数组，记录0-index中的丑数
        vector<int> ans(index + 1, 0);
        ans[1] = 1;
        // 开始的时候三个不同的因子都是从1开始加 这时候
        int index_two = 1, index_three = 1, index_five = 1;

        for (int i = 2; i <= index; i++)
        {
            // 需要明白的一点是因为index_2/3/5是++，因此其实就是可以看作是遍历前面的所有可能
            // for循环中，每一次循环其实都是获得了一个最新的丑数
            // 下面的判断是不是相等的逻辑 是为了防止重复
            int minNum = min(min(ans[index_two] * 2, ans[index_three] * 3), ans[index_five] * 5);
            if (minNum == ans[index_two] * 2)
            {
                index_two++;
            }
            if (minNum == ans[index_three] * 3)
            {
                index_three++;
            }
            if (minNum == ans[index_five] * 5)
            {
                index_five++;
            }
            ans[i] = minNum;
            cout << "minNum: " << minNum << endl;
        }

        return ans[index];
    }
};

int main()
{
    Solution s;
    int a = s.GetUglyNumber_Solution(7);
    cout << a << endl;
    return 0;
}