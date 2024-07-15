#include <iostream>
#include <queue>

const int V = 5000;
extern int graph_len;

int dfs(int rGraph[V][V], int u, int sink, int minEdge, int visited[V]) {
    visited[u] = 1;
    if (u == sink) return minEdge;

    for (int v =1; v <= graph_len; v++){
        if (rGraph[u][v] > 0 && visited[v] == 0){
            int curr = dfs(rGraph, v, sink, std::min(minEdge, rGraph[u][v]), visited);

            if (curr != 0){
                rGraph[u][v] -= curr;
                rGraph[v][u] += curr;
                return curr;
            }
        }
    }
    return 0;
}

// 最大流算法
int Ford_Fulkerson(int graph[V][V], int s, int t)
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

    int maxFlow = 0;
    int visisted[V];

    while (1) {
        memset(visisted, 0, sizeof(visisted));

        int pathFlow = dfs(rGraph, s, t, INT_MAX, visisted);

        if (pathFlow == 0)
            return maxFlow;

        maxFlow += pathFlow;
    }
}
