//#include<bits/stdc++.h>
//#include<random>
//using namespace std;
//
//int dp[100005][15];
//
//int work(int floors, int eggs) {
//	// ��ʼ��
//	for (int i = 0; i <= floors; ++i) {
//		dp[i][1] = i;
//	}
//	for (int i = 0; i <= eggs; ++i) {
//		dp[0][i] = 0;
//		dp[1][i] = 1;
//	}
//	// ��̬ת��
//	for (int i = 1; i <= floors; ++i) {
//		for (int j = 2; j <= eggs; ++j) {
//			int res = 0x3f3f3f3f;
//			for (int k = 1; k <= i; ++k) {
//				res = min(res, max(dp[k - 1][j - 1], dp[i - k][j]) + 1);
//			}
//			dp[i][j] = res;
//		}
//	}
//	return dp[floors][eggs];
//}
//
//int main() {
//
//	int n_val[] = { 0, 10000, 20000,30000,40000,50000,60000,70000,80000,90000,100000 };
//	int k_val[] = { 0,2,3,4,5,6,7,8,9,10 };
//	for (int k = 7; k <= 10; k++) {
//		for (int j = 1; j <= 9; ++j) {
//			double tot_time = 0;
//			int nmin = n_val[k - 1], nmax = n_val[k];
//			int kmin = k_val[j - 1], kmax = k_val[j];
//
//			int test_time = 5;
//			for (int t = 0; t < test_time; t++) {
//				random_device seed;		//Ӳ���������������
//				ranlux48 engine1(seed());	//���������������������
//				uniform_int_distribution<> distrib1(nmin, nmax);	//�����������Χ����Ϊ���ȷֲ�
//				int floors = distrib1(engine1);	// �������¥����
//
//				ranlux48 engine2(seed());	//���������������������
//				uniform_int_distribution<> distrib2(kmin, kmax);	//�����������Χ����Ϊ���ȷֲ�
//				int eggs = distrib2(engine2);	// ������ɼ�����
//
//				clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
//				double time;        // ��¼����ʱ��    
//				StartTime = clock();    //��ʼ��ʱ
//
//				int cnt = work(floors, eggs);
//
//				EndTime = clock();      //������ʱ
//				time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
//				//printf("��%d�β���\n", t);
//				//printf("floors:%d, eggs:%d\n", floors, eggs);
//				//printf("���������ٲ��Դ���Ϊ��%d\n", cnt);
//				//printf("��ʱ %lf s\n", time);
//				//printf("\n");
//				tot_time += time;
//
//			}
//			printf("%lf ", tot_time / test_time);
//		}
//		cout << endl;
//	}
//}