//#include<bits/stdc++.h>
//#include<random>
//using namespace std;
//
//int dp[100000005][2];
//
//int work( int floors, int eggs) {
//	// ��ʼ��
//	for (int i = 0; i <= floors; ++i) {
//		dp[i][1] = i;
//	}
//	for (int i = 0; i <= eggs; ++i) {
//		dp[0][i] = 0;
//		dp[1][i] = 1;
//	}
//
//	// ��̬ת��
//	for (int i = 1; i <= floors; ++i) {
//		for (int j = 2; j <= eggs; ++j) {
//			int l = 1, r = i, mid;
//			int res = 0x3f3f3f3f;
//			while (l <= r) {
//				mid = (l + r) >> 1;
//
//				if (dp[mid - 1][j - 1] == dp[i - mid][j]) {//�պ��ҵ�����
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
//		//printf("��ģΪ%d\n", n_val[k]);
//		for (int t = 0; t < test_time; t++) {
//			random_device seed;		//Ӳ���������������
//			ranlux48 engine(seed());	//���������������������
//			uniform_int_distribution<> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
//			int floors = distrib(engine), eggs = 2;	// �������¥�����ͼ�����
//			
//			// ������άdp����
//			
//
//			clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
//			double time;        // ��¼����ʱ��    
//			StartTime = clock();    //��ʼ��ʱ
//
//			int cnt = work(floors, eggs);
//
//			EndTime = clock();      //������ʱ
//			time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
//			//printf("��%d�β���\n", t);
//			//printf("floors:%d, eggs:%d\n", floors, eggs);
//			//printf("���������ٲ��Դ���Ϊ��%d\n", cnt);
//			printf("��ʱ %lf s\n", time);
//			//printf("\n");
//			tot_time += time;
//
//			
//		}
//		//printf("ƽ����ʱ %lf s\n\n", tot_time / test_time);
//		printf("%lf\n", tot_time / test_time);
//	}
//}