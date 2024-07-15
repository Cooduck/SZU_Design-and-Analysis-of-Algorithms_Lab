//#include<stdio.h>
//#include<string.h>
//#include"链表类.h"
//
//extern int n, m;	// n为顶点数，m为边数
//extern LinkedList graph[1000000];
//extern Edge edge_set[10000000];
//int vis[1000000];
//
//void dfs(int x) {
//	vis[x] = 1;
//
//	Node* p = graph[x].get_head()->next;
//	while(p != nullptr){
//		if (!vis[p->data]) {
//			dfs(p->data);
//		}
//		p = p->next;
//	}
//}
//
//// 统计图的连通数
//int count_block(){
//	memset(vis, 0, sizeof(vis));
//	int cnt = 0;
//
//	for (int i = 0; i < n; i++) {
//		if (!vis[i]) {
//			dfs(i);
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//int work() {
//	int cnt = 0; // 统计桥的个数
//	int block_num = count_block();	// 初始连通块个数
//	for (int i = 0; i < m; ++i) {
//		int u = edge_set[i].u, v = edge_set[i].v;
//		graph[u].erase(v);
//		graph[v].erase(u);
//
//		int new_block_num = count_block();	// 新的连通块个数
//		if (block_num != new_block_num) {
//			++cnt;
//			//printf("%d %d\n", u, v);
//		}
//		graph[u].insert(v);
//		graph[v].insert(u);
//	}
//
//	return cnt;
//}