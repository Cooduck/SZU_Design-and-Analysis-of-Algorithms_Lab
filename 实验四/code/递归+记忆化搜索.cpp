//#include<bits/stdc++.h>
//#include<random>
//using namespace std;
//
//int** dp;
//
//int work(int floors, int eggs) {
//	if (dp[floors][eggs] != 0x3f3f3f3f) return dp[floors][eggs];
//	if (eggs == 1 || floors <= 1) {
//		dp[floors][eggs] = floors;
//		return floors;
//	}
//
//	int res = 0x3f3f3f3f;
//	for (int i = 1; i <= floors; ++i) {
//		res = min(res, max(work(i - 1, eggs - 1), work(floors - i, eggs)) + 1);
//	}
//	dp[floors][eggs] = res;
//	return res;
//}
//
//int main() {
//
//	int n_val[] = { 0, 500, 1000, 1500, 2000 };
//	int eggs_val[] = { 0,2,4,6,8,10,12,14,16,18,20 };
//	for (int k = 1; k <= 4; k++) {
//		double tot_time = 0;
//		int min = n_val[k - 1], max = n_val[k];
//		int test_time = 20;
//		if (k >= 8) {
//			test_time = 5;
//		}
//		printf("��ģΪ%d\n", n_val[k]);
//		for (int t = 0; t < test_time; t++) {
//			random_device seed;		//Ӳ���������������
//			ranlux48 engine(seed());	//���������������������
//			uniform_int_distribution<> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
//			int floors = distrib(engine), eggs = 10;	// �������¥�����ͼ�����
//			
//			// ������άdp����
//			dp = new int* [floors + 1];
//			for (int i = 0; i <= floors; ++i) {
//				dp[i] = new int[eggs + 1];
//				for (int j = 0; j <= eggs; ++j) dp[i][j] = 0x3f3f3f3f;
//			}
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
//			// ɾ����άdp����
//			for (int i = 0; i <= floors; ++i) {
//				delete[] dp[i];
//			}
//			delete[] dp;
//		}
//		printf("ƽ����ʱ %lf s\n\n", tot_time / test_time);
//	}
//}