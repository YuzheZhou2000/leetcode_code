#include <bits/stdc++.h>
using namespace std;
/**
 * 链表相交
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *l1 = headA;
    ListNode *l2 = headB;
    while (l1 != l2)
    {
        if (l1 == nullptr)
        {
            l1 = headB;
        }
        else
        {
            l1 = l1->next;
        }
        if (l2 == nullptr)
        {
            l2 = headA;
        }
        else
        {
            l2 = l2->next;
        }
    }
    return l1;
}

int main()
{
    return 0;
}