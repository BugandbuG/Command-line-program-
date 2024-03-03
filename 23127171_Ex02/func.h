#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};
bool cmp(Date a, Date b) ;
void Read(char filename[], int n, Date a[]);
void Write(char filename[] );