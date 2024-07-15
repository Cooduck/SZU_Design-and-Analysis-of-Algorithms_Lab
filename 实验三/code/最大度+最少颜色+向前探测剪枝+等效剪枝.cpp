#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int vertices, edges;  // verticesΪ��������edgesΪ����
int ans = 0; // ��
int num_color = 5; // ������ɫ�����ϸ���
int color[500];     // ÿ�������Ϳɫ
int solution[500][50];   // ÿ������ʣ�����Ϳ��ɫ
int Feasible_solution[500];     // ÿ������ʣ���Ϳ��ɫ����
int available_color[50];

// �ߵĽṹ��
struct Edge {
    int dest;       // �ߵ��յ�
    Edge* next;
};

struct Head {
    int id;         // �ö���ı��
    int degree;     // �ö���Ķ�
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

    // ���캯��
    Graph(int V) : numVertices(V) {
        head = new Head[V + 1];
        for (int i = 1; i <= V; ++i) {
            head[i].id = i;
        }
    }

    // ��ӱ�
    void addEdge(int src, int dest) {
        Edge* newEdge = new Edge;
        newEdge->dest = dest;
        newEdge->next = head[src].next;
        head[src].next = newEdge;
        head[src].degree += 1;

        // ��Ϊ������ͼ��������Ҫ��ӷ����
        newEdge = new Edge;
        newEdge->dest = src;
        newEdge->next = head[dest].next;
        head[dest].next = newEdge;
        head[dest].degree += 1;
    }

    // ��������
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

    // MRV��DH����
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
        if (solution[id][i]) continue;  // ����ɫ�޷���Ϳ
        if (!flag2 && !available_color[i]) continue;
        color[id] = i;
        flag1 = 1;
        Edge* edge = graph.head[x].next;

        // �����ɫ�Ƿ����Ҫ��
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
            // �����ڽӵ�Ľ�
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
            // �ָ��ڽӵ�Ľ�
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
        graph.addEdge(src, dest);   // ��ͼ
    }

    clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
    double time;        // ��¼����ʱ��			
    StartTime = clock();    //��ʼ��ʱ
    ans = dfs(1, graph);
    EndTime = clock();      //������ʱ
    time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ����
    printf("Solutions: %d\n", ans);
    printf("Time: %.6lf s\n", time);
    return 0;
}
