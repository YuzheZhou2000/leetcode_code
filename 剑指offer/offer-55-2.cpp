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
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }
        else
        {
            return max(leftHeight, rightHeight) + 1;
        }
    }
    // 对于二叉树中的任意一个节点 如果平衡  返回其高度 如果不平衡  直接返回-1
    bool isBalanced(TreeNode *root)
    {
        int height = getHeight(root);
        return height > -1;
    }
};

int main()
{
    return 0;
}