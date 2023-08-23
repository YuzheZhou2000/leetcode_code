#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        vector<int> ans;

        int left = 0;
        int right = len - 1;

        while (right > left)
        {
            int tenmSum = nums[left] + nums[right];
            if (tenmSum == target)
            {
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                return ans;
            }
            else if (tenmSum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}