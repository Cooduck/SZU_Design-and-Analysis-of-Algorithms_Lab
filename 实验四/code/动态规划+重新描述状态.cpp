//#include<bits/stdc++.h>
//#include<random>
//using namespace std;
//
//int work(int **dp, int floors, int eggs) {
//	if (floors <= 1) return floors;
//	// 初始化
//	for (int i = 0; i <= eggs; ++i) {
//		dp[0][i] = 0;
//		dp[i][0] = 0;
//		dp[i][1] = 1;
//	}
//
//	// 动态转移
//	int ans = 0;
//	for (int m = 2; ; ++m) {
//		for (int k = 1; k <= eggs; ++k) {
//			dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
//		}
//		if (dp[eggs][m] >= floors) {
//			ans = m;
//			break;
//		}
//	}
//	return ans;
//}
//
//int main() {
//
//	int n_val[] = { 9e7, 1e8, 2e8, 4e8, 6e8, 8e8 ,1e9, 2e9 };
//	for (int k = 1; k <= 1; k++) {
//		double tot_time = 0;
//		int min = n_val[k - 1], maxx = n_val[k];
//		int test_time = 10000;
//		for (int t = 0; t < test_time; t++) {
//			random_device seed;		//硬件生成随机数种子
//			ranlux48 engine(seed());	//利用种子生成随机数引擎
//			uniform_int_distribution<long long> distrib(min, maxx);	//设置随机数范围，并为均匀分布
//			int floors = distrib(engine), eggs = 2;	// 随机生成楼层数和鸡蛋数
//
//			// 创建二维dp数组
//			int** dp = new int* [eggs+1];
//			for (int i = 0; i <= eggs; ++i) {
//				dp[i] = new int[floors];
//			}
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
//			// 删除二维dp数组
//			for (int i = 0; i <= eggs; ++i) {
//				delete[] dp[i];
//			}
//			delete[] dp;
//		}
//		printf("平均用时 %lf s\n", tot_time/test_time);
//	}
//}