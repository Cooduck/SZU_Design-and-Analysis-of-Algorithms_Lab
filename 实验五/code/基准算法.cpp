//#include<stdio.h>
//#include<string.h>
//#include"������.h"
//
//extern int n, m;	// nΪ��������mΪ����
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
//// ͳ��ͼ����ͨ��
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
//	int cnt = 0; // ͳ���ŵĸ���
//	int block_num = count_block();	// ��ʼ��ͨ�����
//	for (int i = 0; i < m; ++i) {
//		int u = edge_set[i].u, v = edge_set[i].v;
//		graph[u].erase(v);
//		graph[v].erase(u);
//
//		int new_block_num = count_block();	// �µ���ͨ�����
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