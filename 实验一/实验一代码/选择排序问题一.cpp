//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <fstream>��
//#include <iomanip>��
//#include<random>
//using namespace std;
//
//// ѡ������
//void Selection_Sort(int arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        int min = i;
//        for (int j = i + 1; j < n; j++)
//            if (arr[j] < arr[min])
//                min = j;
//        swap(arr[i], arr[min]);
//    }
//}
//
//
//int main()
//{
//    ofstream out_txt_file;
//    out_txt_file.open("./result_ѡ������.txt", ios::out | ios::trunc);
//    out_txt_file << fixed;
//
//    int n_val[5] = { 100000, 200000, 300000,400000,500000 };    // ���ݹ�ģ
//
//    for (int i = 0; i < 5; i++) {
//        double tot_time = 0;
//        for (int j = 1; j <= 20; j++) {
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
//            Selection_Sort(arr, n);    //����
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
