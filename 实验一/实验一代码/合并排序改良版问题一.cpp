//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <fstream>　
//#include <iomanip>　
//#include<vector>
//#include<random>
//using namespace std;
//
//// 合并
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
//// 合并排序
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
//    out_txt_file.open("./result_合并排序2.txt", ios::out | ios::trunc);
//    out_txt_file << fixed;
//
//    int n_val[10] = { 100000, 300000,500000,1000000,3000000, 5000000, 10000000,30000000,50000000, 100000000 };    // 待取的数据规模
//    
//    for (int i = 0; i < 10; i++) {
//        double tot_time = 0;
//        for (int j = 1; j <= 20; j++) {
//            int n = n_val[i];		// n为数据规模
//            int* arr = new int[n];     // arr为待排序数组
//            int* tmp = new int[n];      // tmp为额外数组空间，在排序中用于存储排序结果
//            int min = 0, max = n;
//            random_device seed;//硬件生成随机数种子
//            ranlux48 engine(seed());//利用种子生成随机数引擎
//            uniform_int_distribution<> distrib(min, max);//设置随机数范围，并为正态分布
//            for (int i = 0; i < n; i++)
//            {
//                arr[i] = distrib(engine) % n;    // 生成随机数据
//            }
//            clock_t StartTime, EndTime; //定义计时开始和计时结束变量
//            double time;        // 记录运行时间    
//            StartTime = clock();    //开始计时
//            Merge_Sort(arr, tmp, 0, n-1);    //排序
//            EndTime = clock();      //结束计时
//            time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
//            out_txt_file << "数据规模为" << n << "时在第" << j << "组测试样本下所需运行时间为" << time << "秒" << endl;
//            tot_time += time;
//            delete[]arr;
//        }
//        out_txt_file << "数据规模为" << n_val[i] << "时平均运行时间为" << tot_time/20 << "秒" << endl;
//        out_txt_file << endl;
//    }
//
//    out_txt_file.close();
//    return 0;
//}
