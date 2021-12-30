#include <bits/stdc++.h>
using namespace std;

// 面试题 03.01. 三合一
vector<int> vecStack;
int index1, index2, index3, size;

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

int main()
{

    return 0;
}