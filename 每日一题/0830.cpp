#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    /*
    ��ԭ���������в��ң����ǵ���������������ɣ�����ʵ�ִ��������ע��
    ע�⹹�����⣬������Ķ���Ҫ��ÿ���ڵ��ֵ�������������е������κ�ֵ
    ���ΪʲôҪ��������������������Ϊ�¼����Val��������ĿҪ������ĩβ���и���ֵ
    ��˽��������������������������Ҫ��

    */
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            TreeNode *res = new TreeNode(val);
            return res;
        }
        TreeNode *parent = NULL;
        TreeNode *cur = root;
        // ��ԭ���������б������ҵ���Ӧ��Ŀ��ֵ
        while (cur)
        {
            if (cur->val < val)
            {
                // Ҫ�����Ŀ��ֵ���ô��ڵ�ǰ�ڵ�
                if (!parent)
                {
                    // ����Ϊԭ�����ĸ��ڵ� ��Ϊ�µĸ����  ֱ�ӷ���
                    TreeNode *res = new TreeNode(val, cur, NULL);
                    return res;
                }
                // ��ԭ�������ϵ��м䲿��
                // ����һ���µĽڵ㣬�ڵ��������Ϊԭ����Ŀ��ֵС������
                TreeNode *temp = new TreeNode(val);
                temp->left = cur;
                // ������Ϊԭ�����ڵ��������
                parent->right = temp;
                return root;
            }
            else
            {
                // ����������������
                parent = cur;
                cur = cur->right;
            }
        }
        // ԭ�������������ϵ�ֵ������Ŀ��ֵ��ֱ�ӽ�Ŀ��ֵ�������½ǽڵ���Ҳ�
        TreeNode *temp = new TreeNode(val);
        parent->right = temp;
        // ���շ���ԭ���Ķ���������
        return root;
    }
};
int main()
{
    return 0;
}
