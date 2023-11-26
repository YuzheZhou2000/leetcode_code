#include <bits/stdc++.h>
using namespace std;
/**给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。*/
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
    // 记录节点的父亲关系
    unordered_map<int, TreeNode *> fatherNode;
    unordered_map<int, bool> visit;
    void dfs(TreeNode *root)
    {
        if (root->left != nullptr)
        {
            // 如果存在左子树
            fatherNode[root->left->val] = root;
            visit[root->left->val] = false;
            dfs(root->left);
        }
        if (root->right != nullptr)
        {
            // 如果存在左子树
            fatherNode[root->right->val] = root;
            visit[root->right->val] = false;
            dfs(root->right);
        }
        return;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // 相比于上一个题目，上一个由于已经给定了是一个二叉搜索树，因此二叉树的节点已经时有顺序的了，此时作为没有顺序的二叉树，可以首先使用map记录父子关系
        if (root == nullptr)
        {
            // 如果是一棵空树，直接返回即可
            return root;
        }

        fatherNode[root->val] = nullptr;
        visit[root->val] = false;
        // 进行遍历，对两个map数据结构进行初始化
        dfs(root);
        int curVal = p->val;
        while (p != nullptr)
        {
            // 开始向祖先节点开始遍历，寻找路径
            visit[p->val] = true;
            p = fatherNode[p->val];
        }
        while (q != nullptr)
        {
            if (visit[q->val] == true)
            {
                // 找到了
                return q;
            }
            q = fatherNode[q->val];
        }

        return nullptr;
    }
};

int main()
{
    return 0;
}