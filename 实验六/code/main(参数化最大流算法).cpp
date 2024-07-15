#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#define INF 0x3f3f

const int V = 5000;
int n;
int graph_len;
int w[V];			// w[i]��ʾ����i�Ѿ�ʤ������
int c[V];			// k[i]��ʾ����iʣ���������
int g[V][V];	// g[i][j]��ʾ����i�Ͷ���j֮��ʣ�������
int graph[V][V];	// graphΪ������
int vis[V];
int max_W;
clock_t StartTime, EndTime; // ��¼����ʱ��
extern int Ford_Fulkerson(int graph[V][V], int s, int t);
//extern int Edmond_Karp(int graph[V][V], int s, int t);
//extern int Dinic(int graph[V][V], int s, int t);
int tot_capacity;
struct Team {
	int idx, w, c;
	std::string team_name;
	bool operator < (const Team p) const {
		return w + c < p.w + p.c;
	}
}team[V];

// ����������
void Build_Graph(int W) {
	// �ڵ�1ΪԴ�㣬�ڵ� 2 �� 1 + (n * (n - 1) / 2) Ϊ�����ڵ㣬
	// �ڵ� 2 + (n * (n - 1) / 2) �� 1 + (n * (n - 1) / 2) + n Ϊ����ڵ㣬 
	// 2 + (n * (n - 1) / 2) + n Ϊ���

	memset(graph, 0, sizeof(graph));
	tot_capacity = 0;

	// ������Դ������ı�
	int num = n * (n - 1) / 2;
	int cnt = 2;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[1][cnt++] = g[i][j];
			tot_capacity += g[i][j];
		}
	}

	// �����ӱ����ڵ�����ı�
	cnt = 2;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt][i + 1 + num] = INF, graph[cnt++][j + 1 + num] = INF;
		}
	}

	// �����Ӷ���ڵ�����ı�
	for (int i = 2 + num; i <= 1 + num + n; i++) {
		graph[i][2 + num + n] = W - w[i - 1 - num];
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	//freopen("team4.txt", "r", stdin);
	//freopen("team5.txt", "r", stdin);
	//freopen("team54.txt", "r", stdin);
	std::string file_names[] = { "team32.txt", "team36.txt", "team42.txt", "team48.txt", "team54.txt" };

	for (int file_idx = 0; file_idx < 5; file_idx++) {
		double tot_time = 0;
		int test_num = 10;

		for (int i = 0; i < test_num; i++) {
			freopen(file_names[file_idx].c_str(), "r", stdin);
			int max_w = -INF;
			memset(w, 0, sizeof(w));
			memset(c, 0, sizeof(c));
			memset(g, 0, sizeof(g));
			memset(team, 0, sizeof(team));

			std::cin >> n;
			graph_len = 2 + (n * (n - 1) / 2) + n;
			for (int i = 1; i <= n; i++) {
				std::cin >> team[i].team_name;
			}
			for (int i = 1; i <= n; i++) {
				std::cin >> w[i] >> c[i];
				team[i].idx = i, team[i].w = w[i], team[i].c = c[i];
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					std::cin >> g[i][j];
				}
			}

			StartTime = clock();    //��ʼ��ʱ

			std::sort(team + 1, team + 1 + n);
			int l = team[1].c + team[1].w, r = team[n].c + team[n].w;

			while (l <= r) {
				int mid = (l + r) >> 1;
				Build_Graph(mid);
				int maximum_flow = Ford_Fulkerson(graph, 1, 2 + (n * (n - 1) / 2) + n);
				//int maximum_flow = Edmond_Karp(graph, 1, 2 + (n * (n - 1) / 2) + n);
				//int maximum_flow = Dinic(graph, 1, 2 + (n * (n - 1) / 2) + n);
				if (tot_capacity == maximum_flow) {
					r = mid - 1;
				}
				else {
					max_W = mid;
					l = mid + 1;
				}
			}

			for (int i = 1; i <= n; i++) {
				if (team[i].c + team[i].w <= max_W) {
					//printf("%s ����̭\n", team[i].team_name.c_str());
				}
				else {
					//printf("%s ��ϣ�����\n", team[i].team_name.c_str());
				}
			}

			EndTime = clock();  //������ʱ
			tot_time += (double)(EndTime - StartTime) / CLOCKS_PER_SEC;
		}
		printf("%lf\n", tot_time / test_num);
	}

	return 0;
}