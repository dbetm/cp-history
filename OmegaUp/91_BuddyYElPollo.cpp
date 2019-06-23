#include <bits/stdc++.h>

using namespace std;
vector<long int> dd;

void generarDivisores(int n) {
    for (long int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(n/i == i) dd.push_back(i);
            else {
                dd.push_back(i);
                dd.push_back(n/i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long int n;
    scanf("%ld", &n);
    generarDivisores(n);
    sort(dd.begin(), dd.end());
    for (long int i = 0; i < (int)dd.size(); i++) {
        cout << dd[i] << " ";
    }
    cout << endl;
    return 0;
}
