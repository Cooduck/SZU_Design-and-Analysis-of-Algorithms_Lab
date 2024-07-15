#include <iostream>
#include <queue>

const int V = 5000;
extern int graph_len;

// bfs在残留网络中找增广路径，s为源点，t为汇点
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // 各节点的标记
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    int u;
    int flag = 0;
    while (!q.empty()) {

        u = q.front();
        q.pop();
        for (int v = 1; v <= graph_len; ++v) {

            // 节点还未遍历并且残留容量大于0，则可以到达该节点
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // 如果汇点被标记，说明存在一条从源点开始的增广路径
    return visited[t] == true;
}

// 最大流算法
int Edmond_Karp(int graph[V][V], int s, int t)
{
    int u, v;
    int rGraph[V][V];   // rGraph为残留网络，u->v为剩余可用流量，v->u为回退流量

    for (u = 1; u <= graph_len; ++u)
    {
        for (v = 1; v <= graph_len; ++v)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];
    int max_flow = 0;

    // 存在增广路径则更新最大流和残留网络
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            // 找到增广路径上的最小流量
            u = parent[v];
            path_flow = (path_flow < rGraph[u][v]) ? path_flow : rGraph[u][v];
        }

        // 更新残留网络
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // 更新最大流
        max_flow += path_flow;
    }

    return max_flow;
}
