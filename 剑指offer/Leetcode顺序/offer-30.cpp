# include <bits/stdc++.h>

using namespace std;
  
class MinStack {
public:
    int minEle = INT_MAX;
    stack<int> sourceStack;
    stack<int> minStack;
    /** initialize your data structure here. */
    MinStack() {
        minStack.push(minEle);       
    }
    
    void push(int x) {
        sourceStack.push(x);
        minStack.push(minStack.top()<x ? minStack.top():x);
    }
    
    void pop() {
        sourceStack.pop();
        minStack.pop();
    }
    
    int top() {
        return sourceStack.top();
    }
    
    int min() {
        return minStack.top();

    }
};
int main(){
    cout<< INT_MIN<<endl;
    return 0;
}