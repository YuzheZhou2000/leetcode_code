#include <bits/stdc++.h>
using namespace std;

// ������ 03.01. ����һ
vector<int> vecStack;
int index1, index2, index3, size;

TripleInOne(int stackSize)
{
    // ʹ��һ�������ʾ����ջ
    vecStack.resize(stackSize * 3);
    // �ֱ��ʾ�����±ꡣ
    index1 = 0;
    index2 = stackSize;
    index3 = stackSize * 2;
    size = stackSize;
}

void push(int stackNum, int value)
{
    // ��ջ��ѹ�����ݣ�����Ҫ���ǵ����ǲ���ջ��
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
    // ��ջ��ɾ�����ݣ���Ҫ���ǵ����ǲ���ջ��
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
    // ��ջ�ж����ݣ���Ҫ���ǵ����ǲ���ջ��
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
    // ��ջ�ж����ݣ���Ҫ���ǵ����ǲ���ջ��
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