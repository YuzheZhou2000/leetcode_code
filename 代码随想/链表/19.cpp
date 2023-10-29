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
 * 本题目的要求是删除链表中的倒数的第n个节点
 * 升级版要求说通过一次遍历来找到目标节点进行删除。
 * 如果一次遍历，我们首先想到的就是使用双指针对题目进行解决。
 * 如果找到倒数n个节点，可以让快指针首先向后移动n个距离
 * 然后快指针和慢指针一起同时向后移动，当快指针移动到结尾的时候，曼指针就正好指向了目标
 * 此时进行删除即可
 * 需要注意的是在处理链表问题的时候，首先可以创建一个虚拟的头指针，可以高效的简化流程
 */

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 题目要求通过一次遍历直接找到元素  使用双指针实现本题目
        // 因为是倒数第n个节点， 因此我们使用fast指针首先移动n 然后快慢指针同时移动

        // 首先创建一个伪头节点

        ListNode *ans = new ListNode(0);
        ans->next = head;

        // 首先让fast进行移动
        ListNode *fast = ans;

        while (n > 0 && fast != nullptr)
        {
            /* code */
            fast = fast->next;
            n--;
        }
        fast = fast->next;
        ListNode *slow = ans;
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete (temp);
        return ans->next;
    }
};
int main()
{
    return 0;
}