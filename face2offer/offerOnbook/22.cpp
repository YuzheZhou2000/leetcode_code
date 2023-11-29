#include <bits/stdc++.h>
using namespace std;
/**
 * 判断是不是二叉搜索树的后序遍历
 */
class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        // 能想到的结果就是判断左右两侧是不是都是
        // 因为根节点肯定是在最后一个位置上的
        if (sequence.size() == 0)
        {
            return false;
        }
        return myjudgeBST(sequence, 0, sequence.size() - 1);
    }
    bool myjudgeBST(vector<int> sequence, int star, int end)
    {
        if (star + 1 >= end)
        {
            return true;
        }
        // 寻找左右子树
        int index_1 = -3, index_2 = -3;
        for (int i = star; i <= end; i++)
        {
            if (sequence[i] > sequence[end])
            {
                index_1 = i;
                break;
            }
        }
        // 后面的应该都是右子树了
        for (int i = end; i > -star; i--)
        {
            if (sequence[i] < sequence[end])
            {
                index_2 = i;
                break;
            }
        }
        if (index_2 + 1 == index_1)
        {
            return true && myjudgeBST(sequence, star, index_2) && myjudgeBST(sequence, index_1, end - 1);
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    vector<int> te1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> test = te1.assign(te1.begin() + 1, te1.end());
    for (auto &i : test)
    {
        cout << ' ' << i;
    }
    return 0;
}