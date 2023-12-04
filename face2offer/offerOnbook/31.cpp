# include <bits/stdc++.h>
using namespace std;
/**
 * 把数组排成最小的数字
 * 返回一个字符串
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return string字符串
     */
    string PrintMinNumber(vector<int>& numbers) {
        // write code here
        // 由于两个数组直接拼接，可能会导致int类型的数据数值溢出
        // 所以首先将int类型的数据转化为string
        vector<string> vecStr;
        for(int i = 0; i<numbers.size(); i++){
            string tem = to_string(numbers[i]);
            vecStr.push_back(tem);
        }
        // 现在得到的是一个string的数组，下一步可通过自定义排序
        // 对数组位置进行调整。 那么需要明确的就是这个排序规则
        sort(vecStr.begin(), vecStr.end(), cmp);
        string ans;
        for (int i = 0; i<vecStr.size(); i++){
            ans += vecStr[i];
        }
        return ans;
    }
    static bool cmp (const string vecStr1, const string vecStr2){
        string str1 = vecStr1 + vecStr2;
        string str2 = vecStr2 + vecStr1;
        return str1 < str2;
    }
};
int main(){
    vector<int> nums= {1,2,3,4,555,6,10};
    Solution s;
    string ans = s.PrintMinNumber(nums);
    cout <<ans;
    return 0;
}