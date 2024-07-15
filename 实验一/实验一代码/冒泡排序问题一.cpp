#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>��
#include <iomanip>��
#include<random>
using namespace std;

// ð������
void Bubble_Sort(int arr[], int n) {
    int flag = 1;
    for (int i = 0; i < n - 1; i++) {
        if (i == 1 && flag == 1) break;
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = 0;
            }
    }
}

int main()
{
    ofstream out_txt_file;
    out_txt_file.open("./result_ð������.txt", ios::out | ios::trunc);
    out_txt_file << fixed;

    int n_val[5] = { 100000, 200000, 300000,400000,500000 };    // ��ȡ�����ݹ�ģ
    
    for (int i = 0; i < 5; i++) {
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
            Bubble_Sort(arr, n);    //����
            EndTime = clock();      //������ʱ
            cout << endl;
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
