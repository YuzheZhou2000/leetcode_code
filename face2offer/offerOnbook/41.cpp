#include <bits/stdc++.h>
using namespace std;
/**
 * 57 和为S的两个数字
 */

class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> ans;
        if (array.size() <= 1)
        {
            return ans;
        }
        int left = 0, right = array.size() - 1;

        while (left < right)
        {
            // cout << "nowsum: " << array[left] + array[right] << "   targetSum: " << sum;
            int tem = array[left] + array[right];
            if (array[left] + array[right] == sum)
            {
                ans.push_back(array[left]);
                ans.push_back(array[right]);
                return ans;
            }

            else if (array[left] + array[right] > sum)
            {
                right--;
                // cout << " right--" << endl;
            }
            else
            {
                left++;
                // cout << " left++" << endl;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    int target = 5;
    Solution s;
    vector<int> res = s.FindNumbersWithSum(vec, target);

    for (auto &i : res)
    {
        cout << i << "  ";
    }
    return 0;
}