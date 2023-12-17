#include <bits/stdc++.h>
using namespace std;
/**
 * 无重复的最长子串
 * 首先需要做的就是确定使用什么
 * 这里我们使用一个set来记录
 * 然后其实是对左边的指针进行循环
 * 右边的指针不断后移
 * 如果发现了一样的元素 那么就需要将之前的元素的弹出
 */
int lengthOfLongestSubstring(string s)
{
    int size = s.size();
    if (size <= 1)
        return size;
    unordered_set<char> myset;
    int ans = 0;
    int right = -1;
    for (int i = 0; i < size; i++)
    {
        if (i != 0)
            myset.erase(s[i - 1]);

        while (right + 1 < size && myset.count(s[right + 1]) == 0)
        {
            /* code */
            myset.emplace(s[right + 1]);
            right++;
        }
        // cout << "right: " << right << endl;
        ans = max(ans, right - i + 1);
    }
    return ans;
}

int main()
{
    string s = "dvdf";
    int ans = lengthOfLongestSubstring(s);
    cout << "ans: " << ans;
    return 0;
}