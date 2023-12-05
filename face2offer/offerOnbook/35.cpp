# include <bits/stdc++.h>
using namespace std;
/**
 * 两个链表中的第一个公共节点
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
  public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        if (p1 == nullptr || p2 == nullptr) {
            return  nullptr;
        }
        // 1
        // 2 3
        while (p1 != p2 && p1 != nullptr) {
            cout <<"p_1_val:  " << p1->val << "  p_2_val:" <<p2->val<< endl;

            if (p1->next == nullptr) {
                p1 = pHead2;
            } else {
                p1 = p1->next;
            }
            if (p2->next == nullptr) {
                p2 = pHead1;

            } else {
                p2 = p2->next;
            }
        }
        return p1;
    }
};

int main(){
    return 0;
}