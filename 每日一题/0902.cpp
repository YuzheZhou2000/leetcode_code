#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
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
    // �������ֵͬ·������
    int res;

    int longestUnivaluePath(TreeNode *root)
    {
        // ʹ��������ȱ����ķ��������������ֵͬ�·������
        res = 0;
        dfs(root);// ������ȱ���
        return res;
    }
    int dfs(TreeNode* root){
        // ������ȱ����ľ���ʵ��
        if(root == NULL){
            // ����Ϊ�� ֱ�ӷ���0
            return 0;
        }
        int left1 = 0;
        int right1 = 0;
        // �����������
        int left = dfs(root->left);
        int right = dfs(root->right);

        if(root->left && root->left->val == root->val){
            left1 = left + 1;
        }
        if(root->right && root->right->val == root->val){
            right1 = right + 1;
        }
        // ע�����������Ǳߵĸ���  �����ǽ��ĸ���
        res = max(res, left1 + right1);
        return max(left1, right1);
    }
};

int main()
{
    Solution s;

    return 0;
}