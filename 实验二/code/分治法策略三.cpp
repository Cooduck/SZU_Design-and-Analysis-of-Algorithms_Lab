#include<bits/stdc++.h>
#include<random>
#define INF 0x3f3f3f3f
using namespace std;

struct Point {
	double x, y;
};

int part(Point* points, int low, int high, char op) {
	Point key = points[low];
	if (op == 'x') {
		while (low < high) {
			while (low < high && points[high].x > key.x)high--;
			points[low] = points[high];
			while (low < high && points[low].x <= key.x)low++;
			points[high] = points[low];
		}
	}
	else if (op == 'y') {
		while (low < high) {
			while (low < high && points[high].y > key.y)high--;
			points[low] = points[high];
			while (low < high && points[low].y <= key.y)low++;
			points[high] = points[low];
		}
	}
	points[low] = key;
	return low;
}

void quicksort(Point* points, int low, int high, char op) {
	if (low < high) {
		int mid = part(points, low, high, op);
		quicksort(points, low, mid - 1, op);
		quicksort(points, mid + 1, high, op);
	}
}

double Merge(Point* points, int left, int right, int mid, double min_dis) {
	double d = min_dis;
	Point* Y1 = new Point[right - left + 1];
	Point* Y2 = new Point[right - left + 1];
	int len1 = 0, len2 = 0;

	for (int i = mid; i >= left; --i) {
		if (points[i].x > points[mid].x - d) {
			Y1[len1++] = points[i];
		}
		else break;
	}
	for (int i = mid + 1; i <= right; ++i) {
		if (points[i].x < points[mid].x + d) {
			Y2[len2++] = points[i];
		}
		else break;
	}
	quicksort(Y1, 0, len1 - 1, 'y');	// ��Y1��������������
	quicksort(Y2, 0, len2 - 1, 'y');	// ��Y2��������������

	int low_point = 0;	// �½�ָ�룬��ʼ��Ϊ0
	int flag;	// ���
	for (int i = 0; i < len1; i++) {
		// base_y1Ϊ�����±߽磬base_y2Ϊ�����ϱ߽磬base_xΪ�����ұ߽�
		double base_y1 = Y1[i].y - min_dis, base_y2 = Y1[i].y + min_dis;
		double base_x = Y1[i].x + min_dis;
		flag = 1;	// ��ʼ�����
		for (int j = low_point; j < len2; j++) {
			if (flag && Y2[j].y > Y1[i].y) {	// ���ֵ�һ�����������Y1[i]�ĵ�Y2[j]
				low_point = j;	// ����ָ��
				flag = 0;		// �ı�ǣ�˵��ָ���Ѹ��£����α���Y2�����ٸ���
			}
			if (Y2[j].x >= base_x || Y2[j].y <= base_y1) continue;	// Y2���ھ����Ҳ������ĵ�ֱ������
			else if (Y2[j].x < base_x && Y2[j].y > base_y1 && Y2[j].y < base_y2) {	// �����ھ����ڵĵ�Ծ���
				double new_dis = sqrt((Y1[i].x - Y2[j].x) * (Y1[i].x - Y2[j].x) + 
								(Y1[i].y - Y2[j].y) * (Y1[i].y - Y2[j].y));
				min_dis = min_dis < new_dis ? min_dis : new_dis;
			}
			else if (Y2[j].y >= base_y2) break;	// ��Y2�еĵ����������ھ����ϱ߽磬��ֹͣѭ��
		}
	}
	delete[]Y1;
	delete[]Y2;
	return min_dis;
}

double Divide(Point* points, int left, int right) {
	if (left == right) return INF;
	else if (left + 1 == right) {
		return sqrt((points[left].x - points[right].x) * (points[left].x - points[right].x) + (points[left].y - points[right].y) * (points[left].y - points[right].y));
	}
	else if (left + 2 == right) {
		double dis1 = sqrt((points[left].x - points[left+1].x) * (points[left].x - points[left + 1].x) + (points[left].y - points[left + 1].y) * (points[left].y - points[left + 1].y));
		double dis2 = sqrt((points[left].x - points[right].x) * (points[left].x - points[right].x) + (points[left].y - points[right].y) * (points[left].y - points[right].y));
		double dis3 = sqrt((points[left + 1].x - points[right].x) * (points[left + 1].x - points[right].x) + (points[left + 1].y - points[right].y) * (points[left + 1].y - points[right].y));
		dis1 = dis1 < dis2 ? dis1 : dis2;
		dis1 = dis1 < dis3 ? dis1 : dis3;
		return dis1;
	}
	else {
		int mid = (left + right) >> 1;
		double ldis = Divide(points, left, mid);
		double rdis = Divide(points, mid + 1, right);
		double min_dis = ldis < rdis ? ldis : rdis;
		min_dis = Merge(points, left, right, mid, min_dis);
		return min_dis;
	}
}

int main() {
	ofstream out_txt_file;
	out_txt_file.open("./result_���η�4.txt", ios::out | ios::trunc);
	out_txt_file << fixed;

	int n_val[] = { 100000,200000, 300000,400000, 500000,600000,700000,800000,900000,1000000 };
	for (int k = 0;k < 10; k++) {
		double tot_time = 0;
		int n = n_val[k];
		for (int t = 0; t < 10; t++) {
			Point* points = new Point[n];	// ����㼯
			int min = 0, max = n;	// nΪ���ݹ�ģ
			random_device seed;		//Ӳ���������������
			ranlux48 engine(seed());	//���������������������
			uniform_real_distribution<> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
			for (int i = 0; i < n; i++) {
				points[i].x = distrib(engine);
				points[i].y = distrib(engine);
			}

			clock_t StartTime, EndTime; //�����ʱ��ʼ�ͼ�ʱ��������
			double time;        // ��¼����ʱ��    
			
			StartTime = clock();    //��ʼ��ʱ

			quicksort(points, 0, n - 1, 'x');
			double ans = Divide(points, 0, n - 1);

			EndTime = clock();      //������ʱ
			time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;    //�����ֵ��ת��Ϊ��
			cout << "���ݹ�ģΪ" << n << "ʱ�ڵ�" << t << "�������������������ʱ��Ϊ" << time << "��,��̾���Ϊ" << ans << endl;
			tot_time += time;
			delete[]points;
		}
		cout << "���ݹ�ģΪ" << n_val[k] << "ʱƽ������ʱ��Ϊ" << tot_time / 10 << "��" << endl;
		cout << endl;
	}
	return 0;
}
