#include <bits/stdc++.h>
using namespace std;
/**
 * 根据前序和中序遍历 构建一颗二叉树
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *mybulitTree(vector<int> &preorder, vector<int> &inorder, int star_pre, int end_pre, int star_in, int end_in)
{
    if (star_pre > end_pre)
    {
        // 这时候还没有遍历完
        return nullptr;
    }

    int val = preorder[star_pre];
    TreeNode *root = new TreeNode(val);
    int mid = star_in;
    for (; mid < end_in; mid++)
    {
        if (inorder[mid] == val)
        {
            break;
        }
    }
    // mid这时候是根节点在中序遍历的位置
    // 计算左子树的长度
    int size_left = mid - star_in;
    root->left = mybulitTree(preorder, inorder, star_pre + 1, star_pre + size_left, star_in, mid - 1);
    root->right = mybulitTree(preorder, inorder, star_pre + size_left + 1, end_pre, mid + 1, end_in);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // 前序遍历就首先访问根节点， 然后 左子树  右子树

    // 中序遍历就是现实左子树 然后根节点   然后 右子树
    TreeNode *ans = mybulitTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    return ans;
}
int main()
{
    return 0;
}