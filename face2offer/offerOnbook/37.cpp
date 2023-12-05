# include <bits/stdc++.h>
using namespace std;
/**
 * 二叉树的深度
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int TreeDepth_v0(TreeNode* pRoot) {
        //直接一波层序遍历
        int ans = 0;
        if(pRoot == nullptr){
            return ans;
        }
        queue<TreeNode*> que;
        que.emplace(pRoot);
        while(!que.empty()){
            ans ++;
            int size = que.size();
            for (int i =0;i<size; i++ ){
                TreeNode * temp = que.front();
                que.pop();
                if (temp->left != nullptr) que.emplace(temp->left);
                if (temp ->right != nullptr) que.emplace(temp->right);
            }
        }return ans;
    }

    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr){
            return 0;
        }

        return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
    }
};


int main(){
    return 0;
}