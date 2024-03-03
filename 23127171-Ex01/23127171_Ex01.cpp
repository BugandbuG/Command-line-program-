#include "func.h"

int main() {
    char inputFile[] = "input.bin";
    char outputFile[] = "output.bin";
    cout << "Choose an option: " << endl;
    cout <<"1. Write to file" << endl;
    cout << "2. Read from file" << endl;
    int option;
    cin >> option;
    if (option == 1) {
        Write(inputFile);
    } else if (option == 2) {
        int n;
        int a[100];
        Read(inputFile, n, a);
    }
}