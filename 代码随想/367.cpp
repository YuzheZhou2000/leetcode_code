#include <bits/stdc++.h>

using namespace std;

class Solution
{
    // 本题目是基于69题直接判断而来
public:
    bool isPerfectSquare(int num)
    {
        int ans = mySqrt(num);
        if (ans * ans == num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int mySqrt(int x)
    {
        int ans = -1;
        int star = 0;
        long long end = x;
        while (end >= star)
        {
            long long mid = star + (end - star) / 2; // 防止越界
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
    int source = 16;
    Solution s;
    bool ans = s.isPerfectSquare(source);
    cout << "ans: " << ans;

    return 0;
}