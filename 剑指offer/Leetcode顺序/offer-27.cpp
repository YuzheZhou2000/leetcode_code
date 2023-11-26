#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        // 反转二叉树  直接使用镜像即可

        reversiTree(root);

        return root;
    }

    void reversiTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        reversiTree(root->right);
        reversiTree(root->left);

        TreeNode *tem = root->left;
        root->left = root->right;
        root->right = tem;
        return;
    }
};

int main()
{

    return 0;
}