#include <bits/stdc++.h>
using namespace std;
/**
 * 求1-n的和 要求不能使用基本运算
 */
class Solution
{
public:
    int Sum_Solution(int n)
    {
        // 因为不可以使用别的  但是我们可以通过n的0/非0来实现
        n && (n += Sum_Solution(n - 1));
        return n;
    }
};
int main()
{
    Solution s;
    int ans = s.Sum_Solution(5);
    cout << "ans: " << ans << endl;
    return 0;
}