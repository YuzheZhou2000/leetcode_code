#include <bits/stdc++.h>
using namespace std;
/**
 * 从上到下打印二叉树
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
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        // 从上到下打印二叉树 其实就是层次遍历
        queue<TreeNode *> que;
        vector<int> ans;

        if (root == nullptr)
        {
            return ans;
        }
        que.emplace(root);

        while (!que.empty())
        {
            /* code */
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = que.front();
                if (temp->left != nullptr)
                {
                    que.emplace(temp->left);
                }
                if (temp->right != nullptr)
                {
                    que.emplace(temp->right);
                }
                que.pop();
                ans.push_back(temp->val);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}