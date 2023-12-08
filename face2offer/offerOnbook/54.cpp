#include <bits/stdc++.h>
using namespace std;
/**
 * 寻找环形链表的入口
 */

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
/**
 * 经典的双指针解决方案
 * 1. 假设快指针一共走了f步， 慢指针走了s步
 * 2. 两个指针肯定是有交点 且快指针比慢指针多走了n个环的长度
 * 3. f-s = nb（b为环的长） f = 2s -->   s = nb, f = 2nb
 * 4. 这时候把f放到头结点 和s一起移动 因为s比f多了nb个步骤 所以当两个节点相遇的时候，就是入口节点了
 */
class Solution
{
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (pHead == nullptr)
        {
            return nullptr;
        }

        ListNode *fast = pHead;
        ListNode *slow = pHead;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        // 相遇了
        fast = pHead;

        while (fast != slow)
        {
            /* code */
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
int main()
{

    return 0;
}