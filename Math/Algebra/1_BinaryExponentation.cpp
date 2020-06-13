#include <bits/stdc++.h>
/*
Since the number n has exactly log_2(n) +1 digits in base 2, we only need to
perform O(log(n)) multiplications, if we know the powers a^1, a^2, a^4, ...,a^[log_2(n)]
So we only need to know a fast way to compute those. Luckily this is very easy,
since an element in the sequence is just the square of the previous element.
3^1 = 3
3^2 = (3^1)^2 = 3^2 = 9
3^4 = (3^2)^4 = 9^2 = 81
3^8 = (3^4)^2 = 81^2 = 6561
*/
using namespace std;

long long binpow(long long a, long long n);

int main() {
    long long base, exponente;
    cout << "Base: ";
    cin >> base;
    cout << "Exponente: ";
    cin >> exponente;
    cout << binpow(base, exponente) << endl;
    cout << "Ha iterado: " << (int)log2(exponente) + 1 << " veces" << endl;
    return 0;
}

long long binpow(long long a, long long n) {
    long long res = 1;
    while(n > 0) { // va a iterar log_2(n) veces
        if(n & 1) {
            res = res * a; // caso impar
            cout << "Hey" << endl;
        }
        a = a * a;
        n >>= 1; // b = b >> 1, división sobre 2
        cout << n << endl;
    }
    return res;
}
