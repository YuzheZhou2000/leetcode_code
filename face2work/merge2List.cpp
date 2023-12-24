#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list2 == nullptr)
        return list1;
    if (list1 == nullptr)
        return list2;

    ListNode *weiList = new ListNode(-1);
    ListNode *head = weiList;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val < list2->val)
        {
            head->next = list1;
            head = head->next;
            list1 = list1->next;
        }
        else
        {
            head->next = list2;
            head = head->next;
            list2 = list2->next;
        }
    }
    if (list1 != nullptr)
    {
        head->next = list1;
    }
    if (list2 != nullptr)
    {
        head->next = list2;
    }
    return weiList->next;
}
int main()
{
    return 0;
}