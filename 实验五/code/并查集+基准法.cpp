//#include<stdio.h>
//#include"������.h"
//
//extern int n, m;	// nΪ��������mΪ����
//extern Edge edge_set[10000000];
//int f[1000000];
//
//// ���Ҹü��ϵĴ���Ԫ��
//int find(int x) {
//	if (f[x] == x) return x;
//	else find(f[x]);
//}
//
//// �ϲ�����
//int merge(int u, int v) {
//	int fa = find(u);
//	int fb = find(v);
//
//	// �������ϲ���ͨ����ϲ���������
//	if (fa != fb) {
//		f[fa] = fb;
//		return 1; 
//	}
//	return 0;
//}
//
//int work() {
//	int cnt = 0; // ͳ���ŵĸ���
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
//		// ��ʼ�����鼯
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