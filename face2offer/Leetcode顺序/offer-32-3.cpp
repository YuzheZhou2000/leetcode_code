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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector < vector<int> > res;

        // 层次遍历二叉树
        if (root == nullptr)
        {
            return res;
        }

        queue<TreeNode *> TreeNodeQueue;

        TreeNodeQueue.push(root);
        int order = 1;
        while (!TreeNodeQueue.empty())
        {
            /* code */
            int n = TreeNodeQueue.size();
            vector<int> temRes;
            for (int i = 0; i < n; i++)
            {                
                TreeNode *tem = TreeNodeQueue.front();
                TreeNodeQueue.pop();
                temRes.push_back(tem->val);
                if (tem->left != nullptr)
                    TreeNodeQueue.push(tem->left);
                if (tem->right != nullptr)
                    TreeNodeQueue.push(tem->right);
            }
            if(temRes.size() != 0){

                if (order % 2 == 0){
                    reverse(temRes.begin(),temRes.end());
                }
                res.emplace_back(temRes);
                order++;
            }
            
        }
        return res;
    }
};

int main()
{

    return 0;
}