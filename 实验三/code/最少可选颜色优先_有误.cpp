//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//#define INF 0x3f3f3f3f
//using namespace std;
//
//int vertices, edges;  // vertices为顶点数，edges为边数
//int ans = 0; // 答案
//int num_color = 4; // 用于填色的颜料个数
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
//Head tmp_arr[500];
//
//int cmp(const Head a, const Head b) {
//    if (Feasible_solution[a.id] != Feasible_solution[b.id]) return Feasible_solution[a.id] < Feasible_solution[b.id];
//    else return a.degree > b.degree;
//    //return a.degree > b.degree;
//    //return Feasible_solution[a.id] < Feasible_solution[b.id];
//
//}
//
//struct node {
//    int id;
//    int available_color;
//};
//
//struct ComparePairs {
//    bool operator()(const node& a, const node& b) const {
//        return a.available_color > b.available_color;
//    }
//};
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
//void dfs(int id, Graph& graph, int done) {
//
//    int flag;
//    int available_color;
//    Edge* edge;
//    for (int i = 1; i <= num_color; ++i) {
//        priority_queue<node, vector<node>, ComparePairs> q;
//        if (solution[id][i]) continue;  // 该颜色无法填涂
//        color[id] = i;
//        flag = 1;
//        edge = graph.head[id].next;
//
//        while (edge) {
//            if (color[edge->dest] == color[id]) {
//                flag = 0;
//                break;
//            }
//            edge = edge->next;
//        }
//        if (flag) {
//            ++done;
//            cout << done << " " << id << endl;
//            if (done == vertices) {
//                if (check(graph))ans++;
//                cout << endl;
//                return;
//            }
//            
//            edge = graph.head[id].next;
//            while (edge) {
//                if (!color[edge->dest] && !solution[edge->dest][i]) {
//                    solution[edge->dest][i] = done;
//                    Feasible_solution[edge->dest] -= 1;
//                    q.push({ edge->dest, Feasible_solution[edge->dest] });
//                }
//                edge = edge->next;
//            }
//            while (!q.empty()) {
//                int next = q.top().id;
//                q.pop();
//                dfs(next, graph, done);
//            }
//            edge = graph.head[id].next;
//            while (edge) {
//                if (!color[edge->dest] && solution[edge->dest][i] == done) {
//                    solution[edge->dest][i] = 0;
//                    Feasible_solution[edge->dest] += 1;
//                }
//                edge = edge->next;
//            }
//            --done;
//        }
//        else continue;
//        //if (ans > 0) return;
//    }
//    color[id] = 0;
//}
//
//int main() {
//    freopen("le9_4.txt", "r", stdin);
//    // freopen("小数据集_output.txt", "w", stdout);
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
//    dfs(4, graph, 0);
//    EndTime = clock();      //结束计时
//    time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为毫秒
//    printf("Solutions: %d\n", ans);
//    printf("Time: %.6lf s\n", time);
//    return 0;
//}