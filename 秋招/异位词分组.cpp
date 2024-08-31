#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /**
         * 字母的异位分词
        */

       // 使用一个map来存储数据
       unordered_map<string, vector<string>> maptable;

       for(auto& str : strs){
        string key = str;
        sort(str.begin(), str.end());
        cout <<"key: "<<key <<" str: "<<str<<endl;
        maptable[str].emplace_back(key);
       }

        vector<vector<string>> ans;
        for(auto i = maptable.begin(); i!= maptable.end(); i++){
            ans.emplace_back(i->second);
        }
       return ans;

    }
};

int main(){
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution soul;
    vector<vector<string>> res = soul.groupAnagrams(str);
    for (auto s: res){
        for (auto ss: s){
            cout <<" "<<ss;
        }
        cout <<endl;
    }
    return 0;
}