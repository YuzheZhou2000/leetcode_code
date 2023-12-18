#include <bits/stdc++.h>
using namespace std;
/**
 * 本文件旨在实现一颗二叉搜索树
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 首先给一个查询的操作
TreeNode *search(TreeNode *root, int val)
{

    while (root != nullptr)
    {
        if (root->val == val)
            return root;
        else if (root->val > val)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// 给一个层序遍历的操作
void visitLevel(TreeNode *root)
{
    cout << "level visit:" << endl;
    if (root == nullptr)
        return;
    queue<TreeNode *> que;
    que.emplace(root);

    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *tem = que.front();
            que.pop();
            if (tem->left != nullptr)
                que.emplace(tem->left);
            if (tem->right != nullptr)
                que.emplace(tem->right);
            cout << tem->val << "  ";
        }
        cout << endl;
    }
}

// 插入一个元素
TreeNode *insertNode(TreeNode *root, int val)
{
    TreeNode *tem = new TreeNode(val);
    TreeNode *ans = root;

    if (root == nullptr)
        return tem;
    while (root != nullptr)
    {
        if (val < root->val && root->left != nullptr)
        {
            root = root->left;
        }
        else if (val >= root->val && root->right != nullptr)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    if (root->val > val)
    {
        root->left = tem;
    }
    else
    {
        root->right = tem;
    }
    return ans;
}

// 删除一个元素
TreeNode *deleteNode(TreeNode *root, int val)
{
    // 需要记录这个父亲节点
    TreeNode *cur = root, *curParent = nullptr;
    while (cur != nullptr && cur->val != val)
    {
        curParent = cur;
        if (cur->val > val)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    if (cur == nullptr)
    {
        // 这时候没有找到目标元素
        return root;
    }

    // 分情况讨论
    if (cur->left == nullptr && cur->right == nullptr)
    {
        // 目标值是叶子节点
        cur = nullptr;
    }
    else if (cur->left == nullptr && cur->right != nullptr)
    {
        // 目标节点只有右子树，右子树提前
        cur = cur->right;
    }
    else if (cur->left != nullptr && cur->right == nullptr)
    {
        // 目标节点只有左子树，左子树提前
        cur = cur->left;
    }
    else
    {
        // 左右都有节点，这是一个中间节点
        // 我们要做的可以寻找左子树的最大元素，进行一波替换
        TreeNode *tem = cur->left, *pparent = cur;
        while (tem->right != nullptr)
        {
            pparent = tem;
            tem = tem->right;
        }
        // 这时候找到目标节点的最右侧的节点 tem 以及他的父节点 pprent
        if (pparent->val == cur->val)
        {
            // 本循环表示没有往下走
            pparent->left = tem->left;
        }
        else
        {

            pparent->right = tem->left;
        }

        tem->right = cur->right;
        tem->left = cur->left;
        cur = tem;
    }

    if (curParent == nullptr)
    {
        return cur;
    }
    else
    {
        if (curParent->left && curParent->left->val == val)
        {
            curParent->left = cur;
        }
        else
        {
            curParent->right = cur;
        }
    }

    return root;
}
int main()
{
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(13);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node6 = new TreeNode(10);
    TreeNode *node7 = new TreeNode(15);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    // node3->right = node7;
    //  层序访问
    visitLevel(node1);

    // 查询
    TreeNode *ans = search(node1, 1);
    if (ans == nullptr)
        cout << "no find" << endl;
    else
        cout << "val: " << ans->val << endl;

    // 插入
    node1 = insertNode(node1, 15);

    visitLevel(node1);

    // 删除
    node1 = deleteNode(node1, 13);
    visitLevel(node1);

    return 0;
}