# include <bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur != nullptr)
        {
            ListNode* tem = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tem;
        }
        
        return prev;       

    }
};

int main (){
    return 0;
}