# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkOrder(vector<int>& order, int i, int j){
        if (i>=j){
            // 此时处理的代表子树的序列只有一个节点或者直接为空节点，则肯定满足要求
            return true;
        }

        // 当前序列的根节点的值
        int rootVal = order[j];

        // 左子树的值都小于根节点
        int m = i;
        for(;m<j; m++){
            if(order[m]>rootVal){
                break;
            }
        }
        int mid = m-1;// 左子树的范围为i-mid

        for(;m<j;m++){
            if(order[m]<= rootVal){
                break;
            }
        }
        // 右子树的范围为mid- (m-1)

        // 开始判断
        return (m == j) && checkOrder(order,i,mid) && checkOrder(order, mid+1,m-1);




    }
    bool verifyPostorder(vector<int>& postorder) {

        return checkOrder(postorder, 0, postorder.size()-1);

    }
};


int main(){
    return 0;
}