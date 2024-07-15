//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//using namespace std;
//
//// 边的结构体
//struct Edge {
//    int dest;
//    Edge* next;
//};
//
//class Graph {
//private:
//    int numVertices;
//    Edge** head;
//
//public:
//    // 构造函数
//    Graph(int V) : numVertices(V) {
//        head = new Edge * [V + 1];
//        for (int i = 0; i <= V; ++i) {
//            head[i] = nullptr;
//        }
//    }
//
//    // 添加边
//    void addEdge(int src, int dest) {
//        Edge* newEdge = new Edge;
//        newEdge->dest = dest;
//        newEdge->next = head[src];
//        head[src] = newEdge;
//
//        // 因为是无向图，所以需要添加反向边
//        newEdge = new Edge;
//        newEdge->dest = src;
//        newEdge->next = head[dest];
//        head[dest] = newEdge;
//    }
//
//    // 获得head[src]
//    Edge* get_head(int src) {
//        return head[src];
//    }
//
//    // 打印邻接表
//    void printGraph() {
//        for (int i = 1; i <= numVertices; ++i) {
//            cout << "顶点 " << i << " 的邻接表：" << std::endl;
//            Edge* current = head[i];
//            while (current) {
//                std::cout << "-> " << current->dest;
//                current = current->next;
//            }
//            std::cout << std::endl;
//        }
//    }
//
//    // 析构函数
//    ~Graph() {
//        for (int i = 1; i <= numVertices; ++i) {
//            Edge* current = head[i];
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
//int vertices, edges;  // vertices为顶点数，edges为边数
//int ans = 0; // 答案
//int num_color = 4; // 用于填色的颜料个数
//int* color;
//int F = 0;
//
//void dfs(int x, Graph& graph) {
//    if (x > vertices) {
//        ans++;
//        F = 1;
//        return;
//    }
//    int flag;
//    for (int i = 1; i <= num_color; ++i) {
//        color[x] = i;
//        flag = 1;
//        Edge* edge = graph.get_head(x);
//
//        // 检测填色是否符合要求
//        while (edge) {
//            if (edge->dest < x && color[edge->dest] == color[x]) {
//                flag = 0;
//                break;
//            }
//            edge = edge->next;
//        }
//        if (flag) {
//            dfs(x + 1, graph);
//        }
//        //if (F) return;
//    }
//}
//
//int main() {
//    freopen("le9_4.txt", "r", stdin);
//    cin >> vertices >> edges;
//    Graph graph(vertices);
//    color = new int[vertices + 1];
//    memset(color, 0, sizeof(color));
//    for (int i = 1; i <= edges; ++i) {
//        int src, dest;
//        cin >> src >> dest;
//        graph.addEdge(src, dest);   // 建图
//    }
//
//    clock_t StartTime, EndTime; //定义计时开始和计时结束变量
//    double time;        // 记录运行时间			
//    StartTime = clock();    //开始计时
//    dfs(1, graph);
//    EndTime = clock();      //结束计时
//    time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为毫秒
//    printf("Solutions: %d\n", ans);
//    printf("Time: %.6lf s\n", time);
//    return 0;
//}
