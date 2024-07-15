//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//using namespace std;
//
//int vertices, edges;  // verticesΪ��������edgesΪ����
//long long ans = 0; // ��
//int num_color; // ������ɫ�����ϸ���
//int color[500];     // ÿ�������Ϳɫ
//int solution[500][50];   // ÿ������ʣ�����Ϳ��ɫ
//int Feasible_solution[500];     // ÿ������ʣ���Ϳ��ɫ����
//clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
//double Time;        // ��¼����ʱ��
//
//// �ߵĽṹ��
//struct Edge {
//    int dest;       // �ߵ��յ�
//    Edge* next;
//};
//
//struct Head {
//    int id;         // �ö���ı��
//    int degree;     // �ö���Ķ�
//    Edge* next;
//    Head() : id(0), degree(0), next(nullptr) {}
//};
//
//int cmp(const Head a, const Head b) {
//    return Feasible_solution[a.id] < Feasible_solution[b.id];
//}
//
//class Graph {
//public:
//    int numVertices;
//    Head* head;
//
//    // ���캯��
//    Graph(int V) : numVertices(V) {
//        head = new Head[V + 1];
//        for (int i = 1; i <= V; ++i) {
//            head[i].id = i;
//        }
//    }
//
//    // ��ӱ�
//    void addEdge(int src, int dest) {
//        Edge* newEdge = new Edge;
//        newEdge->dest = dest;
//        newEdge->next = head[src].next;
//        head[src].next = newEdge;
//        head[src].degree += 1;
//
//        // ��Ϊ������ͼ��������Ҫ��ӷ����
//        newEdge = new Edge;
//        newEdge->dest = src;
//        newEdge->next = head[dest].next;
//        head[dest].next = newEdge;
//        head[dest].degree += 1;
//    }
//
//    // ��������
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
//// �������Ƿ���ȷ
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
//    sort(graph.head + x, graph.head + 1 + vertices, cmp);
//    int flag;
//    int id = graph.head[x].id;
//    for (int i = 1; i <= num_color; ++i) {
//        if (solution[id][i]) continue;  // ����ɫ�޷���Ϳ
//        color[id] = i;
//        flag = 1;
//        Edge* edge = graph.head[x].next;
//
//        // �����ɫ�Ƿ����Ҫ��
//        while (edge) {
//            if (color[edge->dest] == color[id]) {
//                flag = 0;
//                break;
//            }
//            edge = edge->next;
//        }
//        if (flag) {
//            // �����ڽӵ�Ľ�
//            edge = graph.head[x].next;
//            while (edge) {
//                if (!color[edge->dest] && !solution[edge->dest][i]) {
//                    solution[edge->dest][i] = x;
//                    Feasible_solution[edge->dest] -= 1;
//                }
//                edge = edge->next;
//            }
//            //cout << x << " " << id << endl;
//            dfs(x + 1, graph);
//
//            // �ָ��ڽӵ�Ľ�
//            edge = graph.head[x].next;
//            while (edge) {
//                if (!color[edge->dest] && solution[edge->dest][i] == x) {
//                    solution[edge->dest][i] = 0;
//                    Feasible_solution[edge->dest] += 1;
//                }
//                edge = edge->next;
//            }
//        }
//        else continue;
//        if (ans > 0) return;
//    }
//    color[id] = 0;
//}
//
//int main() {
//    //freopen("le9_4.txt", "r", stdin);
//    //freopen("le450_5a.txt", "r", stdin);
//    //freopen("le450_15b.txt", "r", stdin);
//    freopen("le450_25a.txt", "r", stdin);
//    num_color = 25;
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
//        graph.addEdge(src, dest);   // ��ͼ
//    }
//			
//    StartTime = clock();    //��ʼ��ʱ
//    //sort(graph.head + 1, graph.head + 1 + vertices, cmp);
//    dfs(1, graph);
//    EndTime = clock();      //������ʱ
//    Time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ����
//    printf("Solutions: %d\n", ans);
//    printf("Time: %.6lf s\n", Time);
//    return 0;
//}
