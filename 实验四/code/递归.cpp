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
//			random_device seed;		//Ӳ���������������
//			ranlux48 engine(seed());	//���������������������
//			uniform_int_distribution<> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
//			int floors = distrib(engine), eggs = 10;	// �������¥�����ͼ�����
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
//			//printf("��ʱ %lf s\n", time);
//			//printf("\n");
//			tot_time += time;
//
//		}
//		//printf("ƽ����ʱ %lf s\n", tot_time/test_time);
//		printf("%lf\n", tot_time / test_time);
//	}
//}