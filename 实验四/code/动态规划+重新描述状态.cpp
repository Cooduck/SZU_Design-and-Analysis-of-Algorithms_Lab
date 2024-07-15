//#include<bits/stdc++.h>
//#include<random>
//using namespace std;
//
//int work(int **dp, int floors, int eggs) {
//	if (floors <= 1) return floors;
//	// ��ʼ��
//	for (int i = 0; i <= eggs; ++i) {
//		dp[0][i] = 0;
//		dp[i][0] = 0;
//		dp[i][1] = 1;
//	}
//
//	// ��̬ת��
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
//			random_device seed;		//Ӳ���������������
//			ranlux48 engine(seed());	//���������������������
//			uniform_int_distribution<long long> distrib(min, maxx);	//�����������Χ����Ϊ���ȷֲ�
//			int floors = distrib(engine), eggs = 2;	// �������¥�����ͼ�����
//
//			// ������άdp����
//			int** dp = new int* [eggs+1];
//			for (int i = 0; i <= eggs; ++i) {
//				dp[i] = new int[floors];
//			}
//
//			clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
//			double time;        // ��¼����ʱ��    
//			StartTime = clock();    //��ʼ��ʱ
//			
//			int cnt = work(dp, floors, eggs);
//
//			EndTime = clock();      //������ʱ
//			time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
//			printf("��%d�β���\n", t);
//			printf("floors:%d, eggs:%d\n", floors, eggs);
//			printf("���������ٲ��Դ���Ϊ��%d\n", cnt);
//			printf("��ʱ %lf s\n", time);
//			printf("\n");
//			tot_time += time;
//
//			// ɾ����άdp����
//			for (int i = 0; i <= eggs; ++i) {
//				delete[] dp[i];
//			}
//			delete[] dp;
//		}
//		printf("ƽ����ʱ %lf s\n", tot_time/test_time);
//	}
//}