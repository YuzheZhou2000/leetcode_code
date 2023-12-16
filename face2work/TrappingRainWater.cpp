#include <bits/stdc++.h>
using namespace std;
/**
 * 接雨水
 */
int trap(vector<int> &height)
{
    int ans = 0;
    int size = height.size();
    if (size <= 1)
        return ans;
    int maxHeight = height[0];
    int tem = 0;
    vector<int> leftMax(size, 0);
    vector<int> rightMax(size, 0);
    leftMax[0] = height[0];
    rightMax[size - 1] = height[size - 1];
    for (int i = 1; i < size; i++)
    {
        leftMax[i] = max(height[i - 1], leftMax[i - 1]);
    }
    for (int i = size - 2; i >= 0; i--)
    {
        rightMax[i] = max(height[i + 1], rightMax[i + 1]);
    }
    for (int i = 0; i < size; i++)
    {
        ans += max((min(leftMax[i], rightMax[i]) - height[i]), 0);
    }

    return ans;
}
int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int ans = trap(height);
    cout << "ans: " << ans << endl;
    return 0;
}