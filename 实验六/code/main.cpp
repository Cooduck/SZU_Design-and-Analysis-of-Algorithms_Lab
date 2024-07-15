//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<iostream>
//#include<string>
//#include<algorithm>
//#define INF 0x3f3f
//
//const int V = 5000;
//int n;
//int graph_len;
//int w[V];			// w[i]表示队伍i已经胜利场数
//int c[V];			// k[i]表示队伍i剩余比赛场数
//int g[V][V];	// g[i][j]表示队伍i和队伍j之间剩余比赛数
//int graph[V][V];	// graph为网络流
//int vis[V];
//int max_w = -INF;
//clock_t StartTime, EndTime; // 记录运行时间
//std::string team_name[V];
////extern int Ford_Fulkerson(int graph[V][V], int s, int t);
////extern int Edmond_Karp(int graph[V][V], int s, int t);
//extern int Dinic(int graph[V][V], int s, int t);
//int tot_capacity;
//struct Team {
//	int idx, w, c;
//	bool operator < (const Team p) const {
//		return w + c < p.w + p.c;
//	}
//}team[V];
//
//// 构建网络流
//void Build_Graph(int idx) {
//	// 节点1为源点，节点 2 到 1 + (n * (n - 1) / 2) 为比赛节点，
//    // 节点 2 + (n * (n - 1) / 2) 到 1 + (n * (n - 1) / 2) + n 为队伍节点， 
//    // 2 + (n * (n - 1) / 2) + n 为汇点
//
//	memset(graph, 0, sizeof(graph));
//	tot_capacity = 0;
//
//	// 构建从源点出发的边
//	int num = n * (n - 1) / 2;
//	int cnt = 2;
//	for (int i = 1; i <= n - 1; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			graph[1][cnt++] = g[i][j];
//			tot_capacity += g[i][j];
//		}
//	}
//
//	// 构建从比赛节点出发的边
//	cnt = 2;
//	for (int i = 1; i <= n - 1; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			graph[cnt][i + 1 + num] = INF, graph[cnt++][j + 1 + num] = INF;
//		}
//	}
//
//	// 构建从队伍节点出发的边
//	for (int i = 2 + num; i <= 1 + num + n; i++) {
//		graph[i][2 + num + n] = w[idx] + c[idx] - w[i - 1 - num];
//	}
//}
//
//void Trivial_Elimination() {
//	memset(vis, 0, sizeof(vis));
//	std::sort(team + 1, team + 1 + n);
//
//	for (int i = 1; i <= n; i++) {
//		int idx = team[i].idx, sum = team[i].w + team[i].c;
//		if (sum < max_w) {
//			vis[idx] = 1;
//		}
//		else break;
//	}	
//}
//
//int main() {
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
//	std::cout.tie(0);
//
//	//freopen("team4.txt", "r", stdin);
//	//freopen("team5.txt", "r", stdin);
//	//freopen("team54.txt", "r", stdin);
//	std::string file_names[] = { "team32.txt", "team36.txt", "team42.txt", "team48.txt", "team54.txt" };
//
//	for (int file_idx = 0; file_idx < 5; file_idx++) {
//		double tot_time = 0;
//		int test_num = 10;
//
//		for (int i = 0; i < test_num; i++) {
//			freopen(file_names[file_idx].c_str(), "r", stdin);
//			int max_w = -INF;
//			memset(w, 0, sizeof(w));
//			memset(c, 0, sizeof(c));
//			memset(g, 0, sizeof(g));
//			memset(team, 0, sizeof(team));
//
//			std::cin >> n;
//			graph_len = 2 + (n * (n - 1) / 2) + n;
//			for (int i = 1; i <= n; i++) {
//				std::cin >> team_name[i];
//			}
//			for (int i = 1; i <= n; i++) {
//				std::cin >> w[i] >> c[i];
//				team[i].idx = i, team[i].w = w[i], team[i].c = c[i];
//				if (max_w < w[i]) max_w = w[i];
//			}
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= n; j++) {
//					std::cin >> g[i][j];
//				}
//			}
//
//			StartTime = clock();    //开始计时
//
//			// 简单淘汰
//			Trivial_Elimination();
//
//			// 非简单淘汰
//			for (int i = 1; i <= n; i++) {
//				if (vis[i] == 1) {
//					//printf("%s 被淘汰\n", team_name[i].c_str());
//					continue;
//				}
//				Build_Graph(i);
//				//int maximum_flow = Ford_Fulkerson(graph, 1, 2 + (n * (n - 1) / 2) + n);
//				//int maximum_flow = Edmond_Karp(graph, 1, 2 + (n * (n - 1) / 2) + n);
//				int maximum_flow = Dinic(graph, 1, 2 + (n * (n - 1) / 2) + n);
//				if (tot_capacity == maximum_flow) {
//					//printf("%s 有希望夺冠\n", team_name[i].c_str());
//				}
//				else {
//					//printf("%s 被淘汰\n", team_name[i].c_str());
//				}
//			}
//
//			EndTime = clock();  //结束计时
//			tot_time += (double)(EndTime - StartTime) / CLOCKS_PER_SEC;
//		}
//		printf("%lf\n", tot_time / test_num);
//	}
//
//	return 0;
//}