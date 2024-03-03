#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[]) {
    if (argc != 7 || std::string(argv[1]) != "-s" || std::string(argv[3]) != "-d" || 
        (std::string(argv[5]) != "-numpart" && std::string(argv[5]) != "-sizeapart")) {
        std::cerr << "Usage: " << argv[0] << " -s PATH_OF_SOURCE_FILE -d PATH_OF_DESTINATION -numpart NUM_PARTS" << std::endl;
        std::cerr << "or: " << argv[0] << " -s PATH_OF_SOURCE_FILE -d PATH_OF_DESTINATION -sizeapart SIZE_IN_BYTES" << std::endl;
        return 1;
    }

    std::string src_path = argv[2];
    std::string dest_dir = argv[4];
    bool isNumPart = std::string(argv[5]) == "-numpart";
    int num_or_size = std::stoi(argv[6]);

    std::ifstream src(src_path, std::ios::binary | std::ios::ate);
    std::streamsize size = src.tellg();
    src.seekg(0, std::ios::beg);

    if (!src) {
        std::cerr << "Error opening source file: " << src_path << std::endl;
        return 1;
    }

    int size_each_part;
    if (isNumPart) {
        size_each_part = std::ceil(static_cast<double>(size) / num_or_size);
    } else {
        size_each_part = num_or_size;
    }

    char* buffer = new char[size_each_part];
    int count = 0;

    while (src.read(buffer, size_each_part)) {
        std::string dest_path = dest_dir + "/part" + std::to_string(count);
        std::ofstream dst(dest_path, std::ios::binary);
        dst.write(buffer, src.gcount());
        count++;
    }

    delete[] buffer;

    return 0;
}