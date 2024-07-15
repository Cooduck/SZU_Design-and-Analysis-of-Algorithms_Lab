//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <fstream>　
//#include <iomanip>　
//#include <random>
//
//using namespace std;
//
//int flag;
//
//int Paritition1(int arr[], int low, int high) {
//    int pivot = arr[low];   // 令当前数组的第一个元素作为基准元素
//    while (low < high) {
//        while (low < high && arr[high] >= pivot) {
//            --high;
//        }
//        arr[low] = arr[high];   // 将比基准元素小的元素交换到基准元素左边
//        while (low < high && arr[low] <= pivot) {
//            ++low;
//        }
//        arr[high] = arr[low];   // 将比基准元素大的元素交换到基准元素右边
//    }
//    arr[low] = pivot;
//    return low;
//}
//
//// 快速排序
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
//    out_txt_file.open("./result_快速排序2.txt", ios::out | ios::trunc);
//    out_txt_file << fixed;
//
//    int n_val[] = { 100000, 300000,500000,1000000,3000000, 5000000, 10000000,30000000,50000000, 100000000 };    // 数据规模
//
//    for (int i = 0; i < 10; i++) {
//        double tot_time = 0;
//        for (int j = 1; j <= 20; j++) {
//            flag = 0;       // 重置标记
//            int n = n_val[i];		// n为数据规模
//            int* arr = new int[n];     // arr为待排序数组
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
//            Quick_Sort(arr, 0, n - 1, n);    //排序
//            EndTime = clock();      //结束计时
//            time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
//            out_txt_file << "数据规模为" << n << "时在第" << j << "组测试样本下所需运行时间为" << time << "秒" << endl;
//            tot_time += time;
//            delete[]arr;
//        }
//        out_txt_file << "数据规模为" << n_val[i] << "时平均运行时间为" << tot_time / 20 << "秒" << endl;
//        out_txt_file << endl;
//    }
//
//    out_txt_file.close();
//    return 0;
//}
