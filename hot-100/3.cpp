# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 求给定子串的最长无重复字串长度
        int res = 0;
        int len = s.size();

        // 使用一个set集合来存储出现过的数字

        unordered_set<char> temSet;

        int right = 0;
        for (int left = 0; left < len;left++){
            if(left!= 0){
                // 删除重复的元素
                temSet.erase(s[left - 1]);
            }


            while(right<len && temSet.find(right) == temSet.end()){
                // 右指针没有越界，没有当前元素
                temSet.insert(s[right]);
                right++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};

int main(){
    Solution s;
    s.lengthOfLongestSubstring("abcabcbb");

    return 0;
}