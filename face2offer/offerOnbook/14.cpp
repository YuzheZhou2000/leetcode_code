#include <bits/stdc++.h>

using namespace std;

/**
 * 链表中倒数第k个结点
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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {

        /***
         *
         * 因为是倒数第K个节点，因此我们如果首先遍历一遍，
         * 得到总长度然后基于总长度，进行计算。这样的时间复杂度可能会高一些
         * 因此我们采用双指针的方法进行。
         *
         */

        if (pListHead == nullptr)
        {
            return nullptr;
        }

        // 要求倒数第k个节点，我们首先让快指针向后移动k个节点
        ListNode *pFast = pListHead;
        ListNode *pSlow = pListHead;
        for (int i = 0; i < k; i++)
        {
            pFast = pFast->next;
            if (pFast == nullptr && i + 1 < k)
            {
                return nullptr;
            }
        }
        while (pFast != nullptr)
        {

            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};

int main()
{
    return 0;
}