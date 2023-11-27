# include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();
        // 新建一个栈结构用于模拟操作
        stack<int> myStack;
        for (int i =0 ,j=0;i<len; i++){
            // 模拟压入栈操作
            myStack.push(pushed[i]);

            // 压入的栈结构不是空，栈的首个元素和弹出栈的元素相同
            while ( !myStack.empty() && myStack.top() == popped[j] )
            {
                /* code */
                j++;// 模拟弹出一个元素
                myStack.pop();
            }                      
        }   
        return myStack.empty();
    }
};

int main(){


    return 0;
}