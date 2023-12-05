#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *A = pHead1;
        ListNode *B = pHead2;

        while (A != B)
        {
            // 两个节点的值不一样
            A = (A != nullptr) ? A->next : pHead2;
            B = (B != nullptr) ? B->next : pHead1;
        }
        return A;
    }
};
int main()
{
    return 0;
}