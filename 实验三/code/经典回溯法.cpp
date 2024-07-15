//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//using namespace std;
//
//// �ߵĽṹ��
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
//    // ���캯��
//    Graph(int V) : numVertices(V) {
//        head = new Edge * [V + 1];
//        for (int i = 0; i <= V; ++i) {
//            head[i] = nullptr;
//        }
//    }
//
//    // ��ӱ�
//    void addEdge(int src, int dest) {
//        Edge* newEdge = new Edge;
//        newEdge->dest = dest;
//        newEdge->next = head[src];
//        head[src] = newEdge;
//
//        // ��Ϊ������ͼ��������Ҫ��ӷ����
//        newEdge = new Edge;
//        newEdge->dest = src;
//        newEdge->next = head[dest];
//        head[dest] = newEdge;
//    }
//
//    // ���head[src]
//    Edge* get_head(int src) {
//        return head[src];
//    }
//
//    // ��ӡ�ڽӱ�
//    void printGraph() {
//        for (int i = 1; i <= numVertices; ++i) {
//            cout << "���� " << i << " ���ڽӱ�" << std::endl;
//            Edge* current = head[i];
//            while (current) {
//                std::cout << "-> " << current->dest;
//                current = current->next;
//            }
//            std::cout << std::endl;
//        }
//    }
//
//    // ��������
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
//int vertices, edges;  // verticesΪ��������edgesΪ����
//int ans = 0; // ��
//int num_color = 4; // ������ɫ�����ϸ���
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
//        graph.addEdge(src, dest);   // ��ͼ
//    }
//
//    clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
//    double time;        // ��¼����ʱ��			
//    StartTime = clock();    //��ʼ��ʱ
//    dfs(1, graph);
//    EndTime = clock();      //������ʱ
//    time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ����
//    printf("Solutions: %d\n", ans);
//    printf("Time: %.6lf s\n", time);
//    return 0;
//}
