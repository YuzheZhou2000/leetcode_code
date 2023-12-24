/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        // 首先写一个遍历 对原来树结构中的每一个节点进行遍历
        // 如果通过迭代的方式写一个针对大的子树的遍历
        bool ans = false;
        if (pRoot1 == nullptr || pRoot2 == nullptr)
        {
            return ans;
        }
        queue<TreeNode *> qtree;
        qtree.emplace(pRoot1);
        while (!qtree.empty())
        {
            // 如果子树不是空的
            int size = qtree.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *tem = qtree.front();
                qtree.pop();
                if (tem->left != nullptr)
                    qtree.emplace(tem->left);
                if (tem->right != nullptr)
                    qtree.emplace(tem->right);

                // 针对当前节点 进行匹配
                // TODO
                ans = machTree(tem, pRoot2);
                if (ans == true)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
    bool machTree(TreeNode *p1, TreeNode *p2)
    {
        // 递归判断两个子树是不是相同的
        if (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val == p2->val)
                return machTree(p1->left, p2->left) && machTree(p1->right, p2->right);
            else
                return false;
        }
        else if (p2 == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {

        return HasSubtree(A, B);
    }
};