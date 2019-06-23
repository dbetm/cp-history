#include <iostream>
// https://omegaup.com/arena/problem/Formula-Recursiva-Seis#problems
using namespace std;

long int fn(long int n) {
    if(n <= 20) return 1;
    else {
        return (fn(n-5) + 5 + n);
    }
}

int main() {
    long int n;
    cin >> n;
    cout << fn(n) << endl;
    return 0;
}
