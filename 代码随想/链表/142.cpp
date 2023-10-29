#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * 题目中要求 找到环形链表中的第一个进入环状结构的节点地址
 * 首先我们使用快慢指针对这个链表进行遍历，可以知道，如果有环的存在，
 * 那么快慢指针一定会相遇（快指针一次移动两个节点）
 * 当两个指针相遇后，通过数学公示分析可以知道慢指针正好走了n个圈圈不常
 * 此时我们将快指针放到头结点上，和满指针一起一个一个节点的遍历
 * 当两个节点相遇的时候曼指针的位置整哈就是头系欸但的位置
 *
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                fast = head;
                while (fast != slow)
                {
                    /* code */
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}