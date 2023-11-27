#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_map<int, int> myMap;
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        // 还是自定义比较函数 通过arr2中的位置定义每一个元素的大小优先级

        for (int i = 0; i < arr2.size(); i++)
        {
            // 数组2中的元素记录了排序的先后顺序
            myMap.emplace(arr2[i], i); // 表示第i个元素的优先级为i
        }

        // 对arr1 执行自定义比较
        sort(arr1.begin(), arr1.end(), [&](int val1, int val2)
             {
            auto res1 = myMap.find(val1);
            auto res2 = myMap.find(val2);
            if (res1 == myMap.end() && res2 == myMap.end())
            {
                return val1 < val2;
            }
            else if (res1 == myMap.end() && res2 != myMap.end())
            {
                return false;
            }
            else if (res1 != myMap.end() && res2 == myMap.end())
            {
                return true;
            }
            else
            {
                // 都出现在了arr2中
                return res1->second < res2->second;
            } });

        return arr1;
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, 4, 4, 5, 6};
    Solution s;
    s.relativeSortArray(vec, vec);
    return 0;
}