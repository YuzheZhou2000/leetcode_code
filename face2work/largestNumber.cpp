#include <bits/stdc++.h>
using namespace std;
/**
 * 最大数
 * 本题目说白了就是一个排序问题
 * 对于两个不同的数字，给出一个匹配规则
 * 因为循环可能用不明白
 * 因此我们直接调用库函数
 * 让两个加起来 做个比较就行了
 *
 */
bool cmp(const int &a, const int &b)
{
    // 自定义比较两个数值数字的大小
    string s1 = to_string(a);
    string s2 = to_string(b);
    return (s1 + s2) > (s2 + s1);
}
string largestNumber(vector<int> &nums)
{
    int size = nums.size();
    if (size <= 0)
        return "";
    sort(nums.begin(), nums.end(), cmp);
    string ans = "";
    for (auto &i : nums)
    {
        ans += to_string(i);
    }
    if (ans[0] == '0')
    {
        ans = "0";
    }
    return ans;
}
int main()
{
    vector<int> vec = {1, 2, 21, 3};
    string s = largestNumber(vec);
    cout << "ans: " << s << endl;
    return 0;
}