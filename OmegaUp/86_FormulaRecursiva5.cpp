#include <iostream>

using namespace std;

long int a[1000] = {0};

long int fn(long int n, long int m) {
    if(n <= 2) {
        return 2*m;
    }
    else if(a[n] != 0) return a[n];
    else if(n == 1) {
        return a[n] = (-1 * fn(n-2, m));
    }
    else if(n > 3) {
        return a[n] = (2 + fn(n-1, m));
    }
    return 1;
}

int main() {
    long int m, n;
    cin >> n >> m;
    cout << fn(n, m) << endl;
    return 0;
}
