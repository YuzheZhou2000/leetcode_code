#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int add(int a, int b)
    {
        // 不适用四则运算计算a和b的和
        while (b != 0)
        {
            // 首先 a&b是在进行与运算，只有全部为1的时候才是1
            unsigned int arry = (unsigned int)(a & b) << 1;
            cout << arry << endl;
            // 然后a和b进行异或操作
            a = a ^ b;
            b = arry;
        }
        return a;
    }
};
int main()
{
    Solution s;
    s.add(11,10);
    return 0;
}