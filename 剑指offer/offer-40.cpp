# include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        /*
        本题目的要求是找到数组中最小的k个数字
        */
       // 声明返回的结果
       vector<int> res(k,0);
       if(k == 0){
        return res;
       }


       // 首先创建一个优先队列
       priority_queue<int> Q;
       for (int i = 0; i < k; i++)
       {
        /*首先直接向优先队列（最大堆）中插入元素，通过一遍遍历 获得结果*/
        Q.emplace(arr[i]);
       }
       for (int i = k; i < arr.size(); i++)
       {
        /* 判断后面的元素和当前元素的大小关系 */
        if(Q.top()>arr[i]){
            Q.pop();
            Q.emplace(arr[i]);
        }
       }
       
       for(int i =0 ;i<k;i++){
        res[i] = Q.top();
        Q.pop();

       }
       return res;
    }
};

int main(){

    return 0;
}