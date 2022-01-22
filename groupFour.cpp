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
        for (auto &g : graph)
        {
            outdegree[g[0]].push_back(g[1]);
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
int main()
{
    return 0;
}
