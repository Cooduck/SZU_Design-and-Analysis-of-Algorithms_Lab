//#include <iostream>
//#include <fstream>
//#include <string>
//
//int main() {
//    // 打开 .col 文件
//    std::ifstream input_file("le450_25a.col");
//    if (!input_file.is_open()) {
//        std::cerr << "无法打开输入文件" << std::endl;
//        return 1;
//    }
//
//    // 打开输出文件
//    std::ofstream output_file("le450_25a.txt");
//    if (!output_file.is_open()) {
//        std::cerr << "无法打开输出文件" << std::endl;
//        return 1;
//    }
//
//    // 读取输入文件内容，并写入输出文件
//    std::string line;
//    while (std::getline(input_file, line)) {
//        if (line[0] == 'p') {
//            output_file << line.substr(7) << std::endl;
//        }
//        else if(line[0] == 'e') output_file << line.substr(2) << std::endl;
//    }
//
//    // 关闭文件
//    input_file.close();
//    output_file.close();
//
//    std::cout << "内容已成功写入到 le450_25a.txt 文件中" << std::endl;
//
//    return 0;
//}
//
