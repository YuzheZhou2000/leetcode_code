# include<bits/stdc++.h>

using namespace std;

// 使用两个栈结构实现一个队列

class CQueue {
public:
    stack<int> instack, outstack;
    CQueue() {

    }
    
    void appendTail(int value) {
        instack.emplace(value);
    }
    
    int deleteHead() {
        if(instack.size() == 0){
            return -1;
        }
        // 将in中的数据全部压入out
        int tem;
        while (!instack.empty())
        {
            tem = instack.top();
            instack.pop();
            outstack.push(tem);
        }
        int res = outstack.top();
        outstack.pop();
        // out中的重新放入in
        while(!outstack.empty()){
            tem = outstack.top();
            outstack.pop();
            instack.push(tem);            
        }
        return res;
        
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(){
    return 0;
}