# include <bits/stdc++.h>
using namespace std;

/**
 * 因为涉及到的两个字符串的异位数字匹配问题
 * 并且题目中给出来了是一个仅仅包含小写字母的问题
 * 因此其实可以使用一个长度为26的数组来实现
 * 其中数组的每一个位置上的值就代表了对应的元素出现的次数
 * 在第二遍遍历的时候，只要保证每一个数组的元素都是0就可以了
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 首先申请一个长度为26的数组
        vector<int> temp_nums(26,0);
        for (const auto & char_char : s){
            temp_nums[char_char - 'a'] ++;            
        }
        
        for (const auto & char_char : s){
            temp_nums[char_char - 'a'] --;            
        }

        for (const auto & i : temp_nums){
            if (i != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int> temp_nums(26,0);
    string S = "aaaab";
    for (const auto & char_char : S){
        cout <<char_char-'a'<<endl;
    }

    return 0;
}