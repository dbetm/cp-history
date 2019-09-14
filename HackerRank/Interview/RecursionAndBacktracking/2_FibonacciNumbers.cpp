#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int tabla[31];

int fibonacci(int n) {
    if(n <= 1) return tabla[n] = n;
    else if(tabla[n] != -1) return tabla[n];
    return tabla[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    cin >> n;
    memset(tabla, -1, sizeof(tabla));
    cout << fibonacci(n) << endl;
    return 0;
}
