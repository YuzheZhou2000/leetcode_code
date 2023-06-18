# include <bits/stdc++.h>

using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:

    bool cheackTree(TreeNode* tree1, TreeNode* tree2){
        if(tree1 == nullptr && tree2 == nullptr){
            return true;
        }
        if (tree1 == nullptr || tree2 == nullptr){
            return false;
        }

        return (tree1->val == tree2->val) && cheackTree(tree1->left,tree2->right) && cheackTree(tree1->right, tree2->left);

    }

    bool isSymmetric(TreeNode* root) {
        
        return cheackTree(root,root);

    }
};


int main(){

    return 0;
}