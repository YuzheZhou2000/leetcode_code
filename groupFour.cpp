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
class Solution
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

// 面试题 04.03. 特定深度节点链表

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    vector<ListNode *> listOfDepth(TreeNode *tree)
    {
        // 广度优先遍历  每一层构造一个链表
        vector<ListNode *> res;
        if (!tree)
        {
            return res;
        }

        // 广度优先遍历 使用队列保存每一层的节点
        queue<TreeNode *> que;
        TreeNode *tem;
        int size;
        // 将根节点压入队列
        que.push(tree);

        ListNode *head;
        ListNode *pre;

        // 队列不为空
        while (!que.empty())
        {
            head = NULL;
            size = que.size();
            // 遍历当前队列
            for (int i = 0; i < size; i++)
            {
                tem = que.front();
                que.pop();
                ListNode *nodeTem = new ListNode(tem->val);
                if (!head)
                {
                    head = nodeTem;
                    pre = head;
                }
                else
                {
                    pre->next = nodeTem;
                    pre = pre->next;
                }
                if (tem->left)
                {
                    que.push(tem->left);
                }
                if (tem->right)
                {
                    que.push(tem->right);
                }
            }
            res.push_back(head);
        }
        return res;
    }
};

// 面试题 04.04. 检查平衡性

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
    bool isBalanced(TreeNode *root)
    {
        /*
            本题主要考查平衡二叉树的定义及判断
            平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。        
        */

        // 使用递归的方法进行判断
        if (root == NULL)
        {
            // 如果树为空，返回true
            return true;
        }
        // 递归遍历树 判断每一颗子树是不是平衡二叉树
        return (abs(getDepth(root->right) - getDepth(root->left)) <= 1 && isBalanced(root->right) && isBalanced(root->left));
    }
    /**
     * @brief Get the Depth object of sub tree
     * 
     * @param root  树的根节点
     * @return ** int  子树的深度
     */
    int getDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 1;
        }
        int res;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
};

// 面试题 04.05. 合法二叉搜索树

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
    bool isValidBST(TreeNode *root)
    {
        // 如果是一个二叉搜索树，那么这棵树的中序遍历一定为一个递增的数组
        vector<int> vec;
        // 获取中序遍历数组
        lastVisit(root, vec);
        // 判断数组是否为递增数组,若是 则是一个二叉搜索树，若不是 返回false
        for (int size = vec.size() - 1; size > 0; size--)
        {
            if (vec[size] <= vec[size - 1])
            {
                return false;
            }
        }
        return true;
    }
    // 递归法中序遍历二叉树
    void lastVisit(TreeNode *root, vector<int> &vec)
    {
        if (root == NULL)
        {
            return;
        }
        lastVisit(root->left, vec);
        vec.push_back(root->val);
        lastVisit(root->right, vec);
    }
};

// 面试题 04.06. 后继者

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
    // 给定搜索二叉树，和其中的一个节点 判断本节点的下一个节点（按照中序遍历）
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        vector<TreeNode *> vec;
        lastVisit(root, vec);
        for (int i = 0; i < vec.size()-1; i++)
        {
            if (vec[i] == p)
            {
                return vec[i + 1];
            }
        }
        return NULL;
    }
    void lastVisit(TreeNode *root, vector<TreeNode *> &vec)
    {
        // 二叉树的中序遍历
        if (root == NULL)
        {
            return;
        }
        lastVisit(root->left, vec);
        vec.push_back(root);
        lastVisit(root->right, vec);
    }
};

//
int main()
{
    return 0;
}
