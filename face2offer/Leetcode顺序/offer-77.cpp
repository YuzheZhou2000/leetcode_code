#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
// 基于归并排序对链表数据结构进行排序
    ListNode *sortList(ListNode *head)
    {
        
        // 对链表进行排序，要求时间复杂度在nlog(n)  根据题解提示 我们使用归并排序
        return mySortList(head,nullptr);

    }
    ListNode * mySortList(ListNode *left, ListNode*right){
        if(left == nullptr){
            return left;
        }
        if(left->next == right){
            // 此时只剩下两个元素 直接返回后进行归并排序
            left->next = nullptr;
            return left;
        }

        // 使用双指针计算链表的长度
        ListNode* fast;
        ListNode* slow;
        fast = left;
        slow = left;
        while(fast != right){
            slow = slow->next;
            fast = fast->next;
            // 快指针每次移动两个位置
            if(fast != right){
                fast = fast->next;
            }            
        }

        // 中间指针的位置就是慢指针现在当前的位置
        ListNode* mid = slow;

        // 进行递归计算
        ListNode * leftHead = mySortList(left,mid);
        ListNode * rightHead = mySortList(mid, right);
        // 合并左右区间
        return merge(leftHead,rightHead);
    }
    // 合并两个已经排好序的数组
    ListNode * merge(ListNode* left, ListNode * right){
        cout<<"zhouyuz";
        // 首先创建一个伪头指针
        ListNode * dumpHead = new ListNode(0);
        ListNode * temp = dumpHead;
        ListNode * temp1 = left;
        ListNode * temp2 = right;
        while(temp1 != nullptr && temp2 != nullptr){
            // 开始进行两个有序链表的合并
            if(temp1->val > temp2->val){
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }else{
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
        if (temp1 != nullptr){
            // temp1中还有剩余  直接接入
            temp->next = temp1;
        }else if(temp2 != nullptr){
            temp->next = temp2;
        }
        // 完成排序 直接返回头指针
        return dumpHead->next;
    }
};

int main()
{
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Solution s;
    
    s.sortList(node1);
    
    while(node1 != nullptr){
        cout<<node1->val<<endl;
        node1 = node1->next;
    }
    return 0;
}