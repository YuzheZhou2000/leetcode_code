#include <bits/stdc++.h>
# include<queue>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL)
        {
            return root2;
        }
        if(root2 == NULL){
            return root1;
        }
        TreeNode * root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left,root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
        
    }
};

int main(){
    queue<int> w;
    w.push(1);
    w.push(2);
    w.push(3);    w.pop();
    int a  = w.front();
    cout<<a<<endl;
    return 0;
}