#include <bits/stdc++.h>
uning namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 本题目讲的是要我们交换成对的链表中的两个节点
 * 首先我们想到的就是遍历一遍，因为要求我们不只是更改元素的值
 * 也要对节点的地址进行调整
 * 因此我们通过设置两个指针，引入额外的指针空间记录中间状态
 * 并对整体进行交换
 * 除此之外，还是说，通过引入头结点来简化操作的复杂
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 交换相邻的两个节点
        if (head == nullptr)
        {
            return head;
        }
        // 创建一个伪头节点
        ListNode *ans = new ListNode(0, head);

        ListNode *curr = ans;

        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            // 交换两个节点
            ListNode *temp = curr->next;
            ListNode *temp1 = curr->next->next;

            temp->next = temp1->next; // 将这个对后面的元素链接到新的对中第二个节点

            curr->next = temp1; // 后面的节点提前
            temp1->next = temp; // 两个系欸但连在一起

            curr = curr->next->next;
        }

        return ans->next;
    }
};
int main()
{

    return 0;
}