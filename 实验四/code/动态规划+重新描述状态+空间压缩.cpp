//#include<bits/stdc++.h>
//#include<random>
//#define int long long
//using namespace std;
//
//int work(int *dp, int floors, int eggs) {
//	if (floors <= 1) return floors;
//	// 初始化
//	dp[0] = 0;
//	for (int i = 1; i <= eggs; ++i) {
//		dp[i] = 1;	// m = 1 时最坏情况下最多楼层数
//	}
//
//	// 动态转移
//	int ans = 0;
//	for (int m = 2; ; ++m) {
//		for (int k = eggs; k >= 1; --k) {
//			dp[k] = dp[k] + dp[k - 1] + 1;
//		}
//		if (dp[eggs] >= floors) {
//			ans = m;
//			break;
//		}
//	}
//	return ans;
//}
//
//signed main() {
//
//	int n_val[] = { 9e11, 1e12, 1e13, 1e14, 1e15, 1e16 ,1e17, 1e18 };
//	for (int k = 1; k <= 7; k++) {
//		double tot_time = 0;
//		int min = n_val[k - 1], max = n_val[k];
//		int test_time = 10;
//		for (int t = 0; t < test_time; t++) {
//			random_device seed;		//硬件生成随机数种子
//			ranlux48 engine(seed());	//利用种子生成随机数引擎
//			uniform_int_distribution<long long> distrib(min, max);	//设置随机数范围，并为均匀分布
//			int floors = distrib(engine), eggs = 2;	// 随机生成楼层数和鸡蛋数
//
//			// 创建dp数组
//			int* dp = new int [eggs+1];
//
//			clock_t StartTime, EndTime; //定义计时开始和计时结束变量
//			double time;        // 记录运行时间    
//			StartTime = clock();    //开始计时
//			
//			int cnt = work(dp, floors, eggs);
//
//			EndTime = clock();      //结束计时
//			time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
//			printf("第%d次测试\n", t);
//			printf("floors:%d, eggs:%d\n", floors, eggs);
//			printf("最坏情况下最少测试次数为：%d\n", cnt);
//			printf("用时 %lf s\n", time);
//			printf("\n");
//			tot_time += time;
//
//			// 删除dp数组
//			delete[] dp;
//		}
//		printf("平均用时 %lf s\n", tot_time/test_time);
//	}
//}