#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res (-1);// 作为头节点
        ListNode* curr = res; 
        while (l1 != nullptr && l2 != nullptr)
        {
            if(l1->val<l2->val){
                curr->next = l1;
                l1 = l1->next;                
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1 != nullptr){
            curr->next = l1;
        }
        if(l2 != nullptr){
            curr->next = l2;
        }
        return res->next;

    }
};

int main(){


    return 0;
}