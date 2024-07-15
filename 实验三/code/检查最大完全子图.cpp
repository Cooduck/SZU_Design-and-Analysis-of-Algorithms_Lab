//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//using namespace std;
//
//int vertices, edges;  // verticesΪ��������edgesΪ����
//int num_color;
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
//vector<int> arr;
//int F = 0;
//
//int find(int i, int j, Graph& graph) {
//    Edge* edge = graph.head[i].next;
//    while (edge) {
//        if (edge->dest == j) return 1;
//        edge = edge->next;
//    }
//    return 0;
//}
//
//int check(Graph& graph) {
//    for (int i = 0; i < arr.size(); ++i) {
//        for (int j = 0; j < arr.size(); ++j) {
//            if (i == j) continue;
//            if (!find(arr[i], arr[j], graph)) return 0;
//        }
//    }
//    return 1;
//}
//
//void dfs(int last, int num, int target, Graph &graph) {
//    if (num == target) {
//        if (check(graph)) {
//            F = 1;
//        }
//        return;
//    }
//    for (int i = last + 1; i <= vertices; ++i) {
//        arr.push_back(i);
//        dfs(i, num + 1, target, graph);
//        if (F == 1) return;
//        arr.pop_back();
//    }
//}
//
//string file_name[] = { "le9_4.txt", "le450_5a.txt", "le450_15b.txt" , "le450_25a.txt" };
//int target[] = { 4,5,10,24 };
//
//int main() {
//
//    for (int i = 0; i < 4; i++) {
//        ifstream file(file_name[i]);
//        file >> vertices >> edges;
//        Graph graph(vertices);
//        for (int i = 1; i <= edges; ++i) {
//            int src, dest;
//            file >> src >> dest;
//            graph.addEdge(src, dest);   // ��ͼ
//        }
//        F = 0;
//        arr.clear();
//        dfs(0, 0, target[i], graph);
//        if(F) printf("ͼ\"%s\"���ܹ��ҵ����%d����ȫ��ͼ\n", file_name[i].c_str(), target[i]);
//        else printf("ͼ\"%s\"�в��ܹ��ҵ����%d����ȫ��ͼ\n", file_name[i].c_str(), target[i]);
//
//        //arr.clear();
//        //F = 0;
//        //dfs(0, 0, target[i]+1, graph);
//        //if (F) printf("ͼ\"%s\"���ܹ��ҵ����%d����ȫ��ͼ\n", file_name[i].c_str(), target[i]+1);
//        //else printf("ͼ\"%s\"�в��ܹ��ҵ����%d����ȫ��ͼ\n", file_name[i].c_str(), target[i]+1);
//        printf("\n");
//    }
//    return 0;
//}
