#include <bits/stdc++.h>
using namespace std;
/**
 * 二叉搜索树转双向排序链表
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
public:
    TreeNode *perNode = nullptr;
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        // 如果最基础的解法，就是通过中序遍历得到一个排序序列，然后构建双向链表
        // 然而本题目需要的是空间复杂度为O(1)的算法，因此我们考虑使用递归解法
        if (pRootOfTree == nullptr)
        {
            return pRootOfTree;
        }
    }
};

int main()
{
    return 0;
}