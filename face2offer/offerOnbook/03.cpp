#include <bits/stdc++.h>
using namespace std;
/***
 * 从尾到头打印链表
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
    // vector<int> printListFromTailToHead(ListNode *head)
    // {
    //     // 首先想到的就是直接顺序读取一遍链表，存储到数组中，然后将数组逆序即可。
    //     vector<int> res;
    //     ListNode *pHead = head;
    //     while (pHead != nullptr)
    //     {
    //         /* code */
    //         res.push_back(pHead->val);
    //         pHead = pHead->next;
    //     }
    //     reverse(res.begin(), res.end());
    //     return res;
    // }
    vector<int> printListFromTailToHead(ListNode *head)
    {
        // 如果使用递归的解法解决这个问题
        vector<int> ans;

        getValofList(ans, head);

        return ans;
    }
    void getValofList(vector<int> &ans, ListNode *node)
    {
        if (node != nullptr)
        {
            // 必须深度理解这个递归的写法
            /**
             * 直接访问当前链表的元素，没有到最后一个，那么需要继续向后访问，
             * 当到了最后一个元素，不继续向后访问了，打印出来链表节点的值，然后返回
             * 返回以后继续打印之前按存储状态的，然后继续打印，
             * 因此最重要的就是先向后访问后面的节点值，然后从后向前回溯
             */
            if (node->next != nullptr)
            {
                getValofList(ans, node->next);
            }
            ans.push_back(node->val);
        }
    }
};

int main()
{
    // 构造一个list
    ListNode *node1 = new ListNode(5);
    ListNode *node2 = new ListNode(6);
    ListNode *node3 = new ListNode(7);
    ListNode *node4 = new ListNode(8);
    ListNode *node5 = new ListNode(9);
    ListNode *node6 = new ListNode(10);
    node5->next = node6;
    node4->next = node5;
    node3->next = node4;
    node2->next = node3;
    node1->next = node2;
    Solution S;
    vector<int> res = S.printListFromTailToHead(node1);
    for (const auto &i : res)
    {
        cout << i << ' ';
    }

    return 0;
}