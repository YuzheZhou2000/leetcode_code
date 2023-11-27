#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        // 在nums中，只有两个数是只出现一次的，其余的都出现了两个
        // 我们知道异或操作 ^ 可以满足相同为0 ，不同为1 的要求，
        // 那么我们首先对整个数组进行遍历，对每一个元素进行异或操作

        int ans = 0;
        for (int num : nums)
        {
            ans ^= num;
        }
        // 此时我们知道ans就是两个只出现一个的元素的异或的值。

        // 因为两个元素的值是不一样的，因此这两个元素a和b一定在某一个数位上是不一样的

        // 所以此时我们首先找到第一个数位是1的
        int diff = 1;
        while ( (diff & ans) == 0)
        {
            diff <<= 1;
        }
        // 此时diff表示的就是两个只出现一次的元素 中 的二级制表示中不一样的数位

        // 下面开始分组   如果nums中的元素在这个diff数位中一样，分到a组 反之分到b组
        int a = 0, b = 0;
        for (int num : nums)
        {
            if (num & diff)
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
        }
        return vector<int>{a, b};
    }
};
int main()
{
    return 0;
}