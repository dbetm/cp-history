#include <bits/stdc++.h>

using namespace std;

int bc(int n, int k);

int main() {
    int n, k;
    cout << "Type n: ";
    cin >> n;
    cout << "Type k: ";
    cin >> k;
    cout << "The binomial coefficient is: " << bc(n, k) << endl;
    return 0;
}

int bc(int n, int k) {
    int res = 1;
    // Al ver el triángulo de pascal vemos que n-ésima línea es simétrica
    // entonces podemos hacer menos cálculos si k > n-k
    if(k > (n-k)) k = n-k;

    // Calculamos
    // bc(n,k) = [n * (n-1) * ... * (n-k+1)] / [k * (k-1) * ... * 1]
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
