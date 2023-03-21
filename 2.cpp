#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int tem_val;
        int jinwei = 0;
        ListNode *head = new ListNode(); // 专门设置的头指针
        ListNode *cur = head;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                // l2 中还有值
                tem_val = (l2->val + jinwei) % 10;
                jinwei = (l2->val + jinwei) / 10;
                ListNode *tem = new ListNode(tem_val);
                cur->next = tem;
                cur = cur->next;
            }
            else if (l2 == NULL)
            {
                // l1 中还有值
                tem_val = (l1->val + jinwei) % 10;
                jinwei = (l1->val + jinwei) / 10;
                ListNode *tem = new ListNode(tem_val);
                cur->next = tem;
                cur = cur->next;
            }
            else
            {
                tem_val = (l1->val + l2->val + jinwei) % 10;    // 当前的个位数字
                jinwei = (l1->val + l2->val + jinwei) / 10; //  当前十位数字
                ListNode *tem = new ListNode(tem_val);
                cur->next = tem;
                cur = cur->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if (jinwei != 0){
            ListNode *tem = new ListNode(jinwei);
            cur->next = tem;
        }
        return head->next;
    }
};

int main()
{
    ListNode *head = new ListNode(10);
    ListNode *cur = head;
    int a = 18 / 10;
    int b = 18 % 10;
    cout << a << "  " << cur->val << endl;
    return 0;
}