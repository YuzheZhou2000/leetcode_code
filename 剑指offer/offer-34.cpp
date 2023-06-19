#include <bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
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
    vector<vector<int>> res;// 首先确定范围的数据类型
    void searchPath(vector<int> path, int sum, int target, TreeNode* root){
        // 首先判断当前值是不是满足要求
        if(sum == target){
            res.push_back(path);
            return;
        }
        if(root == nullptr){
            return;
        }
        sum += root->val;
        path.push_back(root->val);

        if(sum>target){
            return;
        }

        searchPath(path,sum,target,root->left);
        searchPath(path,sum,target,root->right);

    }

    void visitTree(TreeNode *root, int target){
        vector<int>tempath;
        searchPath(tempath,0,target,root);
        if(root->left!= nullptr){
            visitTree(root->left, target);
        }
        if(root->right != nullptr){
            visitTree(root->right, target);
        }
        
        
    }

    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
                
        // 遍历二叉树
        visitTree(root,target);                
        return res;
    }
};
int main()
{
    return 0;
}