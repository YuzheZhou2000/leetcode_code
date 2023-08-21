#include <bits/stdc++.h>

using namespace std;

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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        // 求二叉树的深度 直接使用queue记录二叉树的每一层，进行非迭代方式的遍历即可。
        queue<TreeNode *> layerNode;
        layerNode.push(root);
        int ans = 0;

        while (!layerNode.empty())
        {
            ans++;
            int size = layerNode.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temNode = layerNode.front();
                layerNode.pop();
                if (temNode->left != nullptr)
                {
                    layerNode.push(temNode->left);
                }
                if (temNode->right != nullptr)
                {
                    layerNode.push(temNode->right);
                }
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}