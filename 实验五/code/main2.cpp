//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<stdio.h>
//#include<random>
//#include"链表类.h"
//
//clock_t StartTime, EndTime; //定义计时开始和计时结束变量
//clock_t LCA_StartTime;
//int n, m;	// n为顶点数，m为边数
//LinkedList graph[1000000]; // 图
//Edge edge_set[8000000];
//extern int work();
//std::unordered_map<Edge, int, edge_hash> edge_map;
//double build_tree_tot_time = 0;
//
//int main() {
//    std::ios::sync_with_stdio(0);
//    std::cin.tie(0);
//    std::cout.tie(0);
//    // 读入数据
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
//        //m = (n_val[k] * (n_val[k] - 1) / 2);    // 顶点数和边数
//        m = n_val[k];       // 顶点数和边数
//        for (int t = 0; t < test_time; t++) {
//            std::random_device seed;		//硬件生成随机数种子
//            std::ranlux48 engine(seed());	//利用种子生成随机数引擎
//            std::uniform_int_distribution<> distrib(min, max);	//设置随机数范围，并为均匀分布
//
//            int sum = 0;    // 记录无重边的边个数
//            for (int i = 0; i < m; i++) {
//                int u, v;
//                u = distrib(engine), v = distrib(engine);
//                edge_map.clear();
//                // 去重边
//                if (!edge_map.count({ u,v }) && !edge_map.count({ v,u })) {
//                    edge_map[{u, v}] = edge_map[{v, u}] = 1;
//                    edge_set[sum++] = { u, v };
//                    graph[u].insert(v);    // 无向图构建
//                    graph[v].insert(u);
//                }
//            }
//            m = sum;
//
//            double time = 0;;        // 记录运行时间    
//            StartTime = clock();    //开始计时
//
//            int cnt = work();
//
//            EndTime = clock();      //结束计时
//            time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;
//            tot_time += time;
//            
//            printf("用时 %lf s\n", time);
//
//            for (int j = 0; j < 1000000; ++j) {
//                graph[j].clear();
//            }
//        }
//        printf("%lf\n", tot_time / test_time);
//    }
//    return 0;
//}