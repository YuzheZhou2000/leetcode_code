#include <bits/stdc++.h>
using namespace std;

/**
 * 二维数组的查找
 * 可以看成是一个二叉树进行查找
 * 每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。
 * 因此可以从左下角进行查找
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param target int整型
     * @param array int整型vector<vector<>>
     * @return bool布尔型
     */
    // bool Find(int target, vector<vector<int>> &array)
    // {
    //     // write code here
    //     int row = array.size();
    //     if (row == 0)
    //     {
    //         return false;
    //     }
    //     int col = array[0].size();

    //     int i = row - 1;
    //     int j = 0;
    //     while (i >= 0 && j < col)
    //     {
    //         // 注意这里跳出循环的条件，我们从左下角开始遍历，到右上角结束
    //         if (array[i][j] == target)
    //         {
    //             return true;
    //         }
    //         else if (array[i][j] > target)
    //         {
    //             i--;
    //         }
    //         else
    //         {
    //             j++;
    //         }
    //     }

    //     return false;
    // }

    bool Find(int target, vector<vector<int>> &array)
    {
        int row = array.size();
        for (int i = 0; i < row; i++)
        {
            bool tem = find_mid(target, array[i]);
            if (tem == true)
            {
                return true;
            }
        }
        return false;
    }

    bool find_mid(int target, vector<int> &array)
    {
        // 二分查找怎么写  首先确定两个边界值
        int star = 0;
        int end = array.size() - 1;

        while (end >= star)
        {
            /* code */
            int mid = star + (end - star) / 2;
            if (array[mid] == target)
            {
                return true;
            }
            else if (array[mid] > target)
            {
                // 因为每一行是从左到右递增
                end = mid - 1;
            }
            else
            {
                star = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int target = 2;
    vector<vector<int>> arr(1, vector<int>(2, 1));
    bool res = s.Find(target, arr);
    cout << res;
    return 0;
}