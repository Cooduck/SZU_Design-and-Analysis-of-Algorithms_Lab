//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include <fstream>
//
//int g[100][100];
//int w[100];
//int c[100];
//std::string name[100];
//
//int main() {
//	freopen("team32_origin.txt", "r", stdin);
//	std::ofstream outFile("team32.txt", std::ios::out | std::ios::trunc);
//
//	int n;
//	int tmp;
//	std::cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		std::cin >> name[i];
//		std::cin >> w[i] >> tmp >> c[i];
//		for (int j = 1; j <= n; j++) {
//			std::cin >> g[i][j];
//		}
//	}
//
//	outFile << n << std::endl;
//	for (int i = 1; i <= n; i++) {
//		outFile << name[i] << " ";
//	}
//	outFile << std::endl;
//
//	for (int i = 1; i <= n; i++) {
//		outFile << w[i] << " " << c[i] << std::endl;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			outFile << g[i][j] << " ";
//		}
//		outFile << std::endl;
//	}
//
//
//	return 0;
//}