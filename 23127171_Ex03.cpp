#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " SOURCE_FILE DESTINATION_FILE" << std::endl;
        return 1;
    }
    
    ifstream src(argv[2], ios::binary);
    ofstream dst(argv[4], ios::binary);   

    if (!src) {
        cerr << "Error opening source file: " << argv[2] << endl;
        return 1;
    }
    
    if (!dst) {
        cerr << "Error opening destination file: " << argv[4] << endl;
        return 1;
    }

    dst << src.rdbuf();

    return 0;
}