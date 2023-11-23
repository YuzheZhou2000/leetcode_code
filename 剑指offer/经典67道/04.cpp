#include <bits/stdc++.h>
using namespace std;

/***
 * 根据两个遍历结果重建二叉树
 */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param preOrder int整型vector
     * @param vinOrder int整型vector
     * @return TreeNode类
     */
    // TreeNode *reConstructBinaryTree(vector<int> &preOrder, vector<int> &vinOrder)
    // {
    //     // write code here
    //     // 二叉树的重建  首先可以使用递归的方法解决
    //     int lenght = preOrder.size();
    //     if (lenght == 0)
    //     {
    //         return nullptr;
    //     }
    //     return bulidTree(preOrder, vinOrder, 0, lenght - 1, 0, lenght - 1);
    // }

    // // 通过递归得到二叉树
    // TreeNode *bulidTree(vector<int> &preOrder, vector<int> &vinOrder, int star_per, int end_per, int star_vin, int end_vin)
    // {
    //     if (end_vin >= star_vin)
    //     {
    //         // 根节点肯定是前序遍历的第一个元素
    //         TreeNode *root = new TreeNode(preOrder[star_per]);

    //         // 下一步开始寻找根节点在中序遍历中的index
    //         int index = star_vin;
    //         for (; index < end_vin; index++)
    //         {
    //             if (vinOrder[index] == preOrder[star_per])
    //             {
    //                 break;
    //             }
    //         }
    //         // 这时候得到了根节点在中序遍历中的index
    //         int len_left = index - star_vin;
    //         root->left = bulidTree(preOrder, vinOrder, star_per + 1, star_per + len_left, star_vin, index - 1);
    //         root->right = bulidTree(preOrder, vinOrder, star_per + len_left + 1, end_per, index + 1, end_vin);
    //         return root;
    //     }
    //     return nullptr;
    // }

    TreeNode *reConstructBinaryTree(vector<int> &preOrder, vector<int> &vinOrder)
    {
        // write code here
        // 二叉树的重建  首先可以使用递归的方法解决
        int lenght = preOrder.size();
        if (lenght == 0)
        {
            return nullptr;
        }
        // 引入hash进行加速，可以记录在中序遍历中 出现的位置
        unordered_map<int, int> indexMap;
        for (int i = 0; i < lenght; i++)
        {
            indexMap.emplace(vinOrder[i], i);
        }
        cout << "zhouyuze";
        return bulidTree(indexMap, preOrder, vinOrder, 0, lenght - 1, 0, lenght - 1);
    }

    // 通过递归得到二叉树
    TreeNode *bulidTree(unordered_map<int, int> &indexMap, vector<int> &preOrder, vector<int> &vinOrder, int star_per, int end_per, int star_vin, int end_vin)
    {
        if (end_vin >= star_vin)
        {
            // 根节点肯定是前序遍历的第一个元素
            TreeNode *root = new TreeNode(preOrder[star_per]);

            // 直接通过已经存储的hash表进行检索
            int index = indexMap[preOrder[star_per]];

            // 这时候得到了根节点在中序遍历中的index
            int len_left = index - star_vin;
            root->left = bulidTree(indexMap, preOrder, vinOrder, star_per + 1, star_per + len_left, star_vin, index - 1);
            root->right = bulidTree(indexMap, preOrder, vinOrder, star_per + len_left + 1, end_per, index + 1, end_vin);
            return root;
        }
        return nullptr;
    }
};
int main()
{
    Solution s;
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *root = s.reConstructBinaryTree(pre, vin);
    cout << "2222";
    return 0;
}