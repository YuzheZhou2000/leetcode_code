#include <bits/stdc++.h>
using namespace std;

//面试题 04.01. 节点间通路
/*
 输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 输出：true
*/
class Solution
{
public:
    // 求两个节点之间是否存在通路
    // 首先使用邻接表存储有向图
    // 然后进行深度优先遍历搜素
    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target)
    {
        // 使用vector数据结构记录邻接表
        vector<vector<int>> outdegree;
        for (int i = 0; i < graph.size(); i++)
        {
            outdegree[graph[i][0]].push_back(graph[i][1]);
        }
        // 记录每个节点是否被遍历的时候访问到
        vector<bool> flagOfnode(n, false);

        // 使用队列保存访问顺序
        queue<int> que;

        // 开始进行广度优先搜索
        que.push(start);
        while (!que.empty())
        {
            int cur = que.front();
            if (cur == target)
            {
                return true;
            }
            // 获取当前节点的邻接表
            vector<int> visit_list = outdegree[cur];

            for (int i = 0; i < visit_list.size(); i++)
            {
                if (!flagOfnode[visit_list[i]])
                {
                    // 节点未被访问过
                    flagOfnode[visit_list[i]] = true;
                    // 依次将下一级节点压入队列
                    que.push(visit_list[i]);
                }
            }
            // 从队列中弹出此元素
            que.pop();
        }
        return false;
    }
};

// 面试题 04.02. 最小高度树
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution2
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        // 参数给到的是一个有序整数数组，元素各不相同且按升序排列，利用分治的思想构造高度最小的二叉搜索树
        int begin = 0;
        int end = nums.size() - 1;
        // 通过构造自定义函数进行递归
        return makeBST(begin, end, nums);
    }
    /**
     * @brief 递归构造二叉搜索树
     * 
     * @param begin 开始的数组位置
     * @param end  结束的数组位置
     * @param nums 给定的排序数组
     * @return ** TreeNode* 返回当前子树的根节点
     */

    TreeNode *makeBST(int begin, int end, vector<int> &nums)
    {

        if (begin > end)
        {
            return NULL;
        }

        int mid = (end + begin) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = makeBST(begin, mid - 1, nums);
        root->right = makeBST(mid + 1, end, nums);

        return root;
    }
};

int main()
{
    return 0;
}
