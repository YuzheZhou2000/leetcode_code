#include <bits/stdc++.h>

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
    int res = 0;
    int pathSum(TreeNode *root, int targetSum)
    {
        if(root == nullptr){
            return 0;
        }
        visitTree(root, targetSum);

        // res ++;
        return res;
    }

    void visitTree(TreeNode *root, int targetSum)
    {

        getPathSum(root, targetSum, 0);
        if (root->left != nullptr)
        {
            visitTree(root->left, targetSum);
        }

        if (root->right != nullptr)
        {
            visitTree(root->right, targetSum);
        }
    }

    void getPathSum(TreeNode *root, int targetSum, long long temSum)
    {
        // 注意第三个参数
        
        // 从root开始遍历
        if (root != nullptr)
        {
            temSum += root->val;
        }
        else
        {
            return;
        }
        if (temSum == targetSum)
        {
            res++;
        }
        getPathSum(root->left, targetSum, temSum);
        getPathSum(root->right, targetSum, temSum);
    }
};
using namespace std;

int main()
{
    
    Solution s;
    int a = s.pathSum(nullptr, 0);
    cout << a;
    return 0;
}