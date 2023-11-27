#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        // 输入必须是长度为 32 的 二进制串
        /*
        已经给出说明输入必须是长度为 32 的 二进制串 。
        因此使用位运算直接计算每一个位数上是不是1即可
        需要注意的是在这里输入的就是二进制串
        */
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            // 对1进行移位，并和n进行按位与操作
            if (n & (1 << i))
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}