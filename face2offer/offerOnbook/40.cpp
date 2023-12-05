# include <bits/stdc++.h>
/**
 * 求所有和为Sum的连续的子序列
*/
using namespace std;
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param sum int整型
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > FindContinuousSequence(int sum) {
        
        // write code here
        // 首先确定遍历的边界值，因为sum/2+1，因为除了这个以外不可能存在超过两个的序列结构

        int bound = sum / 2 + 1;
        vector<vector<int> > res;
        if (sum<=2){
            return res;
        }
        // 两个数字的之前连续数列的求和
        vector<int> ans;
        ans.clear();
        for (int i = 1; i <= bound; i++) {
            ans.clear();
            int temp = 0;
            for (int j = i; j <= bound; j++) {
                ans.push_back(j);
                temp += j;
                if (temp == sum) {
                    res.push_back(ans);
                    break;
                } else if (temp > sum) {
                    break;
                } else {
                    continue;
                }
            }
        }
        return res;

    }
};int main(){
    return 0;
}