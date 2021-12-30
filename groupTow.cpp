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
    // ������ 02.01. �Ƴ��ظ��ڵ�
    ListNode *removeDuplicateNodes(ListNode *head)
    {
        return removeDuplicateNodesFunc1(head);
    }
    ListNode *removeDuplicateNodesFunc1(ListNode *head)
    {
        // func1�� ͨ�����ϱ����Ѿ����ֹ��Ľڵ㣬�����Ľڵ�ֱ��ɾ��
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
            { //�����д��ڴ�Ԫ��
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
        // func2 ��ʹ����ʱ������
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

    // ������ 02.02. ���ص����� k ���ڵ�
    int kthToLast(ListNode *head, int k)
    {

        // Ϊ�˼��ٱ���ʱ�䣬��ȡ˫ָ��ķ������б���

        // ��Ϊkһ������Ч�ģ�����������һ������0
        ListNode *slow = head;
        ListNode *fast = head;

        int count = 1;
        int len = 0;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            count++;
            slow = slow->next;       // ÿ���ƶ�һ��
            fast = fast->next->next; // ÿ���ƶ�����
        }
        // ���ݿ���ָ��õ�������
        if (fast->next == NULL)
        {
            len = count * 2 - 1;
        }
        else
        {
            len = count * 2;
        }
        count--;
        // �ж���ָ������λ����k�Ĺ�ϵ��ѡ����ʵ���ʼ��
        if (len - k < count)
        {
            slow = head;
            count = 0;
        }

        // ����ָ����Ϊ��ʼ�㿪ʼѭ��
        while (len - k != count)
        {
            slow = slow->next;
            count++;
        }
        return slow->val;
    }

    //������ 02.03. ɾ���м�ڵ�
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        ListNode *temp = node->next;
        node->next = temp->next;
        delete (temp);
    }

    //������ 02.04. �ָ�����
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

    // ������ 02.05. �������
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        /*
        // �����ڴ�ŵ������֣���˿��Կ���ʵ�ֺ���  ���ܣ�������������ֵ
        long a = getValueFromList(l1);
        long b = getValueFromList(l2);
        // �������ַ�������
        return getListFromValue(a + b);
        
        */

        // ���ȴ���һ��αͷ���
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        int jinwei = 0; //��λ
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
        // ������
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

    // ������ 02.06. ��������
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return true;
        }

        // ������ĿҪ��ʹ��O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ������

        //step 1 ʹ�ÿ���ָ�뽫������Ϊ������

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // �ҵ��м�ڵ�  ��Ϊslow->next

        // step 2 ��ת��벿������
        ListNode *head2 = reverseList(slow->next);

        // step 3 �Ƚϻ����ַ���
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

    //������ 02.07. �����ཻ
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

    // ������ 02.08. ��·���
    ListNode *detectCycle(ListNode *head)
    {
        //ʹ�ÿ���ָ���ж��������Ƿ���ڻ�״�ṹ
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            // �������ָ������ ��˵�����ڻ�״�ṹ
            if (slow == fast)
            {
                // ��ͷ��㿪ʼ�������ڵ㣬ͬʱ����ָ�뿪ʼ����
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