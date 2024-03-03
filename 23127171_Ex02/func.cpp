#include "func.h"
bool cmp(Date a, Date b) {
    if (a.year > b.year) return true;
    if (a.year < b.year) return false;
    if (a.month > b.month) return true;
    if (a.month < b.month) return false;
    if (a.day > b.day) return true;
    return false;
}
void Write(char filename[]) {
    // Date a[];
    int n ;

    FILE *f = fopen(filename, "wb");
    cout <<"Enter number of date: ";

    cin >> n;
    Date a[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter day: ";
        cin >> a[i].day;
        cout << "Enter month: ";
        cin >> a[i].month;
        cout << "Enter year: ";
        cin >> a[i].year;

    
    }
    fwrite(&n, sizeof(int), 1, f);
    fwrite(&a, sizeof(Date), n, f);
}
void Read(char filename[], int n, Date a[]) {
    FILE *f = fopen(filename, "rb");
    fread(&n, sizeof(int), 1, f);
    fread(&a, sizeof(Date), n, f);
    for (int i = 0 ; i < n  -1; i++) {
        for (int j = i +1 ; j < n ;j++) {
            if (cmp(a[i], a[j]) ) {
                Date temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout <<"The newest date: " << a[n-1].day << "/" << a[n-1].month << "/" << a[n-1].year << endl;
}