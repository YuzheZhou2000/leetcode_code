#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 *  */
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
    vector<int> sortVal;
    int kthLargest(TreeNode *root, int k)
    {
        
        // 题目要求为对于一个给定的二叉搜索树，找到第k大的节点的值

        // 首先想到的时因为给出的就是一个二叉搜索树，因此将二叉搜索树中序遍历以后得到的数组就是一个 完成排序的数组

        // 然后通过下标进行访问即可，
        midVisit(root);
        for (auto val : sortVal)
        {
            cout << "val: " << val;
        }
        return sortVal[sortVal.size() - k];
    }
    void midVisit(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        midVisit(root->left);
        sortVal.push_back(root->val);
        midVisit(root->right);

        return;
    }
};

int main()
{
    TreeNode *root = new TreeNode(10);
    Solution s;
    s.kthLargest(root, 1);
    return 0;
}