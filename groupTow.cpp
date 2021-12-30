#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // 面试题 02.01. 移除重复节点
    ListNode *removeDuplicateNodes(ListNode *head)
    {
        return removeDuplicateNodesFunc1(head);
    }
    ListNode *removeDuplicateNodesFunc1(ListNode *head)
    {
        // func1： 通过集合保存已经出现过的节点，其他的节点直接删除
        if (head == NULL)
        {
            return head;
        }
        set<int> recoder;
        set<int>::iterator iter;
        ListNode *res = head;
        recoder.insert(head->val);

        while (head->next)
        {
            iter = recoder.find(head->next->val);
            if (iter != recoder.end())
            { //集合中存在此元素
                ListNode *tem = head->next;
                head->next = tem->next;
                delete (tem);
            }
            else
            {
                recoder.insert(head->next->val);
                head = head->next;
            }
        }
        return res;
    }
    ListNode *removeDuplicateNodesFunc2(ListNode *head)
    {
        // func2 不使用临时缓冲区
        ListNode *tem = head;
        while (tem != nullptr)
        {
            ListNode *prt = tem;
            while (prt->next != nullptr)
            {
                if (prt->next->val == tem->val)
                {
                    prt->next = prt->next->next;
                }
                else
                {
                    prt = prt->next;
                }
            }
            tem = tem->next;
        }
        return head;
    }

    // 面试题 02.02. 返回倒数第 k 个节点
    int kthToLast(ListNode *head, int k)
    {

        // 为了减少遍历时间，采取双指针的方法进行遍历

        // 因为k一定是有效的，所以链表长度一定大于0
        ListNode *slow = head;
        ListNode *fast = head;

        int count = 1;
        int len = 0;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            count++;
            slow = slow->next;       // 每次移动一个
            fast = fast->next->next; // 每次移动两个
        }
        // 根据快慢指针得到链表长度
        if (fast->next == NULL)
        {
            len = count * 2 - 1;
        }
        else
        {
            len = count * 2;
        }
        count--;
        // 判断慢指针所在位置与k的关系，选择合适的起始点
        if (len - k < count)
        {
            slow = head;
            count = 0;
        }

        // 从慢指针作为起始点开始循环
        while (len - k != count)
        {
            slow = slow->next;
            count++;
        }
        return slow->val;
    }

    //面试题 02.03. 删除中间节点
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        ListNode *temp = node->next;
        node->next = temp->next;
        delete (temp);
    }

    //面试题 02.04. 分割链表
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode(0);
        ListNode *large = new ListNode(0);
        ListNode *smalllHead = small;
        ListNode *largeHead = large;

        while (head != NULL)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        small->next = largeHead->next;
        return smalllHead->next;
    }

    // 面试题 02.05. 链表求和
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        /*
        // 链表内存放的是数字，因此可以考虑实现函数  功能：根据链表返回数值
        long a = getValueFromList(l1);
        long b = getValueFromList(l2);
        // 根据数字返回链表
        return getListFromValue(a + b);
        
        */

        // 首先创建一个伪头结点
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        int jinwei = 0; //进位
        while (l1 != NULL || l2 != NULL || jinwei)
        {
            int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + jinwei;

            ListNode *tem = new ListNode(val % 10);
            cur->next = tem;
            cur = cur->next;
            jinwei = val / 10;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return head->next;
    }
    long getValueFromList(ListNode *l)
    {
        // 倒序存放
        long a = 0;
        for (int i = 1; l != NULL; i = i * 10)
        {
            a += l->val * i;
            l = l->next;
        }
        return a;
    }
    ListNode *getListFromValue(long a)
    {
        ListNode *head = new ListNode(0);
        if (a == 0)
        {
            return head;
        }
        ListNode *res = head;
        while (a)
        {
            int val = a % 10;
            a = a / 10;
            ListNode *temp = new ListNode(val);
            head->next = temp;
            head = head->next;
        }
        return res->next;
    }

    // 面试题 02.06. 回文链表
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return true;
        }

        // 根据题目要求使用O(n) 时间复杂度和 O(1) 空间复杂度解决此题

        //step 1 使用快慢指针将链表划分为两部分

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 找到中间节点  即为slow->next

        // step 2 翻转后半部分链表
        ListNode *head2 = reverseList(slow->next);

        // step 3 比较回文字符串
        while (head2 != NULL)
        {
            if (head->val == head2->val)
            {
                head = head->next;
                head2 = head2->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *cur = head;
        ListNode *pre = head->next;

        while (pre != NULL)
        {
            //pre = pre->next;
            ListNode *temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        head->next = NULL;
        return cur;
    }

    //面试题 02.07. 链表相交
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA != curB)
        {
            if (curA != NULL)
            {
                curA = curA->next;
            }
            else
            {
                curA = headB;
            }
            if (curB != NULL)
            {
                curB = curB->next;
            }
            else
            {
                curB = headA;
            }
        }
        return curB;
    }

    // 面试题 02.08. 环路检测
    ListNode *detectCycle(ListNode *head)
    {
        //使用快慢指针判断链表中是否存在环状结构
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            // 如果快慢指针相遇 则说明存在环状结构
            if (slow == fast)
            {
                // 从头结点开始第三个节点，同时和慢指针开始遍历
                ListNode *tem = head;
                while (tem != slow)
                {
                    tem = tem->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

int main()
{
    cout << "done" << endl;
    return 0;
}