# include<bits/stdc++.h>

using namespace std;

/***
 * 合并两个有序的链表结构
*/
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        // 因为空间复杂度要求为O（1），因此需要在原链表上直接进行操作
        ListNode * p_curr_1 = pHead1;
        ListNode * p_curr_2 = pHead2;
        if(pHead1 == nullptr)
            return pHead2;
        if (pHead2 == nullptr)
            return pHead1;

        ListNode * p_ans = new ListNode(0);
        ListNode * p_curr = p_ans;

        // 开始合并操作 是递增序列
        while(p_curr_1 != nullptr && p_curr_2 != nullptr){
            cout <<"1: "<<p_curr_1->val << "     2: "<<p_curr_2->val<<endl;
            if (p_curr_1->val < p_curr_2->val){
                p_curr->next = p_curr_1;            
                p_curr_1 = p_curr_1->next;
            }else{
                p_curr->next = p_curr_2;
                p_curr_2 = p_curr_2->next;
            }
            p_curr = p_curr->next;
        }
        if (p_curr_1 != nullptr){
            p_curr->next = p_curr_1;
        }
        if(p_curr_2 != nullptr){
            p_curr->next = p_curr_2;
        }
        return p_ans->next;
    }
};


int main(){
    return 0;
}