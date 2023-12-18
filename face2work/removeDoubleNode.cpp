#include <bits/stdc++.h>
using namespace std;
/**
 * 删除链表中的重复元素
 * 这个重复的元素指的是将所有重复的全部删除，而不是剩下一个
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
 */
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *ans = new ListNode(0, head);
    ListNode *dump = ans;
    while (dump->next != nullptr && dump->next->next != nullptr)
    {
        /* code */
        if (dump->next->val == dump->next->next->val)
        {
            // 已经出现了重复的值
            int tem = dump->next->val;
            while (dump->next != nullptr && dump->next->val == tem)
            {
                dump->next = dump->next->next;
            }
        }
        else
        {
            dump = dump->next;
        }
    }

    return ans->next;
}
int main()
{
    return 0;
}