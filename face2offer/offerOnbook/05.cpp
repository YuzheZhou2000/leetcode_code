#include <bits/stdc++.h>
using namespace std;
/**
 * 使用两个栈结构实现一个队列+
 */
class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int res;
        //
        if (stack2.empty())
        {
            // 如果第二个栈结构是空的，那么需要将第一个栈中的元素迁移到第二个栈中
            while (!stack1.empty())
            {
                /* code */
                int tem = stack1.top();
                stack2.push(tem);
                stack1.pop();
            }
                }
        res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    return 0;
}