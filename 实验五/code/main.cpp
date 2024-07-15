#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include"链表类.h"

clock_t StartTime, EndTime; // 记录运行时间
clock_t LCA_StartTime;
int n, m;	// n为顶点数，m为边数
LinkedList graph[1000000]; // 图
Edge edge_set[8000000];
extern int work();
std::unordered_map<Edge, int, edge_hash> edge_map;
double build_tree_tot_time = 0;
double tot_time = 0;
double LCA_tot_time = 0;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // 读入数据
    //freopen("图2.txt", "r", stdin);
    //freopen("smallG.txt", "r", stdin);  // 答案为6
    //freopen("mediumG.txt", "r", stdin);   // 答案为3
    freopen("largeG.txt", "r", stdin);    // 答案为8
    int sum = 0;    // 记录无重边的边个数
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        // 去重边
        if (!edge_map.count({ u,v })) {
            edge_map[{u, v}] = edge_map[{v, u}] = 1;
            edge_set[sum++] = { u, v };
            graph[u].insert(v);    // 无向图构建
            graph[v].insert(u);
        }
    }
    m = sum;    // m重新赋值为无重边的边数
    printf("已读入全部数据\n");

    int test_time = 1;
    for (int i = 0; i < test_time; i++) {
        // 记录算法用时
        double algorithm_time = 0;
        double LCA_time = 0;
        StartTime = clock();    //开始计时
        int cnt = work();   // 计算桥的个数
        EndTime = clock();  //结束计时
        algorithm_time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
        LCA_time = (double)(EndTime - LCA_StartTime) / CLOCKS_PER_SEC;
        //printf("桥的个数为 %d \n", cnt);
        //printf("统计树上环边总用时 %lf s\n", LCA_time);
        //printf("算法总用时 %lf s\n\n", algorithm_time);
        tot_time += algorithm_time;
        LCA_tot_time += LCA_time;
    }
    printf("生成树+LCA+路径压缩——largeG\n");
    printf("建树平均用时 %lf s\n", build_tree_tot_time / test_time);
    printf("统计树上环边平均用时 %lf s\n", LCA_tot_time/ test_time);
    printf("算法平均用时 %lf s\n", tot_time / test_time);

    // 记录算法用时
    //double tot_time = 0;    //定义计时开始和计时结束变量
    //StartTime = clock();    //开始计时
    //int cnt = work();   // 计算桥的个数
    //EndTime = clock();  //结束计时
    //tot_time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
    //printf("桥的个数为 %d \n", cnt);
    //printf("用时 %lf s\n", tot_time);

    return 0;
}