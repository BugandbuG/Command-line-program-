#include "func.h"

void Write(char filename[]) {
    int n ;
    cin >> n ;
    int a[n];
    for (int i = 0 ; i < n ; i++ ) {
        cin >> a[i];

    }
    FILE *fp = fopen(filename, "wb");
    fwrite(&n, sizeof(int) , 1, fp);
    fwrite(a,sizeof(int), n , fp );
    
}
void Read(char filename[], int &n, int a[]) {
    FILE *fp = fopen(filename, "rb");
    fread(&n, sizeof(int), 1, fp);
    fread(a, sizeof(int), n, fp);
    for (int i = 0; i < n -1; i++) {
        for (int j = i +1; j < n ;j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);

        }
    }
    if (n % 2 == 0) cout << (a[n/2] + a[n/2 -1]) / 2;
    else
    cout << a[n/2];
    
}
