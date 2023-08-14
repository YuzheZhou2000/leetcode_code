#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        set<int> mySet;
        int minEle = 14;
        int maxEle = 0;
        // 对nums进行遍历
        for (const auto &num : nums)
        {
            if (num == 0)
            {
                continue;
            }
            if (mySet.find(num) == mySet.end())
            {
                // 插入元素
                mySet.emplace(num);
                minEle = minEle < num ? minEle : num;
                maxEle = maxEle > num ? maxEle : num;
            }
            else
            {

                return false;
            }
        }
        cout << maxEle << minEle;
        return maxEle - minEle < 5;
    }
};

int main()
{
    return 0;
}