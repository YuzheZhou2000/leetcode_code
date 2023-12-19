#include <bits/stdc++.h>
using namespace std;
/**
 * 根据出现次数排序
 * 这里使用了两个辅助的工具进行解决
 * 1. 使用map第一次遍历记录每一个元素的出现次数
 * 2. 针对每一个不同的元素的出现次数，放到vector中进行排序
 * 3. 根据排序结果生成新的string用于返回
 * https://leetcode.cn/problems/sort-characters-by-frequency/description/
 */
bool cmp(const pair<char, int> &a, const pair<char, int> &b)
{
    return a.second > b.second;
}
string frequencySort(string s)
{
    int size = s.size();
    if (size <= 1)
        return s;
    // 需要统计每一个字符的出现次数
    unordered_map<char, int> myMap;
    for (auto &i : s)
    {
        myMap[i]++;
    }
    // 放到vector中进行排序
    vector<pair<char, int>> vec;

    for (auto &i : myMap)
    {
        vec.push_back(make_pair(i.first, i.second));
    }

    for (auto &i : vec)
    {
        cout << i.second << "  ";
    }
    sort(vec.begin(), vec.end(), cmp);
    cout << endl;
    for (auto &i : vec)
    {
        cout << i.second << "  ";
    }
    string ans = "";
    for (auto &i : vec)
    {
        while (i.second--)
        {
            ans += i.first;
        }
    }
    return ans;
}

int main()
{
    string ans = frequencySort("zhouuzzhhhh");
    cout << endl;
    cout << "ans: " << ans;
    return 0;
}