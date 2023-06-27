#include <bits/stdc++.h>

using namespace std;

/*
    剑指 Offer II 118. 多余的边

    树可以看成是一个连通且 无环 的 无向 图。
    给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。
    添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。
    图的信息记录于长度为 n 的二维数组 edges ，
    edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。
    请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。
    如果有多个答案，则返回数组 edges 中最后出现的边。
*/
class Solution
{
public:
    // 使用并查集对本题目进行求解首先需要确定合并和查找操作

    int find(vector<int> &parent, int index)
    {
        // 查找操作 查找index的祖先节点

        while (parent[index] != index)
        {
            index = parent[index];
        }
        return parent[index];
    }

    void my_union(vector<int> &parent, int index_1, int index_2)
    {
        // 首先分别找到两个节点的父亲节点
        int parent_1 = find(parent, index_1);
        int parent_2 = find(parent, index_2);

        // 将两个父亲节点归纳到同一个集合
        parent[parent_1] = parent_2;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        // 对于本题目而言，如果存在属于同一个连通分量的两条边，那么即为所求

        int n = edges.size(); // 记录一共存在的边的个数

        vector<int> parent(n + 1); // 记录每一个节点的父亲节点

        for (int i = 1; i <= n; i++)
        {
            // 首先将每一个节点的父亲节点设置为自己
            parent[i] = i;
        }

        // 开始遍历查找，对于每一个边，判断两个节点的父亲节点是不是同一个节点，如果是，
        // 那么这个边即为所求

        for (const auto &edge : edges)
        {
            int node1 = edge[0];
            int node2 = edge[1];

            // 查找两个节点的父亲节点
            if (find(parent, node1) != find(parent, node2))
            {
                // 如果不属于同一个连通分量，则合并两个节点
                my_union(parent, node1, node2);
            }
            else
            {
                return edge;
            }
        }
        return vector<int>{};
    }
};

int main()
{
    return 0;
}