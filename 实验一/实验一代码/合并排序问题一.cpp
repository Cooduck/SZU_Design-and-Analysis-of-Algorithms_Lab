#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>��
#include <iomanip>��
#include<vector>
#include<random>
using namespace std;

// �ϲ�
void Merge(int arr[], int front, int mid, int end) {
    int* tmp_arr1 = new int[mid - front + 1];
    int* tmp_arr2 = new int[end - mid];
    for (int i = 0; i < mid - front + 1; i++) {
        tmp_arr1[i] = arr[front + i];
    }
    for (int i = 0; i < end - mid; i++) {
        tmp_arr2[i] = arr[mid + 1 + i];
    }
    int idxLeft = 0, idxRight = 0;

    int i;
    for (i = front; i <= end; i++) {
        if (idxLeft == mid - front + 1 || idxRight == end - mid) {
            break;
        }
        if (tmp_arr1[idxLeft] < tmp_arr2[idxRight]) {
            arr[i] = tmp_arr1[idxLeft];
            idxLeft++;
        }
        else {
            arr[i] = tmp_arr2[idxRight];
            idxRight++;
        }
    }
    while (idxLeft < mid - front + 1) {
        arr[i++] = tmp_arr1[idxLeft++];
    }
    while (idxRight < end - mid) {
        arr[i++] = tmp_arr2[idxRight++];
    }
}

// �ϲ�����
void Merge_Sort(int arr[], int front, int end) {
    if (front >= end)
        return;
    int mid = (front + end) / 2;
    Merge_Sort(arr, front, mid);
    Merge_Sort(arr, mid + 1, end);
    Merge(arr, front, mid, end);
}


int main()
{
    ofstream out_txt_file;
    out_txt_file.open("./result_�ϲ�����2.txt", ios::out | ios::trunc);
    out_txt_file << fixed;

    int n_val[10] = { 100000, 300000,500000,1000000,3000000, 5000000, 10000000,30000000,50000000, 100000000 };    // ��ȡ�����ݹ�ģ
    
    for (int i = 0; i < 10; i++) {
        double tot_time = 0;
        for (int j = 1; j <= 20; j++) {
            int n = n_val[i];		// nΪ���ݹ�ģ
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
            Merge_Sort(arr, 0, n-1);    //����
            EndTime = clock();      //������ʱ
            time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
            out_txt_file << "���ݹ�ģΪ" << n << "ʱ�ڵ�" << j << "�������������������ʱ��Ϊ" << time << "��" << endl;
            tot_time += time;
            delete[]arr;
        }
        out_txt_file << "���ݹ�ģΪ" << n_val[i] << "ʱƽ������ʱ��Ϊ" << tot_time/20 << "��" << endl;
        out_txt_file << endl;
    }

    out_txt_file.close();
    return 0;
}
