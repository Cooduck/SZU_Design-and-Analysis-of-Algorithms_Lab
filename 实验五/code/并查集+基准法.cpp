//#include<stdio.h>
//#include"链表类.h"
//
//extern int n, m;	// n为顶点数，m为边数
//extern Edge edge_set[10000000];
//int f[1000000];
//
//// 查找该集合的代表元素
//int find(int x) {
//	if (f[x] == x) return x;
//	else find(f[x]);
//}
//
//// 合并集合
//int merge(int u, int v) {
//	int fa = find(u);
//	int fb = find(v);
//
//	// 两个集合不连通，则合并两个集合
//	if (fa != fb) {
//		f[fa] = fb;
//		return 1; 
//	}
//	return 0;
//}
//
//int work() {
//	int cnt = 0; // 统计桥的个数
//	
//	int blocks_num = n;
//	for (int j = 0; j < n; ++j) {
//		f[j] = j;
//	}
//	for (int j = 0; j < m; ++j) {
//		int u = edge_set[j].u, v = edge_set[j].v;
//		blocks_num -= merge(u, v);
//	}
//
//	for (int i = 0; i < m; ++i) {
//		// 初始化并查集
//		int tmp_blocks_num = n;
//		for (int j = 0; j < n; ++j) {
//			f[j] = j;
//		}
//
//		for (int j = 0; j < m; ++j) {
//			if (i != j) {
//				int u = edge_set[j].u, v = edge_set[j].v;
//				tmp_blocks_num -= merge(u, v);
//			}
//		}
//		if (tmp_blocks_num > blocks_num) {
//			cnt++;
//			//int u = edge_set[i].u, v = edge_set[i].v;
//			//printf("%d %d\n", u, v);
//		}
//	}
//	return cnt;
//}