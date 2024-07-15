//#include<bits/stdc++.h>
//#include<random>
//using namespace std;
//
//
//int work(int floors, int eggs) {
//	if (eggs == 1 || floors <= 1) return floors;
//	
//	int res = 0x3f3f3f3f;
//	for (int i = 1; i <= floors; ++i) {
//		res = min(res, max(work(i - 1, eggs - 1), work(floors - i, eggs)) + 1);
//	}
//	return res;
//}
//
//int main() {
//
//	int n_val[] = { 0,5, 10, 15, 20 };
//	for (int k = 1; k <= 4; k++) {
//		double tot_time = 0;
//		int min = n_val[k-1], max = n_val[k];
//		int test_time = 20;
//		for (int t = 0; t < test_time; t++) {
//			random_device seed;		//硬件生成随机数种子
//			ranlux48 engine(seed());	//利用种子生成随机数引擎
//			uniform_int_distribution<> distrib(min, max);	//设置随机数范围，并为均匀分布
//			int floors = distrib(engine), eggs = 10;	// 随机生成楼层数和鸡蛋数
//
//			clock_t StartTime, EndTime; //定义计时开始和计时结束变量
//			double time;        // 记录运行时间    
//			StartTime = clock();    //开始计时
//			
//			int cnt = work(floors, eggs);
//
//			EndTime = clock();      //结束计时
//			time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
//			//printf("第%d次测试\n", t);
//			//printf("floors:%d, eggs:%d\n", floors, eggs);
//			//printf("最坏情况下最少测试次数为：%d\n", cnt);
//			//printf("用时 %lf s\n", time);
//			//printf("\n");
//			tot_time += time;
//
//		}
//		//printf("平均用时 %lf s\n", tot_time/test_time);
//		printf("%lf\n", tot_time / test_time);
//	}
//}