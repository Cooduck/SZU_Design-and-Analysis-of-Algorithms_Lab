#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>��
#include <iomanip>��
#include<vector>
#include <chrono>
#include<random>
#include <thread>
using namespace std;

// ѡ������
void Selection_Sort(int arr[], int n) {
    for (int i = 0; i < 10; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[max])
                max = j;
        swap(arr[i], arr[max]);
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
            Selection_Sort(arr, n);    //����
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
