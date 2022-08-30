#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    /*
    对原二叉树进行查找，考虑到右子树的情况即可，具体实现代码见代码注释
    注意构造问题，最大树的定义要求，每个节点的值都大于其子树中的其他任何值
    针对为什么要仅仅考虑右子树，是因为新加入的Val，根据题目要求，是在末尾进行附加值
    因此仅仅考虑右子树的情况即可满足要求

    */
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            TreeNode *res = new TreeNode(val);
            return res;
        }
        TreeNode *parent = NULL;
        TreeNode *cur = root;
        // 对原二叉树进行遍历，找到对应的目标值
        while (cur)
        {
            if (cur->val < val)
            {
                // 要插入的目标值正好大于当前节点
                if (!parent)
                {
                    // 正好为原子树的根节点 作为新的根结点  直接返回
                    TreeNode *res = new TreeNode(val, cur, NULL);
                    return res;
                }
                // 在原来的树上的中间部分
                // 创建一个新的节点，节点的左子树为原来比目标值小的子树
                TreeNode *temp = new TreeNode(val);
                temp->left = cur;
                // 整体作为原来父节点的右子树
                parent->right = temp;
                return root;
            }
            else
            {
                // 继续向右子树遍历
                parent = cur;
                cur = cur->right;
            }
        }
        // 原来所有右子树上的值都大于目标值，直接将目标值放在右下角节点的右侧
        TreeNode *temp = new TreeNode(val);
        parent->right = temp;
        // 最终返回原来的二叉树即可
        return root;
    }
};
int main()
{
    return 0;
}
