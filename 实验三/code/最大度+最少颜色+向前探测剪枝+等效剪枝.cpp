#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int vertices, edges;  // vertices为顶点数，edges为边数
int ans = 0; // 答案
int num_color = 5; // 用于填色的颜料个数
int color[500];     // 每个顶点的涂色
int solution[500][50];   // 每个顶点剩余可填涂颜色
int Feasible_solution[500];     // 每个顶点剩余可涂颜色个数
int available_color[50];

// 边的结构体
struct Edge {
    int dest;       // 边的终点
    Edge* next;
};

struct Head {
    int id;         // 该顶点的标号
    int degree;     // 该顶点的度
    Edge* next;
    Head() : id(0), degree(0), next(nullptr) {}
};

int cmp(const Head a, const Head b) {
    if (Feasible_solution[a.id] != Feasible_solution[b.id]) return Feasible_solution[a.id] < Feasible_solution[b.id];
    else return a.degree > b.degree;
    //return a.degree > b.degree;
    //return Feasible_solution[a.id] < Feasible_solution[b.id];

}

class Graph {
public:
    int numVertices;
    Head* head;

    // 构造函数
    Graph(int V) : numVertices(V) {
        head = new Head[V + 1];
        for (int i = 1; i <= V; ++i) {
            head[i].id = i;
        }
    }

    // 添加边
    void addEdge(int src, int dest) {
        Edge* newEdge = new Edge;
        newEdge->dest = dest;
        newEdge->next = head[src].next;
        head[src].next = newEdge;
        head[src].degree += 1;

        // 因为是无向图，所以需要添加反向边
        newEdge = new Edge;
        newEdge->dest = src;
        newEdge->next = head[dest].next;
        head[dest].next = newEdge;
        head[dest].degree += 1;
    }

    // 析构函数
    ~Graph() {
        for (int i = 0; i <= numVertices; ++i) {
            Edge* current = head[i].next;
            while (current) {
                Edge* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] head;
    }
};

long long dfs(int x, Graph& graph) {
    if (x > vertices) {
        return 1;
    }

    // MRV或DH排序
    sort(graph.head + x, graph.head + 1 + vertices, cmp);
    long long ans = 0;
    int flag1;
    int flag2 = 1;
    int cnt_of_available_color = 0;
    int id = graph.head[x].id;
    for (int i = 1; i <= num_color; ++i) {
        if (!available_color[i] && !solution[id][i]) cnt_of_available_color += 1;
    }
    for (int i = 1; i <= num_color; ++i) {
        if (solution[id][i]) continue;  // 该颜色无法填涂
        if (!flag2 && !available_color[i]) continue;
        color[id] = i;
        flag1 = 1;
        Edge* edge = graph.head[x].next;

        // 检测填色是否符合要求
        while (edge) {
            if (color[edge->dest] == color[id]) {
                flag1 = 0;
                break;
            }
            if (!solution[edge->dest][i] && Feasible_solution[edge->dest] - 1 == 0) {
                flag1 = 0;
                break;
            }
            edge = edge->next;
        }
        if (flag1) {
            // 减少邻接点的解
            edge = graph.head[x].next;
            while (edge) {
                if (!color[edge->dest] && !solution[edge->dest][i]) {
                    solution[edge->dest][i] = x;
                    Feasible_solution[edge->dest] -= 1;
                }
                edge = edge->next;
            }
            
            if (flag2 && !available_color[i]) {
                available_color[i] += 1;
                flag2 = 0;
                ans += cnt_of_available_color * dfs(x + 1, graph);
            }
            else {
                available_color[i] += 1;
                ans += dfs(x + 1, graph);
            }
            available_color[i] -= 1;
            if (ans > 1000) return ans;
            // 恢复邻接点的解
            edge = graph.head[x].next;
            while (edge) {
                if (!color[edge->dest] && solution[edge->dest][i] == x) {
                    solution[edge->dest][i] = 0;
                    Feasible_solution[edge->dest] += 1;
                }
                edge = edge->next;
            }
        }
        else continue;
    }
    color[id] = 0;
    return ans;
}

int main() {
    //freopen("le9_4.txt", "r", stdin);
    freopen("le450_5a.txt", "r", stdin);
    //freopen("le450_15b.txt", "r", stdin);
    //freopen("le450_25a.txt", "r", stdin);
    num_color = 5;
    cin >> vertices >> edges;
    Graph graph(vertices);
    memset(color, 0, sizeof(color));
    memset(solution, 0, sizeof(solution));
    memset(solution, 0, sizeof(available_color));
    for (int i = 1; i <= vertices; ++i) {
        Feasible_solution[i] = num_color;
    }
    for (int i = 1; i <= edges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);   // 建图
    }

    clock_t StartTime, EndTime; //定义计时开始和计时结束变量
    double time;        // 记录运行时间			
    StartTime = clock();    //开始计时
    ans = dfs(1, graph);
    EndTime = clock();      //结束计时
    time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为毫秒
    printf("Solutions: %d\n", ans);
    printf("Time: %.6lf s\n", time);
    return 0;
}
