#include <bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
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
    // 使用递归的方法遍历，构建二叉树，首先定位根节点的位置，然后分别确定左右子树的位置
    TreeNode *reBuildTree(vector<int> &preorder, vector<int> &inorder, int x, int y, int m, int n)
    {
        // x-y 当前处理的先序遍历的数组的起始点标记   m-n 当前处理的中序遍历的数组的起始点编辑

        if (y < x)
        {
            // 已经没有节点可以处理
            return nullptr;
        }
        int rootIndex;
        // 在中序遍历的数组中找到根节点的位置
        for (int i = m; i < n; i++)
        {
            if (preorder[x] == inorder[i])
            {
                // 根节点就是这个了
                rootIndex = i;
                break;
            }
        }
        int len = rootIndex - m; // 左子树的长度
        TreeNode *root = new TreeNode(preorder[x]);
        // 分别确定两个子树的起始点位置
        root->left = reBuildTree(preorder, inorder, x + 1, x + len, m, rootIndex - 1);
        root->right = reBuildTree(preorder, inorder, x + len + 1, y, rootIndex + 1, n);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 定义返回的子树根节点
        TreeNode *root;

        root = reBuildTree(preorder,inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

        return root;
    }
};
int main()
{

    return 0;
}