#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 5 || std::string(argv[1]) != "-s" || std::string(argv[3]) != "-d") {
        std::cerr << "Usage: " << argv[0] << " -s PATH_OF_PART01 -d PATH_OF_DESTINATION" << std::endl;
        return 1;
    }

    std::string part_path = argv[2];
    std::string dest_path = argv[4];

    std::ofstream dst(dest_path, std::ios::binary);

    if (!dst) {
        std::cerr << "Error opening destination file: " << dest_path << std::endl;
        return 1;
    }

    int count = 1;
    while (true) {
        std::string current_part_path = part_path.substr(0, part_path.size() - 2) + (count < 10 ? "0" : "") + std::to_string(count);
        std::ifstream src(current_part_path, std::ios::binary);

        if (!src) {
            if (count == 1) {
                std::cerr << "Error opening source file: " << current_part_path << std::endl;
                return 1;
            } else {
                break;
            }
        }

        dst << src.rdbuf();
        count++;
    }

    return 0;
}