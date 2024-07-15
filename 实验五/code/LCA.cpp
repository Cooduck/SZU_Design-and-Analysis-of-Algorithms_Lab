//#include<stdio.h>
//#include<iostream>
//#include<string.h>
//#include<queue>
//#include"链表类.h"
//
//extern int n, m;	// n为顶点数，m为边数
//extern Edge edge_set[10000000];
//extern LinkedList graph[1000000];
//int depth[1000000];	// 生成树上顶点深度
//int father[1000000];	// 生成树上顶点的父亲节点
//int Edges_visited[10000000];	// 生成树上边的标记
//int vis[1000000];	// 生成树上顶点标记
//int edge_num = 0;	// 不位于生成树上的边的数目
//int loop_edge = 0;	// 环边的数目
////std::unordered_map<Edge, int, edge_hash> umap2;	// 记录不为桥的边
////Edge edge_on_tree[10000000];	// 位于生成树上的边
////int num_edge_on_tree = 0;	// 位于生成树上的边的数目
//struct vec {
//	int x, depth, father;
//};
//extern clock_t StartTime;
//extern clock_t LCA_StartTime;
//clock_t build_tree_EndTime;
//extern double build_tree_tot_time;
//
//// 构建生成树
//void dfs(int now, int pre, int dep) {
//	vis[now] = 1;
//	depth[now] = dep;
//	father[now] = pre;
//
//	Node* p = graph[now].get_head()->next;
//	while (p != nullptr) {
//		int nxt = p->data;
//		if (!vis[nxt]) {
//			dfs(nxt, now, dep + 1);
//		}
//		p = p->next;
//	}
//}
//
//void bfs() {
//	std::queue<vec> q;
//	
//	for (int i = 0; i < n; i++) {
//		if (!vis[i]) {
//			q.push({i, 1, i});
//
//			while (!q.empty()) {
//				int x = q.front().x, dep = q.front().depth, fa = q.front().father;
//				q.pop();
//
//				if (vis[x]) continue;
//
//				vis[x] = 1;
//				depth[x] = dep;
//				father[x] = fa;
//
//				Node* p = graph[x].get_head()->next;
//				while (p != nullptr) {
//					int nxt = p->data;
//					if (!vis[nxt]) {
//						q.push({nxt, dep + 1, x});
//					}
//					p = p->next;
//				}
//			}
//		}
//	}
//}
//
//// 统计位于环上的边
//void find_LCA(int l, int r) {
//	int initial_l = l, initial_r = r;
//
//	while (1) {
//		if (depth[l] > depth[r]) {
//			if (!Edges_visited[l]) {
//				//umap2[{father[l], l}] = 1;
//				Edges_visited[l] = 1;
//				++loop_edge;
//			}
//			l = father[l];
//		}
//		else if (depth[l] < depth[r]) {
//			if (!Edges_visited[r]) {
//				//umap2[{father[r], r}] = 1;
//				Edges_visited[r] = 1;
//				++loop_edge;
//			}
//			r = father[r];
//		}
//		else {
//			if (l != r) {
//				if (!Edges_visited[l]) {
//					//umap2[{father[l], l}] = 1;
//					Edges_visited[l] = 1;
//					++loop_edge;
//				}
//				if (!Edges_visited[r]) {
//					//umap2[{father[r], r}] = 1;
//					Edges_visited[r] = 1;
//					++loop_edge;
//				}
//				l = father[l], r = father[r];
//			}
//			else break;
//		}
//	}
//}
//
//int work() {
//	memset(vis, 0, sizeof(vis));
//	memset(Edges_visited, 0, sizeof(Edges_visited));
//	memset(father, 0, sizeof(father));
//	memset(depth, 0, sizeof(depth));
//	edge_num = 0;
//	loop_edge = 0;
//	//构建生成树
//	for (int i = 0; i < n; i++) {
//		if (!vis[i]) {
//			dfs(i, i, 1);
//		}
//	}
//	//bfs();
//	build_tree_EndTime = clock();
//	build_tree_tot_time += (double)(build_tree_EndTime - StartTime) / CLOCKS_PER_SEC;
//	//printf("建树用时 %lf s\n", (double)(build_tree_EndTime - StartTime) / CLOCKS_PER_SEC);
//	LCA_StartTime = clock();
//
//	for (int i = 0; i < m; i++) {
//		int u = edge_set[i].u, v = edge_set[i].v;
//		if (father[u] != v && father[v] != u) {
//			//umap2[{u, v}] = 1;
//			++edge_num;
//			find_LCA(u, v);
//		}
//	}
//
//	//for (int i = 0; i < m; i++) {
//	//	int u = edge_set[i].u, v = edge_set[i].v;
//	//	if(!(umap2.count({ u,v }) || umap2.count({ v,u })))
//	//		printf("%d %d\n", u, v);
//	//}
//
//	return m - loop_edge - edge_num;
//}
