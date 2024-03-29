#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    //
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
};
/**
 * 本题目更是基础的链表反转
 * 我们可以通过双指针来进行解决这个问题，主要后一个状态的保存即可
 * 目的是防止改变链接方式后导致后续节点无法定位
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        // ListNode *P_cur = head;
        // ListNode *P_next = head->next;
        ListNode *P_cur = nullptr;
        ListNode *P_next = head;
        ListNode *P_tem = nullptr;
        while (P_next)
        {
            P_tem = P_next->next;
            P_next->next = P_cur;
            P_cur = P_next;
            P_next = P_tem;
        }
        return P_cur;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);

    l4->next = l5;
    l3->next = l4;
    l2->next = l3;
    l1->next = l2;

    Solution s;
    ListNode *head = s.reverseList(nullptr);
    cout << head->val;
    return 0;
}