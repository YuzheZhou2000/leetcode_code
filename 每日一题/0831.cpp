#include <bits/stdc++.h>
using namespace std;
/*
����?pushed?��?popped?�������У�ÿ�������е� ֵ�����ظ���
ֻ�е����ǿ������������ջ�Ͻ��е����� push �͵��� pop �������еĽ��ʱ��
���� true�����򣬷��� false?��

����˼·

��������ջ�ṹ�������������Ƿ�Ϊջ����
����һ���洢��ջ���У���һ���洢ѹջ
����������е�ͷԪ����ͬ ͬʱ���� �����������ģ��
���ͨ���ж�����ջ�Ƿ�ͬʱΪ�ս����ж�

*/

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        
        // �ж������ǲ���һ��ջ�ṹ��ֱ������һ��ջ�ռ����ģ�⡣�ж�����Ƿ�ջ�ռ���

        /*
        ջ�Ļ���������
        top()������һ��ջ��Ԫ�ص����ã�����Ϊ T&�����ջΪ�գ�����ֵδ���塣
        push(const T& obj)�����Խ����󸱱�ѹ��ջ��������ͨ�����õײ������� push_back() ������ɵġ�
        push(T&& obj)�����ƶ�����ķ�ʽ������ѹ��ջ��������ͨ�����õײ�����������ֵ���ò����� push_back() ������ɵġ�
        pop()������ջ��Ԫ�ء�
        size()������ջ��Ԫ�صĸ�����
        empty()����ջ��û��Ԫ�ص�����·��� true��
        emplace()���ô���Ĳ������ù��캯������ջ�����ɶ���
        swap(stack<T> & other_stack)������ǰջ�е�Ԫ�غͲ����е�Ԫ�ؽ���������������Ԫ�ص����ͱ���͵�ǰջ����ͬ������ stack ������һ����������ȫ�ֺ��� swap() ����ʹ�á�
        */

        stack<int> MyStack;
        stack<int> MyPopStack;

        // ��¼���еĳ���
        int length = popped.size();

        // ����������������ͨ��ջ���� ע��ջ���ݽṹ�����ʣ��Ƚ����
        for (int i = length - 1; i >= 0; i--)
        {
            MyPopStack.push(popped[i]);
        }
        
        // ͨ����������ѭ���������ж��ǲ���һ��ջ����
        for (int i = 0; i < length; i++)
        {
            // �����������ѹ��ջ��
            MyStack.push(pushed[i]);
            cout << "zhouyuzhe" << MyPopStack.top()<< endl;
            while (!MyStack.empty() && MyStack.top() == MyPopStack.top())
            {
                // ע���жϱ߽����� ջ����Ϊ��
                // ��� ����Ӧ�ý��е���
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
    vector ��ʼ���ļ��ַ���
    
    */
    vector<int> pop(b, b + 5);
    bool res =  demo.validateStackSequences(push, pop);
    cout << res;
    return 0;
}