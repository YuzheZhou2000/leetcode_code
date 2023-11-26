#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        int len = s.size();
        // 第一次遍历记录顺序
        unordered_map<char, int> myMap;

        for (int i = 0; i < len; i++)
        {
            if (myMap.find(s[i]) == myMap.end())
            {
                myMap[s[i]] = 1;
            }
            else
            {
                myMap[s[i]]++;
            }
        }

        for (int i = 0; i < len; i++)
        {
            if (myMap[s[i]] == 1)
            {
                return s[i];
            }
        }
        return ' ';
    }
};

int main()
{

    return 0;
}