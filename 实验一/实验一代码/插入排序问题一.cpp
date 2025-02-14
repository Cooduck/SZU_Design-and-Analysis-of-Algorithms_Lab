#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>　
#include <iomanip>　
#include<random>
using namespace std;

// 插入排序
void Insertion_Sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (key < arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    ofstream out_txt_file;
    out_txt_file.open("./result_插入排序.txt", ios::out | ios::trunc);
    out_txt_file << fixed;

    int n_val[5] = { 100000, 200000, 300000,400000,500000 };    // 数据规模

    for (int i = 0; i < 5; i++) {
        double tot_time = 0;
        for (int j = 1; j <= 20; j++) {
            int n = n_val[i];		// n为数据规模
            int* arr = new int[n];     // arr为待排序数组
            int min = 0, max = n;
            random_device seed;//硬件生成随机数种子
            ranlux48 engine(seed());//利用种子生成随机数引擎
            uniform_int_distribution<> distrib(min, max);//设置随机数范围，并为正态分布
            for (int i = 0; i < n; i++)
            {
                arr[i] = distrib(engine) % n;    // 生成随机数据
            }
            clock_t StartTime, EndTime; //定义计时开始和计时结束变量
            double time;        // 记录运行时间    
            StartTime = clock();    //开始计时
            Insertion_Sort(arr, n);    //排序
            EndTime = clock();      //结束计时
            time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
            out_txt_file << "数据规模为" << n << "时在第" << j << "组测试样本下所需运行时间为" << time << "秒" << endl;
            tot_time += time;
            delete[]arr;
        }
        out_txt_file << "数据规模为" << n_val[i] << "时平均运行时间为" << tot_time / 20 << "秒" << endl;
        out_txt_file << endl;
    }

    out_txt_file.close();
    return 0;
}
