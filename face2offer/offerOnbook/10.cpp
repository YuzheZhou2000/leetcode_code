#include <bits/stdc++.h>
using namespace std;
/**
 * 矩阵覆盖问题
 * 我们可以用 2*1 的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用 n 个 2*1 的小矩形无重叠地覆盖一个 2*n 的大矩形，
 * 从同一个方向看总共有多少种不同的方法？
 */

class Solution
{
public:
    int rectCover(int number)
    {
        // 因为需要2* n的矩阵，因此矩阵的宽一直都是2  只是在长的维度上进行了改变
        if (number <= 2)
        {
            return number;
        }
        // 这里其实还是一个斐波那契数列问题
        int val_1 = 2;
        int val_2 = 1;
        int ans;

        for (int i = 2; i < number; i++)
        {
            ans = val_2 + val_1;
            val_2 = val_1;
            val_1 = ans;
        }
        return ans;
    }
};
int main()
{
    return 0;
}