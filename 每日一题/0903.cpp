# include<bits/stdc++.h>
using namespace std;
/*

646. 最长数对链

给出?n?个数对。?在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当?b < c?时，数对(c, d)?才可以跟在?(a, b)?后面。我们用这种形式来构造一个数对链。

给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。


*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // 首先  自定义排序方式，最数组对进行排序 
        // 排序方式：按照第二个元素从小到大进行排序
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int cur = INT_MIN;
        
        // 用以表示最后的结果
        int res = 0;

        for (int i = 0; i < pairs.size();i++){
            // 对已经完成排序数对组进行遍历
            if(pairs[i][0]>cur){
                // 注意对判断条件的选择  是位于后面的数对第一个数字要大于前一个数对的第二个数字
                res++;
                cur = pairs[i][1];
            }
        }
        return res;
    }
};
int main(){

    return 0;
}