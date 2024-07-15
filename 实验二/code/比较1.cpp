//#include<bits/stdc++.h>
//#include<random>
//#define INF 0x3f3f3f3f
//using namespace std;
//
//struct Point {
//	double x, y;
//	Point() { x = 0, y = 0; }
//};
//
//
//int part(Point* points, int low, int high, char op) {
//	Point key = points[low];
//	if (op == 'x') {
//		while (low < high) {
//			while (low < high && points[high].x > key.x)high--;
//			points[low] = points[high];
//			while (low < high && points[low].x <= key.x)low++;
//			points[high] = points[low];
//		}
//	}
//	else if (op == 'y') {
//		while (low < high) {
//			while (low < high && points[high].y > key.y)high--;
//			points[low] = points[high];
//			while (low < high && points[low].y <= key.y)low++;
//			points[high] = points[low];
//		}
//	}
//	points[low] = key;
//	return low;
//}
//
//// 快速排序
//void quicksort(Point* points, int low, int high, char op) {
//	if (low < high) {
//		int mid = part(points, low, high, op);
//		quicksort(points, low, mid - 1, op);
//		quicksort(points, mid + 1, high, op);
//	}
//}
//
//// 合并策略一
//double Merge(Point* points, int left, int right, int mid, double min_dis, Point &p1, Point &p2) {
//	double d = min_dis;
//	Point* Y1 = new Point[right - left + 1];
//	Point* Y2 = new Point[right - left + 1];
//	int len1 = 0, len2 = 0;
//
//	for (int i = mid; i >= left; --i) {
//		if (points[i].x > points[mid].x - d) {
//			Y1[len1++] = points[i];
//		}
//		else break;
//	}
//	for (int i = mid + 1; i <= right; ++i) {
//		if (points[i].x < points[mid].x + d) {
//			Y2[len2++] = points[i];
//		}
//		else break;
//	}
//
//	for (int i = 0; i < len1; i++) {
//		for (int j = 0; j < len2; j++) {
//			double new_dis = sqrt((Y1[i].x - Y2[j].x) * (Y1[i].x - Y2[j].x) + 
//							(Y1[i].y - Y2[j].y) * (Y1[i].y - Y2[j].y));
//			if (min_dis > new_dis) {
//				min_dis = new_dis;
//				p1 = Y1[i], p2 = Y2[j];
//			}
//		}
//	}
//	delete[]Y1;
//	delete[]Y2;
//	return min_dis;
//}
//
//// 分治法
//double Divide(Point* points, int left, int right, Point &p1, Point &p2) {
//	if (left == right) return INF;	// 子集长度为1
//	else if (left + 1 == right) {	// 子集长度为2
//		p1 = points[left], p2 = points[right];
//		return sqrt(1.0 * (points[left].x - points[right].x) * (points[left].x - points[right].x) + 
//				(points[left].y - points[right].y) * (points[left].y - points[right].y));
//	}
//	else if (left + 2 == right) {	// 子集长度为3
//		double dis1 = sqrt((points[left].x - points[left + 1].x) * (points[left].x - points[left + 1].x) + 
//					  (points[left].y - points[left + 1].y) * (points[left].y - points[left + 1].y));
//		double dis2 = sqrt((points[left].x - points[right].x) * (points[left].x - points[right].x) + 
//					  (points[left].y - points[right].y) * (points[left].y - points[right].y));
//		double dis3 = sqrt((points[left + 1].x - points[right].x) * (points[left + 1].x - points[right].x) + 
//					  (points[left + 1].y - points[right].y) * (points[left + 1].y - points[right].y));
//		double minn_dis;
//		if (dis1 < dis2) {
//			if (dis1 < dis3) {
//				minn_dis = dis1;
//				p1 = points[left], p2 = points[left + 1];
//			}
//			else {
//				minn_dis = dis3;
//				p1 = points[left + 1], p2 = points[right];
//			}
//		}
//		else {
//			if (dis2 < dis3) {
//				minn_dis = dis2;
//				p1 = points[left], p2 = points[right];
//			}
//			else {
//				minn_dis = dis3;
//				p1 = points[left + 1], p2 = points[right];
//			}
//		}
//		return minn_dis;
//	}
//	else {
//		int mid = (left + right) >> 1;	// 分割点
//		Point q1, q2, q3, q4;
//		double min_dis;
//		double ldis = Divide(points, left, mid, q1, q2);		// 递归求解左子集
//		double rdis = Divide(points, mid + 1, right, q3, q4);	// 递归求解右子集
//		if (ldis < rdis) {
//			p1 = q1, p2 = q2;
//			min_dis = ldis;
//		}
//		else {
//			p1 = q3, p2 = q4;
//			min_dis = rdis;
//		}
//		min_dis = Merge(points, left, right, mid, min_dis, p1, p2);	// 合并左右子集
//		return min_dis;
//	}
//}
//
//// 蛮力法
//double work(Point * points, int n, Point &p1, Point &p2) {
//	double min_dis = n;		// ans记录最短距离
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			double dis = sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) + 
//						 (points[i].y - points[j].y) * (points[i].y - points[j].y));
//			if (min_dis > dis) {
//				min_dis = dis;
//				p1 = points[i], p2 = points[j];
//			}
//		}
//	}
//	return min_dis;
//}
//
//int main() {
//
//	int n = 5000;
//	double ans1;
//	double ans2;
//	for (int t = 0; t < 10; t++) {
//		Point p1, p2, p3, p4;
//		Point* points = new Point[n];	// 坐标点集
//		int min = 0, max = 10000;	// n为数据规模
//		random_device seed;		//硬件生成随机数种子
//		ranlux48 engine(seed());	//利用种子生成随机数引擎
//		uniform_real_distribution<> distrib(min, max);	//设置随机数范围，并为均匀分布
//		for (int i = 0; i < n; i++) {
//			points[i].x = distrib(engine);
//			points[i].y = distrib(engine);
//		}
//			
//		quicksort(points, 0, n - 1, 'x');
//
//		printf("N=5000时第%d次测试\n",t);
//		ans1 = work(points, n, p1, p2);
//		printf("蛮力法——最近点对为(%.2lf,%.2lf)和(%.2lf,%.2lf),最近距离为%lf\n", p1.x, p1.y, p2.x, p2.y, ans1);
//
//		ans2 = Divide(points, 0, n - 1, p3, p4);
//		printf("分治法策略一——最近点对为(%.2lf,%.2lf)和(%.2lf,%.2lf),最近距离为%lf\n", p3.x, p3.y, p4.x, p4.y, ans2);
//
//		delete[]points;
//	}
//	return 0;
//}