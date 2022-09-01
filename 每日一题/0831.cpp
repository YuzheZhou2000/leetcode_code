#include <bits/stdc++.h>
using namespace std;
/*
给定?pushed?和?popped?两个序列，每个序列中的 值都不重复，
只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，
返回 true；否则，返回 false?。

解题思路

利用两个栈结构分析给定序列是否为栈序列
其中一个存储出栈序列，另一个存储压栈
如果两个序列的头元素相同 同时弹出 否则继续进行模拟
最后通过判断两个栈是否同时为空进行判断

*/

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        
        // 判断序列是不是一个栈结构，直接申请一个栈空间进行模拟。判断最后是否栈空即可

        /*
        栈的基本操作：
        top()：返回一个栈顶元素的引用，类型为 T&。如果栈为空，返回值未定义。
        push(const T& obj)：可以将对象副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
        push(T&& obj)：以移动对象的方式将对象压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
        pop()：弹出栈顶元素。
        size()：返回栈中元素的个数。
        empty()：在栈中没有元素的情况下返回 true。
        emplace()：用传入的参数调用构造函数，在栈顶生成对象。
        swap(stack<T> & other_stack)：将当前栈中的元素和参数中的元素交换。参数所包含元素的类型必须和当前栈的相同。对于 stack 对象有一个特例化的全局函数 swap() 可以使用。
        */

        stack<int> MyStack;
        stack<int> MyPopStack;

        // 记录序列的长度
        int length = popped.size();

        // 将弹出的序列数据通过栈保存 注意栈数据结构的性质：先进后出
        for (int i = length - 1; i >= 0; i--)
        {
            MyPopStack.push(popped[i]);
        }
        
        // 通过遍历进行循环遍历，判断是不是一个栈序列
        for (int i = 0; i < length; i++)
        {
            // 将输入的序列压入栈中
            MyStack.push(pushed[i]);
            cout << "zhouyuzhe" << MyPopStack.top()<< endl;
            while (!MyStack.empty() && MyStack.top() == MyPopStack.top())
            {
                // 注意判断边界条件 栈不能为空
                // 相等 正好应该进行弹出
                MyStack.pop();
                MyPopStack.pop();
            }
        }
        
        if (MyStack.empty() && MyPopStack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Solution demo;
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> push(a, a + 5);
    int b[5] = {4, 5, 3, 2, 1};
    /*
    vector 初始化的几种方法
    
    */
    vector<int> pop(b, b + 5);
    bool res =  demo.validateStackSequences(push, pop);
    cout << res;
    return 0;
}