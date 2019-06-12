#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, cont = 0;
    cin >> n;

    if(n & 1) n++;
    else n /= 2;
    cont++;

    if(n >= 100) {
        cont++;
        n /= 100;
    }
    else if(n >= 10 && n < 100) {
        n /= 10;
        cont++;
    }

    if(n % 3 == 0) {
        n--;
        cont++;
    }

    cout << n << " " << cont << endl;

    return 0;
}
