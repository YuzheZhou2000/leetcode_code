#include <bits/stdc++.h>
using namespace std;
/**
 * 数组中出现次数超过一半的元素
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int MoreThanHalfNum_Solution_low(vector<int> &numbers)
    {
        // write code here
        int size = numbers.size();
        sort(numbers.begin(), numbers.end());
        return numbers[size >> 1];
    }
    int MoreThanHalfNum_Solution(vector<int> &numbers)
    {
        // 排序算法的时间复杂度至少为排序的时间复杂度，因此可能时间长，尝试减低
        // 使用一种叫做摩尔投票的方法
        int count = 0, num = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (count == 0)
            {
                num = numbers[i]; // 当前记录的
                count = 1;
            }
            else
            {
                if (num == numbers[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        return num;
    }
};

int main()
{
    return 0;
}