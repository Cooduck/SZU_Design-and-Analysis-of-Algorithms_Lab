//#include<bits/stdc++.h>
//#include<random>
//#include <ctime>
//using namespace std;
//
//struct Point {
//	double x, y;
//};
//
//int main() {
//	ofstream out_txt_file;
//	out_txt_file.open("./result_蛮力法.txt", ios::out | ios::trunc);
//	out_txt_file << fixed;
//
//	int n_val[] = { 100000, 200000,300000, 400000,500000,600000,700000,800000,900000, 1000000 };
//	for (int k = 5; k < 10; k++) {
//		double tot_time = 0;
//		int n = n_val[k];
//		for (int t = 0; t < 10; t++) {
//			Point* points = new Point[n];
//
//			int min = 0, max = n;
//			random_device seed;		//硬件生成随机数种子
//			ranlux48 engine(seed());	//利用种子生成随机数引擎
//			uniform_real_distribution<> distrib(min, max);	//设置随机数范围，并为均匀分布
//			for (int i = 0; i < n; i++) {
//				points[i].x = distrib(engine);
//				points[i].y = distrib(engine);
//			}
//
//			clock_t StartTime, EndTime; //定义计时开始和计时结束变量
//			double time;        // 记录运行时间    
//			StartTime = clock();    //开始计时
//			double ans = n;		// ans记录最短距离
//			for (int i = 0; i < n; i++) {
//				for (int j = i + 1; j < n; j++) {
//					double dis = sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) + (points[i].y - points[j].y) * (points[i].y - points[j].y));
//					if (ans > dis) ans = dis;
//				}
//			}
//			EndTime = clock();      //结束计时
//			time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
//			out_txt_file << "数据规模为" << n << "时在第" << t << "组测试样本下所需运行时间为" << time << "秒,最短距离为" << ans << endl;
//			tot_time += time;
//		}
//		out_txt_file << "数据规模为" << n_val[k] << "时平均运行时间为" << tot_time / 10 << "秒" << endl;
//		out_txt_file << endl;
//	}
//	return 0;
//}
