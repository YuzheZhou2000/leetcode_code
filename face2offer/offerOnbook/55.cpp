#include <bits/stdc++.h>
using namespace std;
/**
 * 删除链表中重复的结点
 */
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    ListNode *deleteDuplication(ListNode *pHead)
    {
        // 删除链表中的重复节点

        // 使用一个map记录出现的次数
        unordered_map<int, int> myMap;
        if (pHead == nullptr)
        {
            return nullptr;
        }

        // 使用一个伪头结点
        ListNode *head = new ListNode(-1);
        head->next = pHead;
        while (pHead)
        {
            myMap[pHead->val]++;
            pHead = pHead->next;
        }
        // 现在记录了节点中的值的出现的次数。
        pHead = head;
        while (pHead->next)
        {
            if (myMap[pHead->next->val] > 1)
            {
                // 出现了超过一次，那么需要删除next节点
                ListNode *temp = pHead->next;
                pHead->next = pHead->next->next;
                delete (temp);
                continue;
            }
            else
            {
                pHead = pHead->next;
            }
        }
        return head->next;
    }
};
int main()
{
    return 0;
}