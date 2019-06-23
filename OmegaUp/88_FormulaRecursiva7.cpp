#include <iostream>
// https://omegaup.com/arena/problem/Formula-Recursiva-Siete#problems
using namespace std;

long int fn(long int n, long int m) {
    if(n < 5) return 20;
    else if(n == 5) return (fn(n - 2, m - 2) * 2);
    else return (fn(n - 1, m - 1) + 2);
}

int main() {
    long int m, n;
    cin >> n >> m;
    cout << fn(n, m) << endl;
    return 0;
}
