//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <fstream>��
//#include <iomanip>��
//#include <random>
//
//using namespace std;
//
//int flag;
//
//int Paritition1(int arr[], int low, int high) {
//    int pivot = arr[low];   // �ǰ����ĵ�һ��Ԫ����Ϊ��׼Ԫ��
//    while (low < high) {
//        while (low < high && arr[high] >= pivot) {
//            --high;
//        }
//        arr[low] = arr[high];   // ���Ȼ�׼Ԫ��С��Ԫ�ؽ�������׼Ԫ�����
//        while (low < high && arr[low] <= pivot) {
//            ++low;
//        }
//        arr[high] = arr[low];   // ���Ȼ�׼Ԫ�ش��Ԫ�ؽ�������׼Ԫ���ұ�
//    }
//    arr[low] = pivot;
//    return low;
//}
//
//// ��������
//void Quick_Sort(int arr[], int low, int high, int n)
//{
//    if (flag == 1) return;
//    if (low < high) {
//        int pivot = Paritition1(arr, low, high);
//        Quick_Sort(arr, pivot + 1, high, n);
//        if (flag == 1) return;
//        if (pivot < n - 10 && high == n - 1) {
//            flag = 1;
//            return;
//        }
//        Quick_Sort(arr, low, pivot - 1, n);
//        if (flag == 1) return;
//    }
//}
//
//int main()
//{
//    ofstream out_txt_file;
//    out_txt_file.open("./result_��������2.txt", ios::out | ios::trunc);
//    out_txt_file << fixed;
//
//    int n_val[] = { 100000, 300000,500000,1000000,3000000, 5000000, 10000000,30000000,50000000, 100000000 };    // ���ݹ�ģ
//
//    for (int i = 0; i < 10; i++) {
//        double tot_time = 0;
//        for (int j = 1; j <= 20; j++) {
//            flag = 0;       // ���ñ��
//            int n = n_val[i];		// nΪ���ݹ�ģ
//            int* arr = new int[n];     // arrΪ����������
//            int min = 0, max = n;
//            random_device seed;//Ӳ���������������
//            ranlux48 engine(seed());//���������������������
//            uniform_int_distribution<> distrib(min, max);//�����������Χ����Ϊ��̬�ֲ�
//            for (int i = 0; i < n; i++)
//            {
//                arr[i] = distrib(engine) % n;    // �����������
//            }
//            clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
//            double time;        // ��¼����ʱ��    
//            StartTime = clock();    //��ʼ��ʱ
//            Quick_Sort(arr, 0, n - 1, n);    //����
//            EndTime = clock();      //������ʱ
//            time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
//            out_txt_file << "���ݹ�ģΪ" << n << "ʱ�ڵ�" << j << "�������������������ʱ��Ϊ" << time << "��" << endl;
//            tot_time += time;
//            delete[]arr;
//        }
//        out_txt_file << "���ݹ�ģΪ" << n_val[i] << "ʱƽ������ʱ��Ϊ" << tot_time / 20 << "��" << endl;
//        out_txt_file << endl;
//    }
//
//    out_txt_file.close();
//    return 0;
//}
