//#include <iostream>
//#include <fstream>
//#include <string>
//
//int main() {
//    // �� .col �ļ�
//    std::ifstream input_file("le450_25a.col");
//    if (!input_file.is_open()) {
//        std::cerr << "�޷��������ļ�" << std::endl;
//        return 1;
//    }
//
//    // ������ļ�
//    std::ofstream output_file("le450_25a.txt");
//    if (!output_file.is_open()) {
//        std::cerr << "�޷�������ļ�" << std::endl;
//        return 1;
//    }
//
//    // ��ȡ�����ļ����ݣ���д������ļ�
//    std::string line;
//    while (std::getline(input_file, line)) {
//        if (line[0] == 'p') {
//            output_file << line.substr(7) << std::endl;
//        }
//        else if(line[0] == 'e') output_file << line.substr(2) << std::endl;
//    }
//
//    // �ر��ļ�
//    input_file.close();
//    output_file.close();
//
//    std::cout << "�����ѳɹ�д�뵽 le450_25a.txt �ļ���" << std::endl;
//
//    return 0;
//}
//
