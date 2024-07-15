//#include<bits/stdc++.h>
//#include<random>
//#define INF 0x3f3f3f3f
//using namespace std;
//
//int vertices, edges;  // verticesΪ��������edgesΪ����
//long long ans = 0; // ��
//int num_color; // ������ɫ�����ϸ���
//int color[500];     // ÿ�������Ϳɫ
//int solution[500][50];   // ÿ������ʣ�����Ϳ��ɫ
//int Feasible_solution[500];     // ÿ������ʣ���Ϳ��ɫ����
//int vis[500][500];
//clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
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
//    int flag;
//    for (int i = 1; i <= num_color; ++i) {
//        color[x] = i;
//        flag = 1;
//        Edge* edge = graph.head[x].next;
//
//        // �����ɫ�Ƿ����Ҫ��
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
//            // �������ͼ
//            int min = 1, max = vertices;	// nΪ���ݹ�ģ
//            random_device seed;		//Ӳ���������������
//            ranlux48 engine(seed());	//���������������������
//            uniform_int_distribution<> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
//            for (int i = 1; i <= edge;) {
//                int src = distrib(engine) % (max + 1);
//                int dest = distrib(engine) % (max + 1);
//                if (src == 0 || dest == 0) {    // ��֤���ɶ����ڷ�Χ��
//                    continue;
//                }
//                if (vis[src][dest] || vis[dest][src]) { // �ų��ر�
//                    continue;
//                }
//                if (src == dest) {      // �ų��Ի�
//                    continue;
//                }
//                graph.addEdge(src, dest);
//                vis[src][dest] = vis[dest][src] = 1;
//                i++;
//            }
//            double time;        // ��¼����ʱ��    
//            StartTime = clock();    //��ʼ��ʱ
//            dfs(1, graph);
//            EndTime = clock();      //������ʱ
//            time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
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