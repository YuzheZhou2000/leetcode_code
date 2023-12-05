# include <bits/stdc++.h>
using namespace std;
/**
 * 判断是不是平衡二叉树
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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return bool布尔型
     */
    bool IsBalanced_Solution(TreeNode* pRoot) {
        // write code here
        int ans = TreeDepth(pRoot);
        if (ans == -1) return false;
        return true;


    }
    int TreeDepth(TreeNode * pRoot){
        if (pRoot == nullptr){
            return 0;
        }
        int leftDepth = TreeDepth(pRoot->left);
        int rightDepth = TreeDepth(pRoot->right);
        if (leftDepth == -1 || rightDepth == -1|| (abs(leftDepth - rightDepth) > 1)){
            return -1;
        }
        return 1 + max(leftDepth, rightDepth);
    }
};
int main(){
    return 0;
}