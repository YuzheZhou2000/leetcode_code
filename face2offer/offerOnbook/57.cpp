#include <bits/stdc++.h>
using namespace std;
/**
 * 对称的二叉树
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return bool布尔型
     */
    /**
     * 题目中要求使用递归和迭代两种方法
     * 来证明是一个对称的二叉树
     * 如果一个二叉树的镜像还是他自己
     * 那么这就是一个对称的二叉树
     *
     */
    bool isSymmetrical(TreeNode *pRoot)
    {
        // 递归的方法证明是一个对称的二叉树

        if (pRoot == nullptr)
        {
            return true;
        }
        bool ans = judgeinDigui(pRoot->left, pRoot->right);
        return ans;
    }
    bool judgeinDigui(TreeNode *root1, TreeNode *root2)
    {
        /**
         * 使用递归方法判断，两个节点分别从左右两个对称的监督判断，
         */
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        else if ((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr))
        {
            return false;
        }
        else
        {
            if (root1->val != root2->val)
            {
                return false;
            }
            else
            {
                return judgeinDigui(root1->left, root2->right) && judgeinDigui(root1->right, root2->left);
            }
        }
    }
};
int main()
{

    return 0;
}