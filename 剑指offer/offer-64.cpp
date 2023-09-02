#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumNums(int n)
    {
        // 实现1+2+···+n
        // 如果增加了限制，我们想到了使用递归
        // 但是递归都是由判断出口的，因此使用一个且操作进行出口，因此正好最后的条件是n为0
        n && (n += sumNums(n - 1));
        return n;
    }
};

int main()
{
    return 0;
}