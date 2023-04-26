#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int res = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if(root == NULL){
            return root;
        }
        convertBST(root->right);
        root->val = root->val + res;
        res = root->val;
        convertBST(root->left);
    }
};

int main()
{

    return 0;
}