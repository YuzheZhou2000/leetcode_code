#include <bits/stdc++.h>
using namespace std;
/**
 * 二叉树中和为某一值的路径
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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param target int整型
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ans;
    vector<vector<int>> FindPath(TreeNode *root, int target)
    {
        // write code here
        vector<int> vec;
        MyFindPath(vec, 0, root, target);

        return ans;
    }
    void MyFindPath(vector<int> vec, int sum, TreeNode *root, int targer)
    {
        sum += root->val;

        // 本剪枝方法不可取 因为可能会存在负数的情况
        // if (sum > targer)
        //     return;
        vec.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            // 到了叶子节点
            if (sum == targer)
                ans.push_back(vec);
            return;
        }
        if (root->left != nullptr)
            MyFindPath(vec, sum, root->left, targer);
        if (root->right != nullptr)
            MyFindPath(vec, sum, root->right, targer);
    }
};
int main()
{
    return 0;
}