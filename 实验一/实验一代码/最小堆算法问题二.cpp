#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>��
#include <iomanip>��
#include<vector>
#include <chrono>
#include <thread>
#include<random>
using namespace std;

void Min_Heapify(int arr[], int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { 
        if (son + 1 <= end && arr[son] > arr[son + 1]) 
            son++;
        if (arr[dad] < arr[son]) 
            return;
        else { 
            int tmp = arr[son];
            arr[son] = arr[dad];
            arr[dad] = tmp;
            dad = son;
            son = dad * 2 + 1;
        }
    }
}


void Heap_Sort(int arr[], int k, int len) {
    for (int i = k / 2 - 1; i >= 0; i--)
        Min_Heapify(arr, i, k - 1);
    for (int i = k; i < len; i++) {
        if (arr[i] > arr[0]) {
            arr[0] = arr[i];
            Min_Heapify(arr, 0, k);
        }
        else continue;
    }
}



int main()
{
    int n_val[] = { 1000000, 3000000,5000000, 10000000,30000000,50000000,100000000, 300000000, 500000000, 1000000000 };
    for (int i = 0; i < 10; i++) {
        double tot_time = 0;
        for (int j = 1; j <= 10; j++) {
            int n = n_val[i];     // nΪ���ݹ�ģ
            int* arr = new int[n];     // arrΪ����������
            int min = 0, max = n;
            random_device seed;//Ӳ���������������
            ranlux48 engine(seed());//���������������������
            uniform_int_distribution<> distrib(min, max);//�����������Χ����Ϊ��̬�ֲ�
            for (int i = 0; i < n; i++)
            {
                arr[i] = distrib(engine) % n;    // �����������
            }
            clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
            double time;        // ��¼����ʱ��    
            StartTime = clock();    //��ʼ��ʱ
            Heap_Sort(arr, 10, n);    //����
            EndTime = clock();      //������ʱ
            time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
            cout << fixed;
            cout << "���ݹ�ģΪ" << n << "ʱ�ڵ�" << j << "�������������������ʱ��Ϊ" << time << "��" << endl;
            tot_time += time;
            delete[]arr;
        }
        cout << "���ݹ�ģΪ" << n_val[i] << "ʱƽ������ʱ��Ϊ" << tot_time / 10 << "��" << endl;
        cout << endl;
    }

    return 0;
}
