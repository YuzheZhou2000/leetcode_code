#include <bits/stdc++.h>
/**
 * 字符串的排列
 *
 */
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return string字符串vector
     */
    unordered_set<string> ans;

    vector<string> Permutation(string str)
    {
        /**
         * 这个题目中存在的一个大坑就是可能会有重复的元素
         * 这时候如果将两个元素看成了一个, 会导致重复
         */
        // write code here
        vector<string> anss;
        int size = str.size();
        if (size == 0)
        {
            return anss;
        }
        // 使用递归的方法解决

        myPer(str, 0, size - 1);

        for (auto &i : ans)
        {
            anss.push_back(i);
        }
        sort(anss.begin(), anss.end());
        return anss;
    }
    void myPer(string &str, int star, int end)
    {
        if (star == end)
        {
            // cout << str << endl;
            int j;
            // cin >> j;
            ans.emplace(str);
            return;
        }
        for (int i = star; i <= end; i++)
        {
            // 当前元素和每一个元素进行交换，可以得到当前位置的所有组合情况
            swap(str[star], str[i]);
            myPer(str, star + 1, end);
            // 然后换回来
            swap(str[star], str[i]);
        }
        return;
    }
};

int main()
{
    string s = "abb";
    Solution S;
    vector<string> ans = S.Permutation(s);
    for (auto &i : ans)
    {
        cout << i << endl;
    }
}