# include <bits/stdc++.h>
using namespace std;
/**
 * 翻转二叉树问题
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
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        // 本科找实习的面试的第一轮的第一道面试题目
        // 使用递归的方法进行，可以简单快速的完成本工作
        if(pRoot == nullptr){
            return nullptr;
        }
        TreeNode * temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        pRoot->left = Mirror(pRoot->left);
        pRoot->right = Mirror(pRoot->right);
        return pRoot;
    }
};
int main(){
    return 0;
}