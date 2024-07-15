#include <iostream>
#include <queue>

const int V = 5000;
extern int graph_len;

// bfs�ڲ���������������·����sΪԴ�㣬tΪ���
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // ���ڵ�ı��
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

            // �ڵ㻹δ�������Ҳ�����������0������Ե���ýڵ�
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // �����㱻��ǣ�˵������һ����Դ�㿪ʼ������·��
    return visited[t] == true;
}

// ������㷨
int Edmond_Karp(int graph[V][V], int s, int t)
{
    int u, v;
    int rGraph[V][V];   // rGraphΪ�������磬u->vΪʣ�����������v->uΪ��������

    for (u = 1; u <= graph_len; ++u)
    {
        for (v = 1; v <= graph_len; ++v)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];
    int max_flow = 0;

    // ��������·�������������Ͳ�������
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            // �ҵ�����·���ϵ���С����
            u = parent[v];
            path_flow = (path_flow < rGraph[u][v]) ? path_flow : rGraph[u][v];
        }

        // ���²�������
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // ���������
        max_flow += path_flow;
    }

    return max_flow;
}
