//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<stdio.h>
//#include<random>
//#include"������.h"
//
//clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
//clock_t LCA_StartTime;
//int n, m;	// nΪ��������mΪ����
//LinkedList graph[1000000]; // ͼ
//Edge edge_set[8000000];
//extern int work();
//std::unordered_map<Edge, int, edge_hash> edge_map;
//double build_tree_tot_time = 0;
//
//int main() {
//    std::ios::sync_with_stdio(0);
//    std::cin.tie(0);
//    std::cout.tie(0);
//    // ��������
//
//    //int n_val[] = { 0, 1000, 2000, 3000, 4000, 5000 };
//    //int n_val[] = { 0, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000 };
//    //int n_val[] = { 0, 50, 100, 150, 200, 250 };
//    int n_val[] = { 0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000 };
//
//    for (int k = 1; k <= 5; k++) {
//        double tot_time = 0;
//        int min = 0, max = n_val[k] - 1;
//        int test_time = 5;
//        n = n_val[k];
//        //m = (n_val[k] * (n_val[k] - 1) / 2);    // �������ͱ���
//        m = n_val[k];       // �������ͱ���
//        for (int t = 0; t < test_time; t++) {
//            std::random_device seed;		//Ӳ���������������
//            std::ranlux48 engine(seed());	//���������������������
//            std::uniform_int_distribution<> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
//
//            int sum = 0;    // ��¼���رߵı߸���
//            for (int i = 0; i < m; i++) {
//                int u, v;
//                u = distrib(engine), v = distrib(engine);
//                edge_map.clear();
//                // ȥ�ر�
//                if (!edge_map.count({ u,v }) && !edge_map.count({ v,u })) {
//                    edge_map[{u, v}] = edge_map[{v, u}] = 1;
//                    edge_set[sum++] = { u, v };
//                    graph[u].insert(v);    // ����ͼ����
//                    graph[v].insert(u);
//                }
//            }
//            m = sum;
//
//            double time = 0;;        // ��¼����ʱ��    
//            StartTime = clock();    //��ʼ��ʱ
//
//            int cnt = work();
//
//            EndTime = clock();      //������ʱ
//            time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;
//            tot_time += time;
//            
//            printf("��ʱ %lf s\n", time);
//
//            for (int j = 0; j < 1000000; ++j) {
//                graph[j].clear();
//            }
//        }
//        printf("%lf\n", tot_time / test_time);
//    }
//    return 0;
//}