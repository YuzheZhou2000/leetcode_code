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
    bool myjudgeBST(vector<int> seq, int star, int end)
    {
        int i = star;
        for (; i < end; i++)
        {
            if (seq[i] > seq[end])
            {
                break;
            }
        }
        // 此时i位置为大于end的位置
        int j = i;
        for (; j < end; j++)
        {
            if (seq[j] < seq[end])
            {
                return false;
            }
        }
        // 讲道理此时j应该已经走到了end的位置

        // 下面递归开始判断左右子树是不是后序遍历

        bool left = true, right = true;
        if (i > star)
        {
            left = myjudgeBST(seq, star, i - 1);
        }
        if (i < end)
        {
            right = myjudgeBST(seq, i, end - 1);
        }
        return (left && right);
    }
};
int main()
{
    vector<int> test = {2};
    Solution s;
    bool ans = s.VerifySquenceOfBST(test);
    // bool ans = false;
    cout << "ans: " << ans;
    return 0;
}