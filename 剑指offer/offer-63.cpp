#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len == 0)
        {
            return 0;
        }
        vector<int> minPri(len);
        minPri[0] = prices[0];
        int ans = 0;
        for (int i = 1; i < len; i++)
        {
            minPri[i] = min(minPri[i - 1], prices[i - 1]);
            ans = max((prices[i] - minPri[i]), ans);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    
    return 0;
}