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

void Max_Heapify(int arr[], int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { 
        if (son + 1 <= end && arr[son] < arr[son + 1]) 
            son++;
        if (arr[dad] > arr[son]) 
            return;
        else { 
            int tmp = arr[dad];
            arr[dad] = arr[son];
            arr[son] = tmp;
            dad = son;
            son = dad * 2 + 1;
        }
    }
}


void Heap_Sort(int arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        Max_Heapify(arr, i, len - 1);
    int tmp = arr[0];
    arr[0] = arr[len - 1];
    arr[len - 1] = tmp;
    for (int i = len - 2; i > len - 11; i--) {
        Max_Heapify(arr, 0, i);
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
    }
}


int main()
{
    int n_val[] = { 1000000, 3000000,5000000, 10000000,30000000,50000000,100000000, 300000000, 500000000, 1000000000 };
    for (int i = 0; i < 10; i++) {
        double tot_time = 0;
        for (int j = 1; j <= 5; j++) {
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
            Heap_Sort(arr, n);    //����
            EndTime = clock();      //������ʱ
            time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
            cout << fixed;
            cout << "���ݹ�ģΪ" << n << "ʱ�ڵ�" << j << "�������������������ʱ��Ϊ" << time << "��" << endl;
            tot_time += time;
            delete[]arr;
        }
        cout << "���ݹ�ģΪ" << n_val[i] << "ʱƽ������ʱ��Ϊ" << tot_time / 5 << "��" << endl;
        cout << endl;
    }

    return 0;
}
