#include <bits/stdc++.h>
using namespace std;
/**
 * 反转链表
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *next = head;
    ListNode *cur = nullptr;
    ListNode *tem = nullptr;

    while (next)
    {
        tem = next->next;
        next->next = cur;
        cur = next;
        next = tem;
    }
    return cur;
}
int main()
{
    return 0;
}