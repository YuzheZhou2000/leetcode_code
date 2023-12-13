#include <bits/stdc++.h>
using namespace std;
/**
 * 序列化和反序列化二叉树
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
    // 序列化操作任意，因此我们可以选择我们习惯的进行二叉树的重建
    //  这里我选择使用中序遍历和前序遍历来解决这个问题。
    char *Serialize(TreeNode *root)
    {
        // 如果是使用前序遍历和中序遍历来解决这个问题，首先我么需要知道
        // 中序遍历 遍历结果
        vector<int> middleOrder;

        return nullptr;
    }
    void middleVisit(vector<int> &vec, TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        middleVisit(vec, root->left);
        vec.push_back(root.val);
        middleVisit(vec, root->right);
    }
    TreeNode *Deserialize(char *str)
    {
        return nullptr;
    }
};
int main()
{
    char *a;
    cout << a;
    return 0;
}