#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        int ans = -1;
        int star = 0;
        int end = x;
        while (end >= star)
        {
            int mid = star + (end - star) / 2;
            if (mid * mid <= x)
            {
                ans = mid;
                star = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};
int main()
{
    int source = 8;
    Solution s;
    int ans = s.mySqrt(10);
    cout << ans << endl;
    return 0;
}