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
    vector<int> res;
    vector<int> reversePrint(ListNode *head)
    {
        if (head != nullptr)
        {

            visit(head);
        }
    }
    void visit(ListNode *root)
    {
        if (root->next != nullptr)
        {
            visit(root->next);
        }
        res.push_back(root->val);
        return;
    }
};

int main()
{

    return 0;
}