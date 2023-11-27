#include <bits/stdc++.h>
using namespace std;
/**
 * 反转链表
*/
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *ReverseList(ListNode *head)
    {
        // write code here
        if (head == nullptr)
        {
            return head;
        }
        ListNode *p_next = head;
        ListNode *p_cur = nullptr;
        ListNode *p_tem = head;
        while (p_next != nullptr)
        {
            p_tem = p_next->next;
            p_next->next = p_cur;
            p_cur = p_next;
            p_next = p_tem;
        }
        return p_cur;
    }
};

int main()
{
    return 0;
}