//#include<bits/stdc++.h>
//#include<random>
//using namespace std;
//
//int dp[100000005][2];
//
//int work( int floors, int eggs) {
//	// 初始化
//	for (int i = 0; i <= floors; ++i) {
//		dp[i][1] = i;
//	}
//	for (int i = 0; i <= eggs; ++i) {
//		dp[0][i] = 0;
//		dp[1][i] = 1;
//	}
//
//	// 动态转移
//	for (int i = 1; i <= floors; ++i) {
//		for (int j = 2; j <= eggs; ++j) {
//			int l = 1, r = i, mid;
//			int res = 0x3f3f3f3f;
//			while (l <= r) {
//				mid = (l + r) >> 1;
//
//				if (dp[mid - 1][j - 1] == dp[i - mid][j]) {//刚好找到交点
//					res = min(res, dp[mid - 1][j - 1] + 1);
//					break;
//				}
//				else if (dp[mid - 1][j - 1] > dp[i - mid][j]) {
//					r = mid - 1;
//					res = min(res, dp[mid - 1][j - 1] + 1);
//				}
//				else if (dp[mid - 1][j - 1] < dp[i - mid][j]) {
//					l = mid + 1;
//					res = min(res, dp[i - mid][j] + 1);
//				}
//			}
//			dp[i][j] = res;
//		}
//	}
//	return dp[floors][eggs];
//}
//
//int main() {
//
//	int n_val[] = { 0, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 150000, 200000 };
//	int egg_val[] = { 0,2,4,6,8,10,12,14,16,18,20 };
//	for (int k = 1; k <= 6; k++) {
//		double tot_time = 0;
//		int min = n_val[k-1], max = n_val[k];
//		int test_time = 30;
//		//printf("规模为%d\n", n_val[k]);
//		for (int t = 0; t < test_time; t++) {
//			random_device seed;		//硬件生成随机数种子
//			ranlux48 engine(seed());	//利用种子生成随机数引擎
//			uniform_int_distribution<> distrib(min, max);	//设置随机数范围，并为均匀分布
//			int floors = distrib(engine), eggs = 2;	// 随机生成楼层数和鸡蛋数
//			
//			// 创建二维dp数组
//			
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
//			printf("用时 %lf s\n", time);
//			//printf("\n");
//			tot_time += time;
//
//			
//		}
//		//printf("平均用时 %lf s\n\n", tot_time / test_time);
//		printf("%lf\n", tot_time / test_time);
//	}
//}