#include <iostream>
#include <queue>

const int V = 5000;
extern int graph_len;
int layer[V];

bool bfs(int rGraph[V][V], int s, int t)
{
    memset(layer, -1, sizeof(layer));
    std::queue<int> q;
    q.push(s);
    layer[s] = 0;

    int u;
    while (!q.empty()) {

        u = q.front();
        q.pop();
        for (int v = 1; v <= graph_len; ++v) {

            if (layer[v] == -1 && rGraph[u][v] > 0) {
                q.push(v);
                layer[v] = layer[u] + 1;
            }
        }
    }

    return layer[t] != -1;
}
int dfs(int rGraph[V][V], int u, int t, int minEdge) {
    int tmp = minEdge;  // tmp相当于当前节点流入的量
    if (u == t) return minEdge;

    for (int v =1; v <= graph_len && tmp; v++){
        if (layer[v] == layer[u] + 1 && rGraph[u][v] > 0){
            int curr = dfs(rGraph, v, t, std::min(tmp, rGraph[u][v]));  // 流出了curr的量
            rGraph[u][v] -= curr;
            rGraph[v][u] += curr;
            tmp -= curr;
        }
    }
    return minEdge - tmp;   // 若没流出，说明没路，返回0
}


int Dinic(int graph[V][V], int s, int t) {

    int rGraph[V][V];   // rGraph为残留网络，u->v为剩余可用流量，v->u为回退流量

    for (int u = 1; u <= graph_len; ++u)
    {
        for (int v = 1; v <= graph_len; ++v)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    int max_flow = 0, tf = 0;
    while (bfs(rGraph, s, t)) {
        while (tf = dfs(rGraph, s, t, INT_MAX)) {
            max_flow += tf;
        }
    }
    return max_flow;
}

