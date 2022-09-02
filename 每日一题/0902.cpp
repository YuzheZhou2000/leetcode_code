#include <bits/stdc++.h>

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
    // 保存最长的同值路径长度
    int res;

    int longestUnivaluePath(TreeNode *root)
    {
        // 使用深度优先遍历的方法解决二叉树的同值最长路径问题
        res = 0;
        dfs(root);// 深度优先遍历
        return res;
    }
    int dfs(TreeNode* root){
        // 深度优先遍历的具体实现
        if(root == NULL){
            // 子树为空 直接返回0
            return 0;
        }
        int left1 = 0;
        int right1 = 0;
        // 不断向深处查找
        int left = dfs(root->left);
        int right = dfs(root->right);

        if(root->left && root->left->val == root->val){
            left1 = left + 1;
        }
        if(root->right && root->right->val == root->val){
            right1 = right + 1;
        }
        // 注意最后输出的是边的个数  而不是结点的个数
        res = max(res, left1 + right1);
        return max(left1, right1);
    }
};

int main()
{
    Solution s;

    return 0;
}