#include <bits/stdc++.h>
using namespace std;
/**给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return root;
        }

        // 因为时寻找最近的祖先节点，因此肯定是两个元素的从根节点到两个指定节点的分叉口(给定的是一个二叉搜索树)

        // 开始遍历搜索
        TreeNode* curNode = root;
        while (curNode!= nullptr)
        {
            if(curNode->val > p->val && curNode->val > q->val){
                curNode = curNode->left;
            }
            else if(curNode->val < p->val && curNode->val < q->val){
                curNode = curNode->right;
            }
            else{
                break;
            }
        }
        return curNode;
    }
};
int main()
{
    return 0;
}