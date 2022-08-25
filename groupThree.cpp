#include <bits/stdc++.h>
using namespace std;

//  面试题 03.01. 三合一
class TripleInOne
{
public:
    vector<int> vecStack;
    int index1, index2, index3, size;
    // 面试题 03.01. 三合一
    TripleInOne(int stackSize)
    {
        // 使用一个数组表示三个栈
        vecStack.resize(stackSize * 3);
        // 分别表示三个下标。
        index1 = 0;
        index2 = stackSize;
        index3 = stackSize * 2;
        size = stackSize;
    }

    void push(int stackNum, int value)
    {
        // 向栈中压入数据，首先要考虑的是是不是栈满
        switch (stackNum)
        {
        case 0:
            if (index1 != size)
            {
                vecStack[index1++] = value;
            }
            break;
        case 1:
            if (index2 != 2 * size)
            {
                vecStack[index2++] = value;
            }
            break;
        case 2:
            if (index3 != 3 * size)
            {
                vecStack[index3++] = value;
            }
            break;

        default:
            break;
        }
        return;
    }

    int pop(int stackNum)
    {
        // 从栈中删除数据，需要考虑的是是不是栈空
        switch (stackNum)
        {
        case 0:
            if (index1 != 0)
            {
                return vecStack[--index1];
            }
            break;
        case 1:
            if (index2 != size)
            {
                return vecStack[--index2];
            }
            break;
        case 2:
            if (index3 != 2 * size)
            {
                return vecStack[--index3];
            }
            break;

        default:
            break;
        }
        return -1;
    }

    int peek(int stackNum)
    {
        // 从栈中读数据，需要考虑的是是不是栈空
        switch (stackNum)
        {
        case 0:
            if (index1 != 0)
            {
                return vecStack[index1 - 1];
            }
            break;
        case 1:
            if (index2 != size)
            {
                return vecStack[index2 - 1];
            }
            break;
        case 2:
            if (index3 != 2 * size)
            {
                return vecStack[index3 - 1];
            }
            break;

        default:
            break;
        }
        return -1;
    }

    bool isEmpty(int stackNum)
    {
        // 从栈中读数据，需要考虑的是是不是栈空
        switch (stackNum)
        {
        case 0:
            if (index1 != 0)
            {
                return false;
            }
            break;
        case 1:
            if (index2 != size)
            {
                return false;
            }
            break;
        case 2:
            if (index3 != 2 * size)
            {
                return false;
            }
            break;

        default:
            break;
        }
        return true;
    }
};

// 面试题 03.02. 栈的最小值
class MinStack
{
public:
    /** initialize your data structure here. */

    stack<int> vecStack;
    stack<int> minstack; //记录最小值

    MinStack()
    {
        minstack.push(INT_MAX); // 最小栈压入最小的一个元素
    }

    void push(int x)
    {
        vecStack.push(x); // 普通栈直接压入
        int v = minstack.top();
        //记录最小值的栈记录当前值对应的最小值
        if (v <= x)
        {
            minstack.push(v);
        }
        else
        {
            minstack.push(x);
        }
    }

    void pop()
    {
        if (!vecStack.empty())
        {
            vecStack.pop();
        }
        if (!minstack.empty())
        {
            minstack.pop();
        }
    }

    int top()
    {
        if (!vecStack.empty())
        {
            return vecStack.top();
        }
        else
        {
            return 0;
        }
    }

    int getMin()
    {
        if (!minstack.empty())
        {
            return minstack.top();
        }
        else
        {
            return INT_MAX;
        }
    }
};

// 面试题 03.03. 堆盘子
class StackOfPlates
{
public:
    int cap;                     // 一摞盘子的最大个数
    int nowIndex;                // 现在的栈
    vector<stack<int>> vecStack; // 使用栈数组

    StackOfPlates(int cap)
    {
        this->cap = cap;
        nowIndex = 0;
    }

    void push(int val)
    {
        if (vecStack[nowIndex].size() == cap)
        {
            //当前栈满
            nowIndex++;
        }
        vecStack[nowIndex].push(val);
    }

    int pop()
    {
        if (vecStack[nowIndex].size() == 0)
        {
            //当前栈空
            if (nowIndex == 0)
            {
                return -1;
            }
            else
            {
                nowIndex--;
            }
        }
        int v = vecStack[nowIndex].top();
        vecStack[nowIndex].pop();
        return v;
    }

    int popAt(int index)
    {
        if (vecStack[index].size() == 0)
        {
            return -1;
        }
        else
        {
            int v = vecStack[index].top();
            vecStack[index].pop();
            return v;
        }
    }
};

// 面试题 03.04. 化栈为队
class MyQueue
{
private:
    stack<int> instack; //入栈

    stack<int> outstack; // 出栈 模拟先入先出

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        //直接向入栈添加元素即可
        instack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (outstack.empty())
        {
            // 出栈中元素为空，将入栈元素存入出栈中
            while (!instack.empty())
            {
                int v = instack.top();
                instack.pop();
                outstack.push(v);
            }
        }
        // 出栈中的栈顶元素就是最先来的
        int v = outstack.top();
        outstack.pop();
        return v;
    }

    /** Get the front element. */
    int peek()
    {
        if (outstack.empty())
        {
            // 出栈中元素为空，将入栈元素存入出栈中
            while (!instack.empty())
            {
                int v = instack.top();
                instack.pop();
                outstack.push(v);
            }
        }
        // 出栈中的栈顶元素就是最先来的
        int v = outstack.top();
        return v;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return instack.empty() && outstack.empty();
    }
};

// 面试题 03.05. 栈排序
class SortedStack
{
private:
    stack<int> sortStack;
    stack<int> tempStack;

public:
    SortedStack()
    {
    }

    void push(int val)
    {

        // 将比大于待插入元素的值先移动到辅助栈
        while (!sortStack.empty() && sortStack.top() < val)
        {
            int v = sortStack.top();
            sortStack.pop();
            tempStack.push(v);
        }
        // 入栈
        sortStack.push(val);
        // 元素重新回到栈中
        while (!tempStack.empty())
        {
            sortStack.push(tempStack.top());
            tempStack.pop();
        }
    }

    void pop()
    {
        if (sortStack.empty())
        {
            return;
        }
        sortStack.pop();
    }

    int peek()
    {
        if (sortStack.empty())
        {
            return -1;
        }
        return sortStack.top();
    }

    bool isEmpty()
    {
        return sortStack.empty();
    }
};

//面试题 03.06. 动物收容所
class AnimalShelf
{
private:
    queue<vector<int>> dog;
    queue<vector<int>> cat;
    vector<int> res;

public:
    AnimalShelf()
    {
        res = {-1,-1};
    }

    void enqueue(vector<int> animal)
    {
        if (animal[1] == 0)
        {
            cat.push(animal);
        }
        else
        {
            dog.push(animal);
        }
    }
    vector<int> dequeueAny()
    {
        if (dog.empty() && cat.empty())
        {
            return res;
        }
        else if (dog.empty() && !cat.empty())
        {
            vector<int> r = cat.front();
            cat.pop();
            return r;
        }
        else if (!dog.empty() && cat.empty())
        {

            vector<int> r = dog.front();
            dog.pop();
            return r;
        }
        else
        {
            if (cat.front()[0] < dog.front()[0])
            {
                vector<int> r = cat.front();
                cat.pop();
                return r;
            }
            else
            {
                vector<int> r = dog.front();
                dog.pop();
                return r;
            }
        }
    }

    vector<int> dequeueDog()
    {
        if (!dog.empty())
        {
            vector<int> r = dog.front();
            dog.pop();
            return r;
        }
        else
        {
            return res;
        }
    }

    vector<int> dequeueCat()
    {
        if (!cat.empty())
        {
            vector<int> r = cat.front();
            cat.pop();
            return r;
        }
        else
        {
            return res;
        }
    }
};

int main()
{
    AnimalShelf am;
    am.enqueue([[ 1, 1 ]]);

    return 0;
}
 