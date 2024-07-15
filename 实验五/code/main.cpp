#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include"������.h"

clock_t StartTime, EndTime; // ��¼����ʱ��
clock_t LCA_StartTime;
int n, m;	// nΪ��������mΪ����
LinkedList graph[1000000]; // ͼ
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
    // ��������
    //freopen("ͼ2.txt", "r", stdin);
    //freopen("smallG.txt", "r", stdin);  // ��Ϊ6
    //freopen("mediumG.txt", "r", stdin);   // ��Ϊ3
    freopen("largeG.txt", "r", stdin);    // ��Ϊ8
    int sum = 0;    // ��¼���رߵı߸���
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        // ȥ�ر�
        if (!edge_map.count({ u,v })) {
            edge_map[{u, v}] = edge_map[{v, u}] = 1;
            edge_set[sum++] = { u, v };
            graph[u].insert(v);    // ����ͼ����
            graph[v].insert(u);
        }
    }
    m = sum;    // m���¸�ֵΪ���رߵı���
    printf("�Ѷ���ȫ������\n");

    int test_time = 1;
    for (int i = 0; i < test_time; i++) {
        // ��¼�㷨��ʱ
        double algorithm_time = 0;
        double LCA_time = 0;
        StartTime = clock();    //��ʼ��ʱ
        int cnt = work();   // �����ŵĸ���
        EndTime = clock();  //������ʱ
        algorithm_time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
        LCA_time = (double)(EndTime - LCA_StartTime) / CLOCKS_PER_SEC;
        //printf("�ŵĸ���Ϊ %d \n", cnt);
        //printf("ͳ�����ϻ�������ʱ %lf s\n", LCA_time);
        //printf("�㷨����ʱ %lf s\n\n", algorithm_time);
        tot_time += algorithm_time;
        LCA_tot_time += LCA_time;
    }
    printf("������+LCA+·��ѹ������largeG\n");
    printf("����ƽ����ʱ %lf s\n", build_tree_tot_time / test_time);
    printf("ͳ�����ϻ���ƽ����ʱ %lf s\n", LCA_tot_time/ test_time);
    printf("�㷨ƽ����ʱ %lf s\n", tot_time / test_time);

    // ��¼�㷨��ʱ
    //double tot_time = 0;    //�����ʱ��ʼ�ͼ�ʱ��������
    //StartTime = clock();    //��ʼ��ʱ
    //int cnt = work();   // �����ŵĸ���
    //EndTime = clock();  //������ʱ
    //tot_time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
    //printf("�ŵĸ���Ϊ %d \n", cnt);
    //printf("��ʱ %lf s\n", tot_time);

    return 0;
}