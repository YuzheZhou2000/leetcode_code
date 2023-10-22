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

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 首先构造1个伪头结点
        ListNode *p_head = new ListNode(0);
        p_head->next = head;
        if (head == nullptr)
        {
            // 如果是一个空节点，那么直接return
            return head;
        }
        // 通过构建两个指针，执行原地的操作
        ListNode *P_cur = p_head;
        ListNode *p_next = head;

        while (p_next)
        {
            if (p_next->val == val)
            {
                // 如果找到了目标节点，那么删除目标节点，记得释放空间
                P_cur->next = p_next->next;
                delete (p_next);
                p_next = P_cur->next;
            }
            else
            {
                // 遍历整个链表，寻找目标值
                P_cur = P_cur->next;
                p_next = p_next->next;
            }
        }
        return p_head->next;
    }
};

int main()
{
    // 重新构建新的链表
    ListNode *l1 = new ListNode(10);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(111);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(2);
    ListNode *l6 = new ListNode(13);

    l5->next = l6;
    l4->next = l5;
    l3->next = l4;
    l2->next = l3;
    l1->next = l2;

    Solution s;
    ListNode *ans = s.removeElements(l1, 2);
    while (ans)
    {
        cout << ans->val << "  ";
        ans = ans->next;
    }

    return 0;
}