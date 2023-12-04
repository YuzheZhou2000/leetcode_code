# include <bits/stdc++.h>
using namespace std;
/**
 * 求第index个丑数(只包含质因子2，3，5)
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param index int整型 
     * @return int整型
     */
    int GetUglyNumber_Solution(int index) {
        // write code here
        if (index < =0 ){
            return -1;
        }
        if (index == 1){
            return 1;
        }

        // 正式逻辑  计算2 3 5 的组合
        // 开辟一个数组，记录0-index中的丑数
        vector<int> ans (index+1,0);
        index[1] = 1;
        int index_two 


    



        return ans;



    }
};
int main(){
    return 0;
}