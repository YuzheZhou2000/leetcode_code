#include <bits/stdc++.h>

using namespace std;

class Solution_1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        { // 尝试使用二分查找，但是忘记了要输出的就是下标，直接sort会使顺序打乱
            int e = nums.size() - 1;
            int s = 0;
            vector<int> res;
            sort(nums.begin(), nums.end());
            while (s < e)
            {
                if (nums[s] + nums[e] == target)
                {
                    res.push_back(s);
                    res.push_back(e);
                    break;
                }
                else if (nums[s] + nums[e] < target)
                {
                    e--;
                }
                else
                {
                    s++;
                }
            }
            return res;
        }
        {
            // 直接进行暴力搜索
            int len = nums.size();
            vector<int> res;
            for (int i = 0; i < len; i++)
            {
                for (int j = i + 1; j < len; j++)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
                }
            }
            return res;
        }
        {
            // 为了迅速查找目标数组中是否存在目标元素，引入哈希表
            unordered_map<int, int> map;
            int len = nums.size();
            for (int i = 0; i < len; i++)
            {
                // 查找操作是根据key查找，因此key存储原来的元素值 而val中应为需要获得的下标值
                auto it = map.find(target - nums[i]);
                if (it != map.end())
                {
                    // 找到了对应的元素值
                    return {it->second, i};
                }
                else
                {
                    map[nums[i]] = i;
                }
            }
            return {};
        }
    }
};



int main()
{

    // count << 18 / 10 << "  " << 18 % 10 << endl;

    // int a = 10;

    return 0;
}