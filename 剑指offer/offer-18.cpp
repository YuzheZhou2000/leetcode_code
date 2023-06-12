# include<bits/stdc++.h>

using namespace std;


/**
 * Definition for singly-linked list.
 *  */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        // 如果直接是头节点 可以直接返回
        if(head->val == val){
            return head->next;
        }

        ListNode* cur = head;
        ListNode* pre = head->next;
        while (pre != nullptr)
        {
            if (pre->val == val){
                cur->next = pre->next;
            }
            pre = pre->next;
            cur = cur->next;
        }
        return head;     
    }
};

int main(){
    return 0;
}