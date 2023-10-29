#include <bits/stdc++.h>
using namespace std;

/**
 * 本题目为模拟题目，模拟一个链表，并且可以通过下标对链表节点进行访问
 * 1， 链表的数据结构我们使用自定义的结构体实现
 * 2， 维护一个size的int变量，代表整个链表中整体的结点个数
 */

class MyLinkedList
{
public:
    // 对于一个目标链表而言，首先需要一个节点
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int v) : val(v), next(nullptr) {}
    };

    int size;
    ListNode *P_head;
    MyLinkedList()
    {
        // 初始化这个链表数据
        size = 0;
        P_head = new ListNode(); // 伪头节点
    }

    int get(int index)
    {
        // 从链表中读取下标为index的节点的值
        if (index >= size || index < 0)
        {
            return -1;
        }
        ListNode *temp = P_head->next;

        // 因为有size限制，因此直接index为边界进行遍历即可
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val)
    {
        // 直接插入一个头结点
        ListNode *ans = new ListNode(val);
        ans->next = P_head->next;
        P_head->next = ans;
        size++;
    }

    void addAtTail(int val)
    {
        // 直接在尾节点处插入一个节点
        ListNode *tail = P_head;
        ListNode *Node = new ListNode(val);
        for (int i = 0; i < size; i++)
        {
            tail = tail->next;
        }
        tail->next = Node;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        // 在index的位置插入元素
        if (index > size || index < 0)
        {
            // 如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。
            // 如果 index 比长度更大，该节点将 不会插入 到链表中 return;
        }
        ListNode *node = new ListNode(val);

        ListNode *P_tem = P_head;
        for (int i = 0; i < index; i++)
        {
            P_tem = P_tem->next;
        }
        node->next = P_tem->next;
        P_tem->next = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
        {
            return;
        }

        ListNode *P_tem = P_head;
        for (int i = 0; i < index; i++)
        {
            P_tem = P_tem->next;
        }
        ListNode *de = P_tem->next;
        P_tem->next = P_tem->next->next;
        delete (de);

        size--;
    }
};
int main()
{
    MyLinkedList *my_list = new MyLinkedList();
    my_list->addAtHead(7);

    my_list->addAtHead(2);

    my_list->addAtHead(1);

    my_list->addAtIndex(3, 0);

    int a = my_list->get(3);
    cout << a << endl;
    cout << my_list->size << endl;
    my_list->deleteAtIndex(2);
    my_list->addAtHead(6);
    my_list->addAtTail(4);
    a = my_list->get(4);
    cout << a << endl;
    return 0;
}