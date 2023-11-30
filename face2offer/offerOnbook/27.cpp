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
    int MoreThanHalfNum_Solution(vector<int> &numbers)
    {
        // write code here
        int size = numbers.size();
        sort(numbers.begin(), numbers.end());
        return numbers[size >> 1];
    }
};

int main()
{
    return 0;
}