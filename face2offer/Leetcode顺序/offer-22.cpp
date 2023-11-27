# include<bits/stdc++.h>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    public:
        ListNode* getKthFromEnd(ListNode* head, int k) {
            ListNode* slow = head;
            ListNode* fast = head;

            // 首先快指针向前前进k步
            for (int i =1;i<k;i++){
                fast = fast->next;
            }            

            // 快慢指针同时向前 当快指针走到结尾时，慢指针正好走到倒数第k个位置

            while(fast != nullptr){
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
            

    }
};

int main(){
    return 0;
}