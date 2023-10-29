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
 * 本题目在链表类问题中更是属于经典中的经典
 * 通过控制两个指针在移动到末尾后，继续走另一个链表的头
 * 如果两个节点相等了  要么都是null 要么就是全部都是相同的那一个节点。
 */
// 循环链表问题
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 本题目为经典链表问题
        ListNode *A = headA;
        ListNode *B = headB;

        while (A != B)
        {
            /* code */
            if (A != nullptr)
                A = A->next;
            else
                A = headB;

            if (B != nullptr)
                B = B->next;
            else
                B = headA;
        }
        return A;
    }
};

int main()
{
    return 0;
}