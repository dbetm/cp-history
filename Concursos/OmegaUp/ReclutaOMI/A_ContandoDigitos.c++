#include <bits/stdc++.h>

using namespace std;

int64_t sumasRangos[]
    = {9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 788888898};

int main() {
    int64_t suma = 0;
    int n;
    cin >> n;

    if(n <= 9) {
        suma = n;
    }
    else if(n <= 99) {
        suma = sumasRangos[0];
        suma += ((n - 10) + 1)*2;
    }
    else if(n <= 999) {
        suma = sumasRangos[1];
        suma += ((n - 100) + 1)*3;
    }
    else if(n <= 9999) {
        suma = sumasRangos[2];
        suma += ((n - 1000) + 1)*4;
    }
    else if(n <= 99999) {
        suma = sumasRangos[3];
        suma += ((n - 10000) + 1)*5;
    }
    else if(n <= 999999) {
        suma = sumasRangos[4];
        suma += ((n - 100000) + 1)*6;
    }
    else if(n <= 9999999) {
        suma = sumasRangos[5];
        suma += ((n - 1000000) + 1)*7;
    }
    else if(n <= 99999999) {
        suma = sumasRangos[6];
        suma += ((n - 10000000) + 1)*8;
    }
    else {
        suma = sumasRangos[8];
    }

    cout << suma << endl;
    return 0;
}
