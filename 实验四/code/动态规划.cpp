//#include<bits/stdc++.h>
//#include<random>
//using namespace std;
//
//
//int work(int **dp, int floors, int eggs) {
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
//	int n_val[] = { 0, 100, 1000, 10000, 100000, 200000, 400000, 600000, 800000, 1000000 };
//	for (int k = 1; k <= 4; k++) {
//		double tot_time = 0;
//		int min = 0, max = n_val[k];
//		int test_time = 5;
//		printf("��ģΪ%d\n", n_val[k]);
//		for (int t = 0; t < test_time; t++) {
//			random_device seed;		//Ӳ���������������
//			ranlux48 engine(seed());	//���������������������
//			uniform_int_distribution<> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
//			int floors = distrib(engine), eggs = 2;	// �������¥�����ͼ�����
//
//			// ������άdp����
//			int** dp = new int* [floors + 1];
//			for (int i = 0; i <= floors; ++i) {
//				dp[i] = new int[eggs + 1];
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
//			//printf("��%d�β���\n", t);
//			//printf("floors:%d, eggs:%d\n", floors, eggs);
//			//printf("���������ٲ��Դ���Ϊ��%d\n", cnt);
//			printf("��ʱ %lf s\n", time);
//			//printf("\n");
//			tot_time += time;
//
//			// ɾ����άdp����
//			for (int i = 0; i <= floors; ++i) {
//				delete[] dp[i];
//			}
//			delete[] dp;
//		}
//		printf("ƽ����ʱ %lf s\n\n", tot_time/test_time);
//	}
//}