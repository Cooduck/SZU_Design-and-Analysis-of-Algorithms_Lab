//#include<bits/stdc++.h>
//#include<random>
//#include <ctime>
//using namespace std;
//
//struct Point {
//	double x, y;
//};
//
//int main() {
//	ofstream out_txt_file;
//	out_txt_file.open("./result_������.txt", ios::out | ios::trunc);
//	out_txt_file << fixed;
//
//	int n_val[] = { 100000, 200000,300000, 400000,500000,600000,700000,800000,900000, 1000000 };
//	for (int k = 5; k < 10; k++) {
//		double tot_time = 0;
//		int n = n_val[k];
//		for (int t = 0; t < 10; t++) {
//			Point* points = new Point[n];
//
//			int min = 0, max = n;
//			random_device seed;		//Ӳ���������������
//			ranlux48 engine(seed());	//���������������������
//			uniform_real_distribution<> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
//			for (int i = 0; i < n; i++) {
//				points[i].x = distrib(engine);
//				points[i].y = distrib(engine);
//			}
//
//			clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
//			double time;        // ��¼����ʱ��    
//			StartTime = clock();    //��ʼ��ʱ
//			double ans = n;		// ans��¼��̾���
//			for (int i = 0; i < n; i++) {
//				for (int j = i + 1; j < n; j++) {
//					double dis = sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) + (points[i].y - points[j].y) * (points[i].y - points[j].y));
//					if (ans > dis) ans = dis;
//				}
//			}
//			EndTime = clock();      //������ʱ
//			time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
//			out_txt_file << "���ݹ�ģΪ" << n << "ʱ�ڵ�" << t << "�������������������ʱ��Ϊ" << time << "��,��̾���Ϊ" << ans << endl;
//			tot_time += time;
//		}
//		out_txt_file << "���ݹ�ģΪ" << n_val[k] << "ʱƽ������ʱ��Ϊ" << tot_time / 10 << "��" << endl;
//		out_txt_file << endl;
//	}
//	return 0;
//}
