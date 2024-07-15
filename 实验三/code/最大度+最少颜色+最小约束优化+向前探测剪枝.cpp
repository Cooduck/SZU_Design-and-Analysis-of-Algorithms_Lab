//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//#define INF 0x3f3f3f3f
//using namespace std;
//
//int vertices, edges;  // vertices为顶点数，edges为边数
//int ans = 0; // 答案
//int num_color; // 用于填色的颜料个数
//int color[500];     // 每个顶点的涂色
//int solution[500][50];   // 每个顶点剩余可填涂颜色
//int Feasible_solution[500];     // 每个顶点剩余可涂颜色个数
//
//// 边的结构体
//struct Edge {
//    int dest;       // 边的终点
//    Edge* next;
//};
//
//struct Head {
//    int id;         // 该顶点的标号
//    int degree;     // 该顶点的度
//    Edge* next;
//    Head() : id(0), degree(0), next(nullptr) {}
//};
//
//struct node {
//    int color_id;
//    int cost;
//};
//
//struct ComparePairs {
//    bool operator()(const node& a, const node& b) const {
//        return a.cost > b.cost;
//    }
//};
//
//int cmp(const Head a, const Head b) {
//    if (Feasible_solution[a.id] != Feasible_solution[b.id]) return Feasible_solution[a.id] < Feasible_solution[b.id];
//    else return a.degree > b.degree;
//}
//
//class Graph {
//public:
//    int numVertices;
//    Head* head;
//
//    // 构造函数
//    Graph(int V) : numVertices(V) {
//        head = new Head[V + 1];
//        for (int i = 1; i <= V; ++i) {
//            head[i].id = i;
//        }
//    }
//
//    // 添加边
//    void addEdge(int src, int dest) {
//        Edge* newEdge = new Edge;
//        newEdge->dest = dest;
//        newEdge->next = head[src].next;
//        head[src].next = newEdge;
//        head[src].degree += 1;
//
//        // 因为是无向图，所以需要添加反向边
//        newEdge = new Edge;
//        newEdge->dest = src;
//        newEdge->next = head[dest].next;
//        head[dest].next = newEdge;
//        head[dest].degree += 1;
//    }
//
//    // 析构函数
//    ~Graph() {
//        for (int i = 0; i <= numVertices; ++i) {
//            Edge* current = head[i].next;
//            while (current) {
//                Edge* temp = current;
//                current = current->next;
//                delete temp;
//            }
//        }
//        delete[] head;
//    }
//};
//
//// 检验结果是否正确
//int check(Graph& graph) {
//    int flag = 1;
//    for (int i = 1; i <= vertices; ++i) {
//        Edge* p = graph.head[i].next;
//        int id = graph.head[i].id;
//        while (p) {
//            if (color[id] == color[p->dest]) {
//                return 0;
//            }
//            p = p->next;
//        }
//    }
//    return 1;
//}
//
//void dfs(int x, Graph& graph) {
//    if (x > vertices) {
//        if (check(graph))ans++;
//        return;
//    }
//
//    sort(graph.head + x, graph.head + 1 + vertices, cmp);
//    int flag;
//    int id = graph.head[x].id;
//    int cost;
//    Edge* edge;
//    priority_queue<node, vector<node>, ComparePairs> q;
//    for (int i = 1; i <= num_color; ++i) {
//        if (solution[id][i]) continue;  // 该颜色无法填涂
//        color[id] = i;
//        flag = 1;
//        cost = 0;
//        edge = graph.head[x].next;
//
//        while (edge) {
//            if (color[edge->dest] == color[id]) {
//                flag = 0;
//                break;
//            }
//            if (!solution[edge->dest][i] && Feasible_solution[edge->dest] - 1 == 0) {
//                flag = 0;
//                break;
//            }
//            edge = edge->next;
//        }
//        if (flag) {
//
//            edge = graph.head[x].next;
//            while (edge) {
//                if (!color[edge->dest] && !solution[edge->dest][i]) {
//                    cost++;
//                }
//                edge = edge->next;
//            }
//            q.push({ i, cost });
//        }
//        else continue;
//    }
//
//    while (!q.empty()) {
//        int chose_color = q.top().color_id;
//        q.pop();
//        // 减少邻接点的解
//        color[id] = chose_color;
//        edge = graph.head[x].next;
//        while (edge) {
//            if (!color[edge->dest] && !solution[edge->dest][chose_color]) {
//                solution[edge->dest][chose_color] = x;
//                Feasible_solution[edge->dest] -= 1;
//            }
//            edge = edge->next;
//        }
//        //cout << x << endl;
//        dfs(x + 1, graph);
//        if (ans > 0)return;
//
//        // 恢复邻接点的解
//        edge = graph.head[x].next;
//        while (edge) {
//            if (!color[edge->dest] && solution[edge->dest][chose_color] == x) {
//                solution[edge->dest][chose_color] = 0;
//                Feasible_solution[edge->dest] += 1;
//            }
//            edge = edge->next;
//        }
//    }
//    color[id] = 0;
//}
//
//int main() {
//    //freopen("le9_4.txt", "r", stdin);
//    freopen("le450_5a.txt", "r", stdin);
//    //freopen("le450_15b.txt", "r", stdin);
//    //freopen("le450_25a.txt", "r", stdin);
//    num_color = 5;
//    cin >> vertices >> edges;
//    Graph graph(vertices);
//    memset(color, 0, sizeof(color));
//    memset(solution, 0, sizeof(solution));
//    for (int i = 1; i <= vertices; ++i) {
//        Feasible_solution[i] = num_color;
//    }
//    for (int i = 1; i <= edges; ++i) {
//        int src, dest;
//        cin >> src >> dest;
//        graph.addEdge(src, dest);   // 建图
//    }
//
//    clock_t StartTime, EndTime; //定义计时开始和计时结束变量
//    double time;        // 记录运行时间			
//    StartTime = clock();    //开始计时
//
//    dfs(1, graph);
//    EndTime = clock();      //结束计时
//    time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为毫秒
//    printf("Solutions: %d\n", ans);
//    printf("Time: %.6lf s\n", time);
//
//
//    return 0;
//}