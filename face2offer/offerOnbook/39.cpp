# include <bits/stdc++.h> 
using namespace std;
/**
 * 数组中只出现一个的两个数字
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data) {//,int* num1,int *num2) {
        
        if (data.size()<=1){
            return;
        }
        int tem = 0;
        for (auto & i : data){
            // 定位两个只出现一次的两个数字的异或结果
            tem ^=i;
        }
        // 拿到这个数组中1出现的一个位置。
        int i = 1;
        while(! (tem & i)){
            i = i<<1;
        }
        cout <<"i: " <<i<<endl;
        // 这时候可以根据i进行分组
        int ans1 = 0, ans2=0;
        for (auto & num :data){
            if (num & i){
                // 第一组
                ans1 ^= num;
            }else{
                // 第二组
                ans2 ^= num;
            }
        }
        cout <<"res1: "<<ans1 <<" res2: "<<ans2<<endl; 
    }
};
int main(){
    vector <int> vec = {1,1,2,4,4,3,5,5};
    Solution s;
    s.FindNumsAppearOnce(vec);

    return 0;
}