//#include<stdio.h>
//#include<string.h>
//#include"链表类.h"
//
//extern int n, m;	// n为顶点数，m为边数
//extern LinkedList graph[1000000];
//extern Edge edge_set[10000000];
//int vis[1000000];
//
//void dfs(int x, int start, int end, int &flag) {
//	vis[x] = 1;
//	if (end == x) {
//		flag = 1;
//		return;
//	}
//
//	Node* p = graph[x].get_head()->next;
//	while(p != nullptr){
//		int v = p->data;
//
//		// 移除特定边
//		if ((x == start && v == end) || (x == end && v == start)) {
//			p = p->next;
//			continue;
//		}
//
//		// 没遍历过的顶点则往下遍历
//		if (!vis[v]) {
//			dfs(v, start, end, flag);
//		}
//
//		// 提前返回
//		if (end == x || flag) return;
//		
//		p = p->next;
//	}
//}
//
//// 查看两顶点间是否还连通,连通则返回1，不连通返回0
//int check_block(int u, int v){
//	memset(vis, 0, sizeof(vis));
//
//	int flag = 0;
//	dfs(u, u, v, flag);
//	if (flag == 1) {
//		return 1;
//	}
//	else return 0;
//}
//
//int work() {
//	int cnt = 0; // 统计桥的个数
//	
//	for (int i = 0; i < m; ++i) {
//		int u = edge_set[i].u, v = edge_set[i].v;
//		if (!check_block(u, v)) {
//			++cnt;
//			//printf("%d %d\n", u, v);
//		}
//	}
//
//	return cnt;
//}