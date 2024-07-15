//#include<bits/stdc++.h>
//#include<random>
//#define INF 0x3f3f3f3f
//using namespace std;
//
//int vertices, edges;  // vertices为顶点数，edges为边数
//long long ans = 0; // 答案
//int num_color; // 用于填色的颜料个数
//int color[500];     // 每个顶点的涂色
//int solution[500][50];   // 每个顶点剩余可填涂颜色
//int Feasible_solution[500];     // 每个顶点剩余可涂颜色个数
//int vis[500][500];
//clock_t StartTime, EndTime; //定义计时开始和计时结束变量
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
//        if(check(graph))ans++;
//        return;
//    }
//    int flag;
//    for (int i = 1; i <= num_color; ++i) {
//        color[x] = i;
//        flag = 1;
//        Edge* edge = graph.head[x].next;
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
//        if (ans > 0) return;
//        if (((double)(clock() - StartTime) / CLOCKS_PER_SEC) > 30) return;
//    }
//}
//
//
//int main() {
//    vertices = 200;
//    num_color = 12;
//    int edges[10] = { 400,800,1200,1600,2000,2400,2800,3200,3600,4000 };
//    for (int i = 0; i < 10; i++) {
//        int edge = edges[i];
//        double tot_time = 0;
//        int available_cnt = 0;
//        for (int j = 0; j < 5; j++) {
//            Graph graph(vertices);
//            memset(vis, 0, sizeof(vis));
//            memset(color, 0, sizeof(color));
//            memset(solution, 0, sizeof(solution));
//            for (int i = 1; i <= vertices; ++i) {
//                Feasible_solution[i] = num_color;
//            }
//            ans = 0;
//
//            // 生成随机图
//            int min = 1, max = vertices;	// n为数据规模
//            random_device seed;		//硬件生成随机数种子
//            ranlux48 engine(seed());	//利用种子生成随机数引擎
//            uniform_int_distribution<> distrib(min, max);	//设置随机数范围，并为均匀分布
//            for (int i = 1; i <= edge;) {
//                int src = distrib(engine) % (max + 1);
//                int dest = distrib(engine) % (max + 1);
//                if (src == 0 || dest == 0) {    // 保证生成顶点在范围内
//                    continue;
//                }
//                if (vis[src][dest] || vis[dest][src]) { // 排除重边
//                    continue;
//                }
//                if (src == dest) {      // 排除自环
//                    continue;
//                }
//                graph.addEdge(src, dest);
//                vis[src][dest] = vis[dest][src] = 1;
//                i++;
//            }
//            double time;        // 记录运行时间    
//            StartTime = clock();    //开始计时
//            dfs(1, graph);
//            EndTime = clock();      //结束计时
//            time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
//            if (ans > 0) {
//                tot_time += time;
//                available_cnt++;
//            }
//            printf("edge:%d--ans:%d--time:%lf\n", edge, ans, time);
//        }
//        printf("tot_time:%lf\n\n", tot_time / available_cnt);
//    }
//
//    return 0;
//}