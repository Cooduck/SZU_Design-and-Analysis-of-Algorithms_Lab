//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <fstream>��
//#include <iomanip>��
//#include<vector>
//#include<random>
//using namespace std;
//
//// �ϲ�
//void merge(int arr[], int tmp[], int front, int mid, int end) {
//    int i;
//    int idxLeft = 0, idxRight = 0;
//    for (i = front; i <= end; i++) {
//        if (idxLeft == mid - front + 1 || idxRight == end - mid) {
//            break;
//        }
//        if (arr[idxLeft] < arr[idxRight]) {
//            tmp[i] = arr[idxLeft];
//            idxLeft++;
//        }
//        else {
//            tmp[i] = arr[idxRight];
//            idxRight++;
//        }
//    }
//    while (idxLeft < mid - front + 1) {
//        tmp[i++] = arr[idxLeft++];
//    }
//    while (idxRight < end - mid) {
//        tmp[i++] = arr[idxRight++];
//    }
//    for (int i = front; i <= end; i++) {
//        arr[i] = tmp[i];
//    }
//}
//
//// �ϲ�����
//void Merge_Sort(int arr[], int t[], int front, int end) {
//    if (front < end) {
//        int mid = (front + end) / 2;
//        Merge_Sort(arr, t, front, mid);
//        Merge_Sort(arr, t, mid + 1, end);
//        merge(arr, t, front, mid, end);
//    }
//}
//
//int main()
//{
//    ofstream out_txt_file;
//    out_txt_file.open("./result_�ϲ�����2.txt", ios::out | ios::trunc);
//    out_txt_file << fixed;
//
//    int n_val[10] = { 100000, 300000,500000,1000000,3000000, 5000000, 10000000,30000000,50000000, 100000000 };    // ��ȡ�����ݹ�ģ
//    
//    for (int i = 0; i < 10; i++) {
//        double tot_time = 0;
//        for (int j = 1; j <= 20; j++) {
//            int n = n_val[i];		// nΪ���ݹ�ģ
//            int* arr = new int[n];     // arrΪ����������
//            int* tmp = new int[n];      // tmpΪ��������ռ䣬�����������ڴ洢������
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
//            Merge_Sort(arr, tmp, 0, n-1);    //����
//            EndTime = clock();      //������ʱ
//            time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
//            out_txt_file << "���ݹ�ģΪ" << n << "ʱ�ڵ�" << j << "�������������������ʱ��Ϊ" << time << "��" << endl;
//            tot_time += time;
//            delete[]arr;
//        }
//        out_txt_file << "���ݹ�ģΪ" << n_val[i] << "ʱƽ������ʱ��Ϊ" << tot_time/20 << "��" << endl;
//        out_txt_file << endl;
//    }
//
//    out_txt_file.close();
//    return 0;
//}
