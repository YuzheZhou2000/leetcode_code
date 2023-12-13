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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // 使用双指针直接解决问题
    ListNode *phead = new ListNode(0, head);

    ListNode *fast = phead->next;
    ListNode *slow = phead;
    for (int i = 0; i < n; i++)
    {
        if (fast != nullptr)
        {
            fast = fast->next;
        }
        else
        {
            return nullptr;
        }
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *tem = slow->next;
    slow->next = tem->next;
    delete tem;

    // 找到了slow这个点
    return phead->next;
}
int main()
{
    ListNode *node1 = new ListNode(1, nullptr);
    ListNode *node2 = new ListNode(2, node1);
    ListNode *node3 = new ListNode(3, node2);
    ListNode *node4 = new ListNode(4, node3);
    ListNode *node5 = new ListNode(5, node4);
    ListNode *node6 = new ListNode(6, node5);
    ListNode *ans = removeNthFromEnd(node6, 7);
    cout << "ans: ";
    while (ans)
    {
        cout << ans->val << "  ";
        ans = ans->next;
    }

    return 0;
}