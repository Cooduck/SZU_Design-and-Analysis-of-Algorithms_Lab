//#include<bits/stdc++.h>
//#include<random>
//#define int long long
//using namespace std;
//
//int work(int *dp, int floors, int eggs) {
//	if (floors <= 1) return floors;
//	// ��ʼ��
//	dp[0] = 0;
//	for (int i = 1; i <= eggs; ++i) {
//		dp[i] = 1;	// m = 1 ʱ���������¥����
//	}
//
//	// ��̬ת��
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
//			random_device seed;		//Ӳ���������������
//			ranlux48 engine(seed());	//���������������������
//			uniform_int_distribution<long long> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
//			int floors = distrib(engine), eggs = 2;	// �������¥�����ͼ�����
//
//			// ����dp����
//			int* dp = new int [eggs+1];
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
//			// ɾ��dp����
//			delete[] dp;
//		}
//		printf("ƽ����ʱ %lf s\n", tot_time/test_time);
//	}
//}