# include <bits/stdc++.h>
using namespace std;
/**
 * 包含min操作的栈结构
*/
class Solution {
  public:
    stack<int> sta;
    stack<int> minSta;
    void push(int value) {
        sta.push(value);
        // 通过辅助栈 维护辅助栈对应的元素正好是当前元素以及之前所有元素中最小的元素。
        if (minSta.empty()) {
            minSta.push(value);
        } else {
            int ans = minSta.top() < value ? minSta.top() : value;
            minSta.push(ans);
        }
    }
    void pop() {
        minSta.pop();
        sta.pop();
    }
    int top() {
        int ans = sta.top();
        return ans;
    }
    int min() {
        int ans = minSta.top();
        return ans;
    }
};
int main(){
    return 0;
}