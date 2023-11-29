#include <bits/stdc++.h>
using namespace std;
/**
 * 二叉树中和为某一值的路径
 */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param target int整型
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ans;
    vector<vector<int>> FindPath(TreeNode *root, int target)
    {
        // write code here

        return ans;
    }
};
int main()
{
    return 0;
}