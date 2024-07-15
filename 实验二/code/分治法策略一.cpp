//#include<bits/stdc++.h>
//#include<random>
//#define INF 0x3f3f3f3f
//using namespace std;
//
//struct Point {
//	double x, y;
//};
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
//void quicksort(Point* points, int low, int high, char op) {
//	if (low < high) {
//		int mid = part(points, low, high, op);
//		quicksort(points, low, mid - 1, op);
//		quicksort(points, mid + 1, high, op);
//	}
//}
//
//double Merge(Point* points, int left, int right, int mid, double min_dis) {
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
//			double new_dis = sqrt((Y1[i].x - Y2[j].x) * (Y1[i].x - Y2[j].x) + (Y1[i].y - Y2[j].y) * (Y1[i].y - Y2[j].y));
//			if (min_dis > new_dis) min_dis = new_dis;
//		}
//	}
//	delete[]Y1;
//	delete[]Y2;
//	return min_dis;
//}
//
//double Divide(Point* points, int left, int right) {
//  // right - left <= 2直接返回结果
//	if (left == right) return INF;
//	else if (left + 1 == right) {
//		return sqrt(1.0 * (points[left].x - points[right].x) * (points[left].x - points[right].x) + (points[left].y - points[right].y) * (points[left].y - points[right].y));
//	}
//	else if (left + 2 == right) {
//		double dis1 = sqrt((points[left].x - points[left + 1].x) * (points[left].x - points[left + 1].x) + (points[left].y - points[left + 1].y) * (points[left].y - points[left + 1].y));
//		double dis2 = sqrt((points[left].x - points[right].x) * (points[left].x - points[right].x) + (points[left].y - points[right].y) * (points[left].y - points[right].y));
//		double dis3 = sqrt((points[left + 1].x - points[right].x) * (points[left + 1].x - points[right].x) + (points[left + 1].y - points[right].y) * (points[left + 1].y - points[right].y));
//		dis1 = dis1 < dis2 ? dis1 : dis2;
//		dis1 = dis1 < dis3 ? dis1 : dis3;
//		return dis1;
//	}
//	else {
//		int mid = (left + right) >> 1;
//		double ldis = Divide(points, left, mid);		// 求左子集最近点对
//		double rdis = Divide(points, mid + 1, right);	// 求右子集最近点对
//		double min_dis = ldis < rdis ? ldis : rdis;
//		min_dis = Merge(points, left, right, mid, min_dis);	// 合并左右子集
//		return min_dis;
//	}
//}
//
//
//
//int main() {
//	ofstream out_txt_file;
//	out_txt_file.open("./result_分治法1_double.txt", ios::out | ios::trunc);
//	out_txt_file << fixed;
//
//	int n_val[] = { 100000,200000, 300000,400000, 500000,600000,700000,800000,900000,1000000 };
//	for (int k = 0; k < 10; k++) {
//		double tot_time = 0;
//		int n = n_val[k];
//		for (int t = 0; t < 10; t++) {
//			Point* points = new Point[n];	// 坐标点集
//			int min = 0, max = n;	// n为数据规模
//			random_device seed;		//硬件生成随机数种子
//			ranlux48 engine(seed());	//利用种子生成随机数引擎
//			uniform_real_distribution<> distrib(min, max);	//设置随机数范围，并为均匀分布
//			for (int i = 0; i < n; i++) {
//				points[i].x = distrib(engine);
//				points[i].y = distrib(engine);
//			}
//
//			clock_t StartTime, EndTime; //定义计时开始和计时结束变量
//			double time;        // 记录运行时间    
//			StartTime = clock();    //开始计时
//
//			quicksort(points, 0, n - 1, 'x');
//			double ans = Divide(points, 0, n - 1);
//
//			EndTime = clock();      //结束计时
//			time = (double)((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;    //计算差值并转换为秒
//			out_txt_file << "数据规模为" << n << "时在第" << t << "组测试样本下所需运行时间为";
//			out_txt_file << fixed << setprecision(6) << time;
//			out_txt_file << "秒,最短距离为" << ans << endl;
//			tot_time += time;
//			delete[]points;
//		}
//		out_txt_file << "数据规模为" << n_val[k] << "时平均运行时间为";
//		out_txt_file << fixed << setprecision(6) << tot_time / 10;
//		out_txt_file << "秒" << endl;
//		out_txt_file << endl;
//	}
//	return 0;
//}
