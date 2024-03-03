#include "func.h"

int main() {
    int option; 
    do {
        cout <<"Choose an option: " << endl;
        cout << "1. Write to file" << endl;
        cout << "2. Read from file" << endl;
        cout << "3. Exit" << endl;
        
       
        cout << "Enter option: ";

        cin >> option;
        if (option == 1) {
            char filename[100];
            cout << "Enter filename: ";
            cin >> filename;
            Write(filename);
        } else if (option == 2) {
            char filename[100];
            cout << "Enter filename: ";
            cin >> filename;
            int n;
            Date a[n];
            Read(filename, n, a);
        } else if (option == 3) {
            cout << "Exit program" << endl;

            break;
        }

    } while (option != 3);
}