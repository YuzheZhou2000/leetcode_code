# include <bits/stdc++.h>

using namespace std;
/**
 * 只出现一次的字符
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return int整型
     */
    int FirstNotRepeatingChar(string str) {
        // write code here
        int size = str.size();
        // 且字符串只有字母组成
        unordered_map<char,int> myMap;
        for(int i =0;i<size;i++){
            char tem = str[i];
            // 在map数据结构中的查找操作
            auto iter = myMap.find(tem);
            if (iter != myMap.end()){
                // 找到了
                iter->second ++;
            }else{
                myMap.emplace(tem,1);
            }
        }

        // 遍历maMap 找到第一个第二个元素是1的即可，
        for (int i =0; i<size; i++){
            auto iter = myMap.find(str[i]);
            if(iter->second == 1){
                return i;
            }
        }
        return -1;

    }
};
int main(){
    Solution s;
    cout << s.FirstNotRepeatingChar("aa");
    return 0;
}