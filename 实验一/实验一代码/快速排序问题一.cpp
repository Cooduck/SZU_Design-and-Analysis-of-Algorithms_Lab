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

int Paritition1(int arr[], int low, int high) {
    int pivot = arr[low];   // �ǰ����ĵ�һ��Ԫ����Ϊ��׼Ԫ��
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            --high;
        }
        arr[low] = arr[high];   // ���Ȼ�׼Ԫ��С��Ԫ�ؽ�������׼Ԫ�����
        while (low < high && arr[low] <= pivot) {
            ++low;
        }
        arr[high] = arr[low];   // ���Ȼ�׼Ԫ�ش��Ԫ�ؽ�������׼Ԫ���ұ�
    }
    arr[low] = pivot;
    return low;
}

// ��������
void Quick_Sort(int arr[], int low, int high)
{
    if (low < high) {
        int pivot = Paritition1(arr, low, high);
        Quick_Sort(arr, low, pivot - 1);    // �ݹ�ؿ�������
        Quick_Sort(arr, pivot + 1, high);   // �ݹ�ؿ�������
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
            Quick_Sort(arr, 0, n - 1);    //����
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
