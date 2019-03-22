#include <bits/stdc++.h>

using namespace std;

int obtenerNumeroFibonacci(int);

int main(int argc, char const *argv[]) {
    int n;
    cout << "Escribe n: ";
    cin >> n;
    cout << obtenerNumeroFibonacci(n) << endl;
    return 0;
}

int obtenerNumeroFibonacci(int n) {
    // Versión iterativa, dinámica, de la sucesión del Fibonacci
    int A[n];
    int ans;
    A[0] = 0;
    A[1] = 1;
    for (int i = 2; i < n; i++) A[i] = A[i - 1] + A[i - 2];
    ans = A[n-1];
    return ans;
}
