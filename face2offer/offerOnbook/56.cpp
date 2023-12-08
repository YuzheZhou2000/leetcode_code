#include <bits/stdc++.h>
using namespace std;
/**
 * 找出二叉树给定节点的下一个节点
 */
struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};
class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        // 用户得到的输入只有一个子树根节点
        /**
         * 也就说我们拿到的这个pNode可能是给定的子树中的节点
         * 我们要返回的就是这个pnode的后一个节点
         */
        if (pNode == nullptr)
        {
            // 如果当前节点是一个空节点，那么直接返回这个
            return pNode;
        }
        TreeLinkNode *ans = nullptr;

        if (pNode->right != nullptr)
        {
            // 如果当前节点下面有右子树， 那么下一个遍历的节点就应该是
            // 当前节点右子树的最左边的节点
            TreeLinkNode *rightNode = pNode->right;
            while (rightNode->left != nullptr)
            {
                rightNode = rightNode->left;
            }
            ans = rightNode;
            return ans;
        }
        else
        {
            // 当前节点下面没有右子树了，那么就需要看父节点
            TreeLinkNode *parentNode = pNode->next;

            // 父节点分为两种情况
            if (parentNode != nullptr && parentNode->left == pNode)
            {
                // case1: 当前节点是父节点的左子树的根节点 那么下一个就是父节点
                ans = parentNode;
                return ans;
            }
            else if (parentNode != nullptr && parentNode->right == pNode)
            {
                // case2：当前节点是父节点的右子树的根节点 那么就需要继续向上寻找
                // 寻找的条件是第一个成为包含左子树的父节点
                TreeLinkNode *curNode = pNode;
                while (parentNode != nullptr && parentNode->right == curNode)
                {
                    curNode = parentNode;
                    parentNode = curNode->next;
                }
                ans = parentNode;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}