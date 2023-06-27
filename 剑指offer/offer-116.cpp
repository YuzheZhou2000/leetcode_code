#include <bits/stdc++.h>

using namespace std;

/**
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，
 * 且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
 * 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
 * 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和
 * 第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
 * 返回矩阵中 省份 的数量。
 */
class Solution
{
public:
    int find(vector<int> &parent, int index)
    {
        while (parent[index] != index)
        {
            index = parent[index];
        }
        return parent[index];
    }

    void my_union(vector<int> &parent, int index_1, int index_2)
    {
        int father_1 = find(parent, index_1);
        int father_2 = find(parent, index_2);

        parent[father_1] = father_2;
    }

    // 使用并查集的方法求解本体
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // 首先获得城市的个数
        int n = isConnected.size();
        int res = n; // 初始化时每一个城市都是一个省份

        // 开辟记录parent数组
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++)
        {
            // 初始化父亲节点为本身
            parent[i] = i;
        }

        // 对每一个
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                // 矩阵是对称的 遍历一半即可
                if (isConnected[i][j] == 1)
                {
                    if (find(parent, i) != find(parent, j))
                    {
                        my_union(parent, i, j);
                        res--;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}