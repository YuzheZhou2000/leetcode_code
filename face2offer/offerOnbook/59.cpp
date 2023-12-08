#include <bits/stdc++.h>
using namespace std;
/**
 * 将二叉树打印成多行
 */
/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        // write code here            // write code here
        // 首先可以知道的是一个层序遍历问题
        // 题目中给出了第一层从左向右，下一层从右向左，一直这样交替
        // 因此可以知道第一层是一个正常的序列，其实每一层可以使用vector保存
        // 如果需要逆序 直接resver即可
        vector<vector<int>> ans;
        if (pRoot == nullptr)
        {
            return ans;
        }
        queue<TreeNode *> que;
        que.emplace(pRoot);
        while (!que.empty())
        {
            /* code */
            vector<int> temVec;
            TreeNode *tempNode = nullptr;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                tempNode = que.front();
                que.pop();
                temVec.push_back(tempNode->val);
                if (tempNode->left != nullptr)
                    que.emplace(tempNode->left);
                if (tempNode->right != nullptr)
                    que.emplace(tempNode->right);
            }

            ans.push_back(temVec);
        }
        return ans;
    }
};
int main(() {
    return 0;
})